/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 04:30:10 by dpotvin          ###   ########.fr       */
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

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 1000
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
	uint32_t 	minimapwall;
	uint32_t 	minimapbackground;
	uint32_t 	minimapplayer;
	uint32_t 	minimapplayerangleline;
}	s_colors;
///////////////////////////

////////////////////////////
// 		   Enums
////////////////////////////

////////////////////////////
// 		Data Functions	
////////////////////////////
s_playerunit	*getplayerunit();
s_gamedata		*getgamedata();
s_texture		*gettexture();
s_colors		*getcolor();
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

//		Errors
bool			argc_isbad(int argv);

//		Movement
bool			isKeyDown(int key);
void			movePlayer();

// 		Minimap
void    		drawMiniMap();
bool 			isValidTile(s_coord coord);

//		Drawing
void 			raycasting();
void			drawPlayer();
uint32_t		texture_to_pixel(mlx_texture_t* texture, int x, int y);
uint32_t		rgba_to_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

//		Maths
double 			degreesToRadians(double degrees);
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

#endif
