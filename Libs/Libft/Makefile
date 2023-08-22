# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 03:25:04 by dpotvin           #+#    #+#              #
#    Updated: 2023/06/28 21:29:30 by dpotvin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
AR= ar rcs
RM= rm -f
NAME= libft.a
FLAGS= -Wall -Wextra -Werror

CYAN="\033[1;36m"
GREEN="\033[1;32m"
ENDCOLOR="\033[0m"
CLEANING := $(GREEN)[+] [Libft] Cleaning Completed$(ENDCOLOR)
SUCCESS := $(GREEN)[+] [Libft] Successfully Compiled!$(ENDCOLOR)

FILES :=	ft_itoa \
			ft_atoi \
			ft_split \
			ft_bzero \
			ft_memset \
			ft_strchr \
			ft_memcpy \
			ft_calloc \
			ft_memchr \
			ft_substr \
			ft_strdup \
			ft_memcmp \
			ft_strlen \
			ft_lstmap \
			ft_lstnew \
			ft_strlcpy \
			ft_strlcat \
			ft_memmove \
			ft_strrchr \
			ft_strnstr \
			ft_strncmp \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_lstsize \
			ft_lstlast \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_strjoin \
			ft_strtrim \
			ft_lstiter \
			ft_strmapi \
	  		ft_lstclear \
			ft_striteri \
			ft_putstr_fd \
			ft_putnbr_fd \
			ft_lstdelone \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_lstadd_back \
			ft_lstadd_front 

OBJS_DIR = ./obj/
SRCS_DIR = ./src/
INCL_DIR = ./include/

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
FNAME = $(addprefix $(INCL_DIR), $(NAME))


all: mkdir $(FNAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	@$(CC) $(FLAGS) -c -o $@ $<
	@echo $(CYAN)[-] [Libft] Compiling: $@$(ENDCOLOR)

$(OBJS): | $(OBJS_DIR)

$(FNAME): $(OBJS)
	@$(AR) $@ $^
	@echo $(SUCCESS)

mkdir:
	$(shell mkdir -p $(OBJS_DIR))
	$(shell mkdir -p $(INCL_DIR))

clean:
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJS_DIR)
	@echo $(CLEANING)

fclean: clean
	@$(RM) $(FNAME)
	@$(RM) -r $(INCL_DIR)

re: fclean all
