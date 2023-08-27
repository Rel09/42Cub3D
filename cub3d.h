/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/27 00:49:08 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
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
# define TABSIZE 4
# define GAME_NAME "🤡 BozoLand 🤡"
////////////////////////////
// 		  Structs	
////////////////////////////		Coords
typedef struct coord
{
	float	x;
	float	y;
}	t_coord;
///////////////////////////			RGB struct
typedef struct rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;
///////////////////////////			Game Data MLX Struct
typedef struct gamedata
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint8_t		map_x;
	uint8_t		map_y;
	uint8_t		**nmap;
	struct
	{
		char	*texture_file[4];
		char	*rgb_color[2];
	}	s_mapfile;
}	t_gamedata;
///////////////////////////			Player Struct
typedef struct playerunit
{
	t_coord		coord;
	uint8_t		fov;
	float		angle;
	float		movementspeed;
	float		rotationspeed;
}	t_playerunit;
///////////////////////////			Textures Struct
typedef struct texture
{
	mlx_texture_t	*textures[4];
	uint32_t		rgb[2];
}	t_texture;
///////////////////////////			Colors Struct
typedef struct colors
{
	uint32_t	mn_wall;
	uint32_t	mn_bckgrnd;
	uint32_t	mn_player;
	uint32_t	mn_fovline;
}	t_colors;
///////////////////////////			Raycasting Struct
typedef struct raycast
{
	int		w;
	int		h;
	float	rad;
	float	fovrad;
	float	camplane;
	float	angle;
	float	x;
	float	y;
	float	cos;
	float	sin;
	float	txtx;
	float	txty;
	bool	wall;
	bool	wver;
	uint8_t	txt_i;
	int		wh;
}	t_raycast;
////////////////////////////
// 		Data Functions	
////////////////////////////
t_playerunit	*unit(void);
t_gamedata		*game(void);
t_texture		*gettexture(void);
t_colors		*color(void);
////////////////////////////
// 		Game Functions	
////////////////////////////
void			gameloop(void);//
////////////////////////////
// 		   Tools
////////////////////////////
//		Parsing
bool			detail_parser(void);
bool			read_rgb_color(void);
bool			can_map_be_flooded(void);
bool			map_isbad(char *map);
int				get_map_row(char *map);
int				get_map_height(char *map);
bool			readfile(char *mapcontent);
bool			does_file_exist(char *file);
bool			readmap(char *mapcontent);
void			setplayerangle(uint8_t i);
uint8_t			**allocate_map(int x, int y);
void			convert_map(char *mapcontent);
bool			replacetabswithspaces(char *input);
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
void			free_everything(void);
//		Movement
bool			iskeydown(int key);
void			moveplayer(void);
// 		Minimap
bool			isvalidtile(t_coord coord);
//		Drawing
void			raycasting(void);
void			drawplayer(void);
uint32_t		rgba_to_pixels(int *a);
uint32_t		texture_to_pixel(mlx_texture_t *texture, int x, int y);
uint32_t		rgba_to_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
void			drawsquare(uint16_t x, uint16_t y,
					uint16_t sizex, uint16_t sizey);
//		Maths
double			degreetoradians(double degrees);
float			get_distance(t_coord a, t_coord b);
//		Free
void			free_map(uint8_t **array, int x);
//		Others
bool			ft_isspace(char c);
bool			ft_isnumeric(char *str);
uint8_t			ft_iskeyword(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strtok(char *str, const char delim);
void			ft_charncat(char *dest, const char src);
char			*ft_strncat(char *s1, const char *s2, size_t n);
void			ft_bzero2(void *s, size_t n, void *s1, size_t n1);

#endif
