/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 03:16:04 by dpotvin          ###   ########.fr       */
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

# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1200
# define GAME_NAME "🤡 Bozo - The comeback of the invisible enemy 🤡"

////////////////////////////
// 		  Structs	
////////////////////////////		Coords
typedef struct
{
	float x;
	float y;
}	s_coord;
///////////////////////////			Game Data MLX Struct
typedef struct
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	uint8_t 	map_x;
	uint8_t 	map_y;
	uint8_t		map[21][20];	// map**
	
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
	mlx_texture_t	*test;
}	s_texture;
///////////////////////////			Colors Struct
typedef struct
{
	uint32_t 	minimapwall;
	uint32_t 	minimapbackground;
	uint32_t 	minimapplayer;
	uint32_t 	minimapplayerangleline;
	uint32_t 	gamefloor;
	uint32_t 	gamewall;	// remove?
	uint32_t 	gameroof;
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
bool			map_isbad(char *map);

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

#endif
