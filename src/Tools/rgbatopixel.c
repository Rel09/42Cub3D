/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbatopixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:11:26 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/27 01:03:31 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

uint32_t	rgba_to_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

// dumb error from norminette -.-
uint32_t	rgba_to_pixels(int *a)
{
	return (a[0] << 24 | a[1] << 16 | a[2] << 8 | 255);
}

// Retrieve the Pixel color of a texture X Y
// Note that you could change texture->bytes_per_pixel by 4. 
// its always 4. R G B A = 4
uint32_t	texture_to_pixel(mlx_texture_t *texture, int x, int y)
{
	uint32_t	i;
	uint8_t		*pixel;

	i = (y * texture->width + x) * texture->bytes_per_pixel;
	pixel = &texture->pixels[i];
	return (rgba_to_pixel(pixel[0], pixel[1], pixel[2], pixel[3]));
}
