/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:26:48 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 05:02:46 by dpotvin          ###   ########.fr       */
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

	if (flag == 0)
		return (void *)&data;
	else if (flag == 1)
		return (void *)&player;
	else if (flag == 2)
		return (void *)&color;
	else if (flag == 3)
		return (void *)&texture;
	return (0);
}

// Helpers Functions
s_gamedata	*getgamedata()
{
	static bool	init;
	s_gamedata	*T;
	if (!init)
	{
		T = ((s_gamedata *)gamedata(0));
		T->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME, true);
		if (!T->mlx)
		{
			printf("Couldnt Init MLX\n");
			exit(1);
		}
		T->img = mlx_new_image(T->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!T->img)
			{
			printf("Couldnt Init MLX->IMG\n");
			exit(1);
		}
		mlx_image_to_window(T->mlx, T->img, 0, 0);
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
		init = true;
	}
	return ((s_playerunit *)gamedata(1));
}
s_colors	*getcolor()
{
	static bool	init;
	s_colors	*T;

	if (!init)
	{
		T = ((s_colors *)gamedata(2));
		T->minimapwall = rgba_to_pixel(128, 128, 128, 255);
		T->minimapplayer = rgba_to_pixel(0, 255, 0, 255);
		T->minimapbackground = rgba_to_pixel(0, 0, 0, 255);
		T->minimapplayerangleline = rgba_to_pixel(255, 255, 255, 255);
		init = true;
	}
	return ((s_colors *)gamedata(2));
}
s_texture	*gettexture()
{
	return (((s_texture *)gamedata(3)));
}
