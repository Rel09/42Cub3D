/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 02:20:27 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 23:24:30 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// FloodFill Backend
static void	floodfill(uint8_t **arr, uint8_t nval, int x, int y)
{
	int	rows;
	int	cols;

	rows = game()->map_y;
	cols = game()->map_x;
	if (x < 0 || x >= rows || y < 0 || y >= cols
		|| arr[x][y] == nval || arr[x][y] == 1)
		return ;
	arr[x][y] = nval;
	floodfill(arr, nval, x + 1, y);
	floodfill(arr, nval, x - 1, y);
	floodfill(arr, nval, x, y + 1);
	floodfill(arr, nval, x, y - 1);
}

// Get rid of all the non reacheable area
static void	illuminatifloodfill(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game()->map_y)
	{
		while (j < game()->map_x)
		{
			if (!(game()->nmap[i][j] == 7))
				game()->nmap[i][j] = 1;
			j++;
		}
		j = 0;
		i++;
	}
}

// Check if we have only one spawn point and if we have no shit in map
bool	detail_parser(void)
{
	uint8_t	**map;
	int		i[4];

	ft_bzero(i, sizeof(i));
	map = game()->nmap;
	while (i[0] < game()->map_y)
	{
		while (i[1] < game()->map_x)
		{
			if (map[i[0]][i[1]] >= 2 && map[i[0]][i[1]] <= 5)
			{
				(unit()->coord) = (t_coord){i[1], i[0]};
				setplayerangle(map[i[0]][i[1]]);
				game()->nmap[i[0]][i[1]] = 0;
				i[2]++;
			}
			else if (map[i[0]][i[1]] == 8)
				i[3]++;
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
	}
	return (i[2] == 1 && i[3] == 0);
}

// Do the Flood Fill Test
bool	can_map_be_flooded(void)
{
	uint8_t	**map;

	map = game()->nmap;
	floodfill(map, 7, unit()->coord.y, unit()->coord.x);
	if (map[0][0] == 7)
	{
		display_map(map, game()->map_y, game()->map_x);
		printf("[-] Error\n[-] Map Failed FloodFill Test\n");
		return (true);
	}
	floodfill(map, 0, unit()->coord.y, unit()->coord.x);
	display_map(map, game()->map_y, game()->map_x);
	floodfill(map, 7, unit()->coord.y, unit()->coord.x);
	illuminatifloodfill();
	floodfill(map, 0, unit()->coord.y, unit()->coord.x);
	return (false);
}

// I dont think you need comment on this one
void	free_map(uint8_t **array, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(array[i++]);
	free(array);
}
