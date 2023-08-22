/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:30:50 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 03:03:00 by dpotvin          ###   ########.fr       */
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

# define TILESIZE 1
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 1200
# define GAME_NAME "🤡 Bozo - The comeback of the invisible enemy 🤡"

////////////////////////////
// 		  Structs	
////////////////////////////
typedef struct {//					Coords
	float x;
	float y;
}	s_coord;

typedef struct {//					Game Data MLX Struct
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	uint8_t 	map_x;
	uint8_t 	map_y;
	uint8_t		map[21][20];	// map**
	
}	s_gamedata;

typedef struct {//					Player Struct
	s_coord 	Coord;
	uint8_t 	fov;
	float 		angle;
	float 		movementSpeed;
	float 		rotationSpeed;
}	s_playerunit;

typedef struct {//					Textures Struct
	mlx_texture_t	*test;
}	s_texture;

typedef struct {//					Colors Struct
	uint32_t 	minimapwall;
	uint32_t 	minimapbackground;
	uint32_t 	minimapplayer;
	uint32_t 	minimapplayerangleline;
	uint32_t 	gamefloor;
	uint32_t 	gamewall;	// remove?
	uint32_t 	gameroof;
}	s_colors;
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
bool			map_isbad();
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
