/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:33:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 03:55:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	drawSquare(uint16_t x, uint16_t y, uint16_t tilesize_x, uint16_t tilesize_y)
{
    uint16_t	num[4];

	num[0] = x + tilesize_x;
	num[1] = y + tilesize_y;

    if (num[0] > WIDTH || num[1] > HEIGHT)
        return;
	num[2] = x;
    while (num[2] < num[0])
	{
        while (num[3] < num[1])
		{
            mlx_put_pixel(game()->img, num[2], num[3], color()->mn_wall);
			num[3]++;
        }
		num[3] = y;
		num[2]++;
    }
}

// Return the angle texture
static uint8_t get_texture(bool vertical, float raycos, float raysin)
{
	int	textureIndex;

	if (vertical)
	{
		if (raycos > 0)
			textureIndex = 2;
		else
			textureIndex = 3;
	}
	else
	{
		if (raysin > 0)
			textureIndex = 1;
		else
			textureIndex = 0;
	}
	return (textureIndex);
}

// Make sure everyting is printing the right way ( from left to right / right to left )
static float	get_texture_x(bool vertical, float rayY, float rayX, uint8_t txtindex)
{
	float	textureX;
	
	if (vertical)
	{
		if (txtindex == 0)
		{
			textureX = (rayY - floor(rayY)) * gettexture()->textures[txtindex]->width;
			textureX = gettexture()->textures[txtindex]->width - textureX - 1.0;
		}
		else if (txtindex == 2)
			textureX = (1.0 - (rayY - floor(rayY))) * gettexture()->textures[txtindex]->width;
		else
			textureX = (rayY - floor(rayY)) * gettexture()->textures[txtindex]->width;
	}
	else
	{
		if (txtindex == 0 )
		{
			textureX = (rayX - floor(rayX)) * gettexture()->textures[txtindex]->width;
			textureX = gettexture()->textures[txtindex]->width - textureX - 1.0;
		}
		else
			textureX = (rayX - floor(rayX)) * gettexture()->textures[txtindex]->width;
	}
	return (textureX);
}


static s_raycast	get_raycast(s_raycast *ray, int width, float camplane, float anglerad)
{
	ft_bzero(ray, sizeof(s_raycast));
	ray->rayangle = atan2(WIDTH / 2.0f - width + 0.5, camplane) + anglerad;
	ray->rayx = unit()->Coord.x;
	ray->rayy = unit()->Coord.y;
	ray->raycos = cos(ray->rayangle) / 300;
	ray->raysin = sin(ray->rayangle) / 300;
	ray->wall = false;
	ray->w_isvertical = true;
	while (!ray->wall)
	{
		ray->rayx += ray->raycos;
		ray->rayy += ray->raysin;
		ray->wall = game()->nmap[(int)(ray->rayy)][(int)(ray->rayx)] == 1;
		if (ray->wall)
			ray->w_isvertical = game()->nmap[(int)(ray->rayy)][(int)(ray->rayx - ray->raycos)] != 1;
	}
	ray->txt_i = get_texture(ray->w_isvertical, ray->raycos, ray->raysin);
	ray->w_height = (camplane / (get_distance(unit()->Coord, (s_coord){ray->rayx, ray->rayy}) * cos(ray->rayangle - anglerad)));
}

void	raycasting()
{
    s_raycast	ray;
	int	w;
	int h;
	float angleRad = degreetoradians(unit()->angle);
    float halfFovAngleRad = degreetoradians(unit()->fov / 2.0f);
    float camplane = (WIDTH / 2.0f) / tan(halfFovAngleRad);
	w = 0;
    while (w < WIDTH)
    {
		get_raycast(&ray, w, camplane, angleRad);
		h = 0;
		while (h < HEIGHT)
		{
			float textureY = (h - (HEIGHT - ray.w_height) / 2) / (float)ray.w_height * gettexture()->textures[0]->height;
			if (h >= (HEIGHT - ray.w_height) / 2 && h < (HEIGHT + ray.w_height) / 2)
			{
				float textureX = get_texture_x(ray.w_isvertical, ray.rayy, ray.rayx, ray.txt_i);
				mlx_put_pixel(game()->img, w, h, texture_to_pixel(gettexture()->textures[ray.txt_i], textureX, textureY));
			}
			else if (h < (HEIGHT - ray.w_height) / 2)
				mlx_put_pixel(game()->img, w, h, gettexture()->rgb[1]);
			else
				mlx_put_pixel(game()->img, w, h, gettexture()->rgb[0]);
			h++;
		}
		w++;
    }
}


