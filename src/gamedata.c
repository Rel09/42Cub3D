/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:26:48 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 21:52:56 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Store All the GG Stuff
static void		*gamedata(uint8_t flag)
{
	static s_gamedata	data;
	static s_playerunit	player;
	static s_colors		color;
	static s_texture	texture;

	if (flag == 0)		// 0 GAME
		return (void *)&data;
	else if (flag == 1)	// 1 PLAYER
		return (void *)&player;
	else if (flag == 2)	// 2 COLOR
		return (void *)&color;
	else if (flag == 3)	// 3 TEXTURE
		return (void *)&texture;
	return (0);
}

// Helpers Functions
s_gamedata		*getgamedata()
{
	static bool	init;
	s_gamedata	*T;

	if (!init)
	{
		T = ((s_gamedata *)gamedata(0));
		
		// Init the MLX
		T->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME, true);
		if (!T->mlx)
		{
			printf("Couldnt Init MLX\n");
			exit(1);
		}
			
		// Init the IMG
		T->img = mlx_new_image(T->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!T->img)
			{
			printf("Couldnt Init MLX->IMG\n");
			exit(1);
		}
		
		// Init the Window
		mlx_image_to_window(T->mlx, T->img, 0, 0);
		
		// Temp Map
		T->map_x = 21;
		T->map_y = 20;
		uint8_t copypastemap[20][21] = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		};
		for (int i = 0; i < T->map_y; i++) {
			for (int j = 0; j < T->map_x; j++) {
				T->map[j][i] = copypastemap[i][j];
			}
		}
		
		init = true;
	}
	return ((s_gamedata *)gamedata(0));
}
s_playerunit	*getplayerunit()
{
	static bool		init;
	s_playerunit	*T;
	
	if (!init)
	{
		T = ((s_playerunit *)gamedata(1));
		T->fov = 90;
		T->angle = 270;
		T->rotationSpeed = 200.0;
		T->Coord.x = getgamedata()->map_x / 2;
		T->Coord.y = getgamedata()->map_y / 2;
		init = true;
	}
	return ((s_playerunit *)gamedata(1));
}
s_colors		*getcolor()
{
	static bool	init;
	s_colors	*T;

	if (!init)
	{
		T = ((s_colors *)gamedata(2));
		T->gamewall = rgba_to_pixel(255, 120, 0, 255);
		T->gameroof = rgba_to_pixel(153, 204, 255, 255);
		T->gamefloor = rgba_to_pixel(0, 0, 0, 255);
		T->minimapwall = rgba_to_pixel(39, 245, 148, 255);
		T->minimapplayer = rgba_to_pixel(0, 255, 0, 255);
		T->minimapbackground = rgba_to_pixel(0, 0, 0, 255);
		T->minimapplayerangleline = rgba_to_pixel(255, 255, 255, 255);
		init = true;
	}
	return ((s_colors *)gamedata(2));
}
s_texture		*gettexture()
{
	static s_texture	*T;
	static bool			init;

	if (!init)
	{
		T = ((s_texture *)gamedata(3));
		T->test = mlx_load_png("./src/Textures/dolorama.png");
		init = true;
	}
	
	return (((s_texture *)gamedata(3)));
}
