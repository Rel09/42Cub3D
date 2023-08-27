/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:26:59 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/27 00:51:48 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	iskeydown(int key)
{
	return (mlx_is_key_down(game()->mlx, key));
}

static void	move(float dx, float dy, float movs, bool a)
{
	float	x;
	float	y;

	if (a)
	{
		x = unit()->coord.x + dx * movs;
		y = unit()->coord.y + dy * movs;
	}
	else
	{
		x = unit()->coord.x - dx * movs;
		y = unit()->coord.y - dy * movs;
	}
	if (isvalidtile((t_coord){x, y}))
	{
		unit()->coord.x = x;
		unit()->coord.y = y;
	}
}

static void	strafe(float anglerad, float delta, bool a)
{
	float	strafedir;
	float	x;
	float	y;

	if (a)
		strafedir = anglerad - (M_PI / 2.0);
	else
		strafedir = anglerad + (M_PI / 2.0);
	x = unit()->coord.x + cos(strafedir) * 5.0 * delta;
	y = unit()->coord.y + sin(strafedir) * 5.0 * delta;
	if (isvalidtile((t_coord){x, y}))
	{
		unit()->coord.x = x;
		unit()->coord.y = y;
	}
}

static void	rotate(float delta, bool a)
{
	if (a)
		unit()->angle -= unit()->rotationspeed * delta;
	else
		unit()->angle += unit()->rotationspeed * delta;
	(unit()->angle) = fmodf(unit()->angle, 360.0f);
}

void	moveplayer(void)
{
	float	a[5];

	a[0] = game()->mlx->delta_time;
	a[1] = unit()->angle * (M_PI / 180.0);
	a[2] = 5.0 * a[0];
	a[3] = cos(a[1]);
	a[4] = sin(a[1]);
	if (iskeydown(MLX_KEY_ESCAPE))
	{
		free_everything();
		exit(0);
	}
	if (iskeydown(MLX_KEY_W))
		move(a[3], a[4], a[2], true);
	else if (iskeydown(MLX_KEY_S))
		move(a[3], a[4], a[2], false);
	if (iskeydown(MLX_KEY_D))
		strafe(a[1], a[0], true);
	else if (iskeydown(MLX_KEY_A))
		strafe(a[1], a[0], false);
	if (iskeydown(MLX_KEY_RIGHT))
		rotate(a[0], true);
	else if (iskeydown(MLX_KEY_LEFT))
		rotate(a[0], false);
}
