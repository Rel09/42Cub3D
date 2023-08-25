/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:20:27 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 05:06:43 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// FloodFill Backend
static void	floodFill(uint8_t **arr, uint8_t nval, int rows, int cols, int x, int y)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || arr[x][y] == nval || arr[x][y] == 1)
        return;
	arr[x][y] = nval;
	floodFill(arr, nval, rows, cols, x + 1, y);
	floodFill(arr, nval, rows, cols, x - 1, y);
	floodFill(arr, nval, rows, cols, x, y + 1);
	floodFill(arr, nval, rows, cols, x, y - 1);
}

// Get rid of all the non reacheable area
static void	illuminatifloodFill()
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < getgamedata()->map_y) {
		while (j < getgamedata()->map_x){
			if (!(getgamedata()->nmap[i][j] == 7))
				getgamedata()->nmap[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
}

// Check if we have only one spawn point and if we have no shit in map
bool	detail_parser()
{
	uint8_t	**map;
	int		i[2];
	int		stuff[2];
	
	ft_bzero(i, sizeof(i));
	ft_bzero(stuff, sizeof(stuff));
	map = getgamedata()->nmap;
	while (i[0] < getgamedata()->map_y)
	{
		while (i[1] < getgamedata()->map_x)
		{
			if (getgamedata()->nmap[i[0]][i[1]] >= 2 && getgamedata()->nmap[i[0]][i[1]] <= 5)
			{
				getplayerunit()->Coord = (s_coord){i[1], i[0]};
				getgamedata()->nmap[i[0]][i[1]] = 0;
				stuff[0]++;
			}
			else if (getgamedata()->nmap[i[0]][i[1]] == 8)
				stuff[1]++;
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	return (stuff[0] == 1 && stuff[1] == 0);
}

// Do the Flood Fill Test
bool	can_map_be_flooded()
{
	floodFill(getgamedata()->nmap, 7, getgamedata()->map_y, getgamedata()->map_x, getplayerunit()->Coord.y, getplayerunit()->Coord.x);
	if (getgamedata()->nmap[0][0] == 7)
	{
		display_map(getgamedata()->nmap, getgamedata()->map_y, getgamedata()->map_x);
		printf("[-] Error\n[-] Map Failed FloodFill Test\n");
		return (true);
	}
	floodFill(getgamedata()->nmap, 0, getgamedata()->map_y, getgamedata()->map_x, getplayerunit()->Coord.y, getplayerunit()->Coord.x);
	display_map(getgamedata()->nmap, getgamedata()->map_y, getgamedata()->map_x);
	floodFill(getgamedata()->nmap, 7, getgamedata()->map_y, getgamedata()->map_x, getplayerunit()->Coord.y, getplayerunit()->Coord.x);
	illuminatifloodFill(getgamedata()->nmap, getgamedata()->map_y, getgamedata()->map_x, 0, 0);
	floodFill(getgamedata()->nmap, 0, getgamedata()->map_y, getgamedata()->map_x, getplayerunit()->Coord.y, getplayerunit()->Coord.x);
	return (false);
}

// I dont think you need comment on this one
void free_map(uint8_t **array, int x)
{
    int	i;

	i = 0;
	while (i < x)
		free(array[i++]);
	free(array);
}
