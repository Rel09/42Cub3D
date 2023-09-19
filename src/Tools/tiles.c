/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:27:02 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/18 18:15:16 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	isvalidtile(t_coord coord)
{
	int	mapx;
	int	mapy;

	mapx = coord.x;
	mapy = coord.y;
	if (mapx >= 0 && mapx < game()->map_x && mapy >= 0
		&& mapy < game()->map_y)
	{
		if (game()->nmap[mapy][mapx] == 0)
			return (true);
	}
	return (false);
}

void	drawsquare(uint16_t x, uint16_t y, uint16_t sizex, uint16_t sizey)
{
	uint16_t	num[4];

	num[0] = x + sizex;
	num[1] = y + sizey;
	if (num[0] > WIDTH || num[1] > HEIGHT)
		return ;
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

void	setplayerangle(uint8_t i)
{
	if (i == 2)
		unit()->angle = 270;
	else if (i == 3)
		unit()->angle = 90;
	else if (i == 4)
		unit()->angle = 180;
	else
		unit()->angle = 0;
}

void	save_current_map(char *mapcontent)
{
	game()->map_x = get_map_row(mapcontent) + 2;
	game()->map_y = get_map_height(mapcontent) + 2;
	(game()->nmap) = allocate_map(game()->map_y, game()->map_x);
	if (!game()->nmap)
		return ;
	convert_map(mapcontent);
}

bool	replacetabswithspaces(char *input)
{
	char	*output;
	int		a[3];
	
	output = malloc(strlen(input) * TABSIZE + 1);
	if (!output)
		return (false);
	ft_bzero(a, sizeof (a));
	while (input[a[1]])
	{
		if (input[a[1]] == '\t')
		{
			a[2] = -1;
			while (++a[2] < TABSIZE)
				output[a[0]++] = ' ';
		}
		else
			output[a[0]++] = input[a[1]];
		a[1]++;
	}
	output[a[0]] = 0;
	save_current_map(output);
	free(output);
	return (true);
}
