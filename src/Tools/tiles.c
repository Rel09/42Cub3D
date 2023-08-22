/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:27:02 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/21 23:51:26 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Return true if Tile is valid
bool isValidTile(s_coord coord)
{
	int mapX = coord.x;
    int mapY = coord.y;

    if (mapX >= 0 && mapX < getgamedata()->map_x && mapY >= 0 && mapY < getgamedata()->map_y)
    {
        if (getgamedata()->map[mapX][mapY] == 0)
            return true;
    }
    return false;
}
