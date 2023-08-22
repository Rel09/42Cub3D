CC = gcc
RM = rm -f
NAME = cub3d
FLAGS = -Wall -Werror -Wextra -w
CFLAGS = -I /include -lglfw -pthread -L "/Users/$(USER)/.brew/opt/glfw/lib/"

LIBFT = Libs/Libft/Include/libft.a
MINILIBX = Libs/MiniLibx/build/libmlx42.a

FILES = cub3d \
		src/gamedata \
		src/gameloop \
		src/Tools/draw \
		src/Tools/math \
		src/Tools/tiles \
		src/Tools/movement \
		src/Tools/rgbatopixel \
		src/Parsing/readfile \
		src/Errors/init

CYAN="\033[1;36m"
GREEN="\033[1;32m"
ENDCOLOR="\033[0m"
CLEANING := $(GREEN)[+] [Cub3D] Cleaning Completed$(ENDCOLOR)
SUCCESS := $(GREEN)[+] [Cub3D] Successfully Compiled!$(ENDCOLOR)

OBJS_DIR = ./obj/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: lib makedir $(NAME)
	@echo $(SUCCESS)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@${CC}  ${FLAGS} ${OBJS} ${LIBFT} ${MINILIBX} ${CFLAGS} -o ${NAME}
	@echo $(CYAN)[-] [Cub3D] Compiling: $@$(ENDCOLOR)

lib:
	@make -C Libs/Libft
	@cmake ./Libs/MiniLibx/ -B ./Libs/MiniLibx/build && make -C ./Libs/MiniLibx/build -j4
	@echo $(GREEN)[+] [MiniLibx] Successfully Compiled!$(ENDCOLOR)

makedir:
	@mkdir -p $(OBJS_DIR)
	@mkdir -p ./obj/src/
	@mkdir -p ./obj/src/Tools
	@mkdir -p ./obj/src/Parsing
	@mkdir -p ./obj/src/Errors

run: all
	@./$(NAME)

$(OBJS_DIR)%.o: %.c
	@${CC} ${FLAGS} ${CFLAGS} -c $< -o $@
	@echo $(CYAN)[-] [Cub3D] Compiling: $<$(ENDCOLOR)

clean:
	@make clean -s -C libs/Libft
	@cd Libs/MiniLibx && ${RM} -r build
	@echo $(GREEN)[+] [MiniLibx] Cleaning Completed$(ENDCOLOR)
	@${RM} ${OBJS}
	@${RM} -r ${OBJS_DIR}
	@echo $(CLEANING)

fclean: 
	@make fclean -s -C libs/Libft
	@cd Libs/MiniLibx && ${RM} -r build
	@echo $(GREEN)[+] [MiniLibx] Cleaning Completed$(ENDCOLOR)
	@${RM} ${OBJS}
	@${RM} -r ${OBJS_DIR}
	@${RM} ${NAME}
	@echo $(CLEANING)


re: fclean all

leak: all
	@valgrind --leak-check=full --track-fds=no --show-leak-kinds=all --trace-children=no ./$(NAME)
	@${RM} -r cub3d.dSYM

.PHONY: all clean fclean re lib run leak
