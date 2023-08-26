/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:26:48 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 03:01:24 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Store All the GG Stuff
static void	*gamedata(uint8_t flag)
{
	static s_gamedata	data;
	static s_playerunit	player;
	static s_colors		color;
	static s_texture	texture;

	if (flag == 0)
		return ((void *)&data);
	else if (flag == 1)
		return ((void *)&player);
	else if (flag == 2)
		return ((void *)&color);
	else if (flag == 3)
		return ((void *)&texture);
	return (0);
}

// Helpers Functions
s_gamedata	*game(void)
{
	static bool	init;
	s_gamedata	*t;

	if (!init)
	{
		t = ((s_gamedata *)gamedata(0));
		t->mlx = mlx_init(WIDTH, HEIGHT, GAME_NAME, true);
		if (!t->mlx)
		{
			printf("Couldnt Init MLX\n");
			exit(1);
		}
		t->img = mlx_new_image(t->mlx, WIDTH, HEIGHT);
		if (!t->img)
		{
			printf("Couldnt Init MLX->IMG\n");
			exit(1);
		}
		mlx_image_to_window(t->mlx, t->img, 0, 0);
		init = true;
	}
	return ((s_gamedata *)gamedata(0));
}

s_playerunit	*unit(void)
{
	static bool		init;
	s_playerunit	*t;

	if (!init)
	{
		t = ((s_playerunit *)gamedata(1));
		t->fov = 90;
		t->angle = 270;
		t->rotationSpeed = 200.0;
		init = true;
	}
	return ((s_playerunit *)gamedata(1));
}

s_colors	*color(void)
{
	static bool	init;
	s_colors	*t;

	if (!init)
	{
		t = ((s_colors *)gamedata(2));
		t->mn_wall = rgba_to_pixel(128, 128, 128, 255);
		t->mn_player = rgba_to_pixel(0, 255, 0, 255);
		t->mn_bckgrnd = rgba_to_pixel(0, 0, 0, 255);
		t->mn_fovline = rgba_to_pixel(255, 255, 255, 255);
		init = true;
	}
	return ((s_colors *)gamedata(2));
}

s_texture	*gettexture(void)
{
	return (((s_texture *)gamedata(3)));
}
