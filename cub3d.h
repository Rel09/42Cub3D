/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 03:53:53 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>;
# include "Libs/Libft/libft.h"
# include "Libs/MiniLibx/include/MLX42/MLX42.h"

# define PINK_TEXT	"\x1B[38;5;206m"
# define RED_TEXT	"\x1B[31m"
# define BLACK_BG	"\x1B[40m"
# define GREEN_BG	"\x1B[42m"
# define BLUE_BG	"\x1B[44m"
# define RESET		"\x1B[0m"

# define WIDTH 1000
# define HEIGHT 1000
# define GAME_NAME "🤡 BozoLand 🤡"

////////////////////////////
// 		  Structs	
////////////////////////////		Coords
typedef struct
{
	float x;
	float y;
}	s_coord;
///////////////////////////			RGB struct
typedef struct {
	int r;
	int g;
	int b;
}	s_RGB;
///////////////////////////			Game Data MLX Struct
typedef struct
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint8_t 	map_x;
	uint8_t 	map_y;
	uint8_t		**nmap;
	struct {//					Map File Data
		char *texture_file[4];
		char *rgb_color[2];
	}	s_mapfile;
}	s_gamedata;
///////////////////////////			Player Struct
typedef struct
{
	s_coord 	Coord;
	uint8_t 	fov;
	float 		angle;
	float 		movementSpeed;
	float 		rotationSpeed;
}	s_playerunit;
///////////////////////////			Textures Struct
typedef struct {
	mlx_texture_t	*textures[4];
	uint32_t		rgb[2];
}	s_texture;
///////////////////////////			Colors Struct
typedef struct
{
	uint32_t 	mn_wall;
	uint32_t 	mn_bckgrnd;
	uint32_t 	mn_player;
	uint32_t 	mn_fovline;
}	s_colors;
///////////////////////////			Raycasting Struct
typedef struct {
	int		w;
	int		h;
	
	float	anglerad;
	float	fovrad;
	float	camplane;
	float	rayangle;
	float	rayx;
	float	rayy;
	float	raycos;
	float	raysin;
	bool	wall;
	bool	w_isvertical;
	uint8_t	txt_i;
	int		w_height;
}	s_raycast;


///////////////////////////

////////////////////////////
// 		   Enums
////////////////////////////

////////////////////////////
// 		Data Functions	
////////////////////////////
s_playerunit	*unit();
s_gamedata		*game();
s_texture		*gettexture();
s_colors		*color();
////////////////////////////
// 		Game Functions	
////////////////////////////
void			gameloop();//
////////////////////////////
// 		   Tools
////////////////////////////

//		Parsing
bool			detail_parser();
bool			read_rgb_color();
bool			can_map_be_flooded();
bool			map_isbad(char *map);
int				get_map_row(char *map);
int 			get_map_height(char *map);
bool 			readfile(char *mapcontent);
bool			does_file_exist(char *file);
bool			readmap(char *mapcontent);
uint8_t 		**allocate_map(int x, int y);
void			convert_map(char *mapcontent);
bool			add_to_data(char *data, char *keyword);
void			display_map(uint8_t **map, int y, int x);
bool			is_file_format_supported(char *map, char *format);
void			parse_mapfile0(char *map, char *temp, int *index, int *count);
void			parse_mapfile1(char *map, char *temp, int *index, int *count);

//		Errors
bool			argc_isbad(int argv);
bool			readfile_error_0(void);
bool			readfile_error_1(char *value);
bool			readfile_error_2(int value);
bool			readfile_error_3(void);
bool			readfile_error_4(int count, char *temp);
bool			readfile_error_5(void);
bool			readfile_error_6(void);
bool			open_png_error_0(void);
bool			open_png_error_1(void);
bool			open_png_error_2(char *str);
bool			open_png_error_3(char *str);

//		Movement
bool			isKeyDown(int key);
void			movePlayer();

// 		Minimap
void    		drawminimap();
bool 			isvalidtile(s_coord coord);

//		Drawing
void 			raycasting();
void			drawplayer();
uint32_t 		rgba_to_pixels(int *a);
uint32_t		texture_to_pixel(mlx_texture_t* texture, int x, int y);
uint32_t		rgba_to_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

//		Maths
double 			degreetoradians(double degrees);
float 			get_distance(s_coord a, s_coord b);

//		Free
void 			free_map(uint8_t **array, int x);

//		Others
bool			ft_isspace(char c);
bool			ft_isnumeric(char *str);
uint8_t 		ft_iskeyword(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strtok(char *str, const char delim);
void			ft_charncat(char *dest, const char src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
void			ft_bzero2(void *s, size_t n, void *s1, size_t n1);

#endif
