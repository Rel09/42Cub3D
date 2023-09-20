/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:46:34 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/19 20:04:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	drawminimapbackground(void)
{
	int	num[6];

	num[2] = 0;
	num[0] = WIDTH / (4 * game()->map_x);
	num[1] = HEIGHT / (4 * game()->map_y);
	while (num[2] < game()->map_y)
	{
		num[3] = 0;
		while (num[3] < game()->map_x)
		{
			if (game()->nmap[num[2]][num[3]] != 1)
			{
				num[3]++;
				continue ;
			}
			num[4] = num[3] * num[0];
			num[5] = num[2] * num[1];
			drawsquare(num[4], num[5], num[0], num[1]);
			num[3]++;
		}
		num[2]++;
	}
}

static void	drawline_onminimap(float x1, float y1, float x2, float y2)
{
	int		i;
	float	n[7];

	n[0] = x2 - x1;
	n[1] = y2 - y1;
	n[2] = fmaxf(fabsf(n[0]), fabsf(n[1]));
	n[3] = n[0] / n[2];
	n[4] = n[1] / n[2];
	n[5] = x1;
	n[6] = y1;
	i = 0;
	while (i < n[2])
	{
		if (n[5] >= 0 && n[5] < WIDTH && n[6] >= 0
			&& n[6] < HEIGHT)
			mlx_put_pixel(game()->img, n[5], n[6],
				color()->mn_fovline);
		n[5] += n[3];
		n[6] += n[4];
		i++;
	}
}

static void	drawline(void)
{
	float	num[8];

	num[0] = 10.0f;
	num[1] = degreetoradians(unit()->angle);
	num[2] = (WIDTH) / (4 * game()->map_x);
	num[3] = (HEIGHT) / (4 * game()->map_y);
	num[4] = unit()->coord.x * num[2];
	num[5] = unit()->coord.y * num[3];
	num[6] = num[4] + num[0] * cos(num[1]);
	num[7] = num[5] + num[0] * sin(num[1]);
	drawline_onminimap(num[4], num[5], num[6], num[7]);
}

void	draw_minimap(void)
{
	int	num[6];

	num[0] = WIDTH / (4 * game()->map_x);
	num[1] = HEIGHT / (4 * game()->map_y);
	num[2] = 0;
	while (num[2] < (game()->map_x * num[0]))
	{
		num[3] = 0;
		while (num[3] < (game()->map_y * num[1]))
			mlx_put_pixel(game()->img, num[2], num[3]++,
				color()->mn_bckgrnd);
		num[2]++;
	}
	drawminimapbackground();
}

void	drawplayer(void)
{
	int		a[2];
	float	b[4];

	b[0] = (unit()->coord.x) * ((WIDTH) / (4 * game()->map_x));
	b[1] = (unit()->coord.y) * ((HEIGHT) / (4 * game()->map_y));
	a[0] = -5;
	while (a[0] <= 5)
	{
		a[1] = -5;
		while (a[1] <= 5)
		{
			if (sqrt(a[1] * a[1] + a[0] * a[0]) <= 5)
			{
				b[2] = b[0] + a[0];
				b[3] = b[1] + a[1];
				if (b[2] >= 0 && b[2] < WIDTH && b[3] >= 0 && b[3] < HEIGHT)
					mlx_put_pixel(game()->img, b[2], b[3], color()->mn_player);
			}
			a[1]++;
		}
		a[0]++;
	}
	drawline();
}
