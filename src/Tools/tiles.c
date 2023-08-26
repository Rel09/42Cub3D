/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:27:02 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 02:57:13 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Return true if Tile is valid
bool	isvalidtile(s_coord coord)
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
