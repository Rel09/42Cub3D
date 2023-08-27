/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:33:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 22:57:30 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Return the angle texture
static uint8_t	get_texture(bool vertical, float cos, float sin)
{
	int	texture_index;

	if (vertical)
	{
		if (cos > 0)
			texture_index = 2;
		else
			texture_index = 3;
	}
	else
	{
		if (sin > 0)
			texture_index = 1;
		else
			texture_index = 0;
	}
	return (texture_index);
}

static float	get_texture_x(bool ver, float rayY, float rayX, uint8_t i)
{
	float	x;

	if (ver)
	{
		if (i == 0)
		{
			x = (rayY - floor(rayY)) * gettexture()->textures[i]->width;
			x = gettexture()->textures[i]->width - x - 1.0;
		}
		else if (i == 2)
			x = (1.0 - (rayY - floor(rayY))) * gettexture()->textures[i]->width;
		else
			x = (rayY - floor(rayY)) * gettexture()->textures[i]->width;
	}
	else
	{
		if (i == 0)
		{
			x = (rayX - floor(rayX)) * gettexture()->textures[i]->width;
			x = gettexture()->textures[i]->width - x - 1.0;
		}
		else
			x = (rayX - floor(rayX)) * gettexture()->textures[i]->width;
	}
	return (x);
}

static t_raycast	get_raycast(t_raycast *ray, int w, float c, float rad)
{
	t_coord	t;

	ray->angle = atan2(WIDTH / 2.0f - w + 0.5, c) + rad;
	ray->x = unit()->coord.x;
	ray->y = unit()->coord.y;
	ray->cos = cos(ray->angle) / 300;
	ray->sin = sin(ray->angle) / 300;
	ray->wall = false;
	ray->wver = true;
	while (!ray->wall)
	{
		ray->x += ray->cos;
		ray->y += ray->sin;
		ray->wall = game()->nmap[(int)(ray->y)][(int)(ray->x)] == 1;
		if (ray->wall)
			ray->wver = game()->nmap[(int)
				(ray->y)][(int)(ray->x - ray->cos)] != 1;
	}
	ray->txt_i = get_texture(ray->wver, ray->cos, ray->sin);
	t = (t_coord){ray->x, ray->y};
	ray->wh = (c / (get_distance(unit()->coord, t) * cos(ray->angle - rad)));
}

static void	init_raycast(t_raycast *ray)
{
	ray->w = 0;
	ray->rad = degreetoradians(unit()->angle);
	ray->fovrad = degreetoradians(unit()->fov / 2.0f);
	ray->camplane = (WIDTH / 2.0f) / tan(ray->fovrad);
}

void	raycasting(void)
{
	t_raycast	ray;

	init_raycast(&ray);
	while (ray.w < WIDTH)
	{
		get_raycast(&ray, ray.w, ray.camplane, ray.rad);
		ray.h = 0;
		while (ray.h < HEIGHT)
		{
			ray.txty = (ray.h - (HEIGHT - ray.wh) / 2) / (float)ray.wh
				* gettexture()->textures[0]->height;
			if (ray.h >= (HEIGHT - ray.wh) / 2 && ray.h < (HEIGHT + ray.wh) / 2)
			{
				ray.txtx = get_texture_x(ray.wver, ray.y, ray.x, ray.txt_i);
				mlx_put_pixel(game()->img, ray.w, ray.h, texture_to_pixel
					(gettexture()->textures[ray.txt_i], ray.txtx, ray.txty));
			}
			else if (ray.h < (HEIGHT - ray.wh) / 2)
				mlx_put_pixel(game()->img, ray.w, ray.h, gettexture()->rgb[1]);
			else
				mlx_put_pixel(game()->img, ray.w, ray.h, gettexture()->rgb[0]);
			ray.h++;
		}
		ray.w++;
	}
}
