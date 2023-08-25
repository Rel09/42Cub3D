/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:59:06 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/24 03:45:36 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Return the longest row of the Map
int	get_map_row(char *map)
{
	int	i;
	int biggest_count;
	int	current_count;

	i = 0;
	current_count = 0;
	biggest_count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (current_count > biggest_count)
				biggest_count = current_count;
			current_count = 0;
			i++;
			continue;
		}
		current_count++;
		i++;
	}
	return (biggest_count);
}

// Return the height of the Map
int get_map_height(char *map)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

// Hard coded Convertion, because why not
static uint8_t convert_char(char c)
{
	if (c == '0' || ft_isspace(c))
		return (0);
	else if (c == '1')
		return (1);
	else if (c == 'N')
		return (2);
	else if (c == 'S')
		return (3);
	else if (c == 'E')
		return (4);
	else if (c == 'W')
		return (5);
	return (8);
}

// Just display the map
void	display_map(uint8_t **map, int y, int x)
{
	int		i;
	int		j;
	uint8_t	c;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			c = map[i][j];
			if (c == 1)
				printf(BLACK_BG PINK_TEXT"█"RESET, c);
			else if (c >= 2 && c <= 5)
				printf(BLACK_BG RED_TEXT"X"RESET);
			else if (c == 7)
				printf(BLUE_BG" "RESET);
			else if (c == 8)
				printf(GREEN_BG" "RESET);
			else
				printf(BLACK_BG" "RESET);
			j++;
		}
		j = 0;
		i++;
		printf("\n");
	}
}

// Transform 1D Char array to 2D uint8_t array
void convert_map(char *mapcontent) {
    int i;
    int j;
    int k;

	i = 0;
	j = 0;
	k = 0;
	while (mapcontent[i]) {
		if (mapcontent[i] != '\n')
		{
			getgamedata()->nmap[j + 1][k + 1] = convert_char(mapcontent[i]);
			k++;
		}
		else
		{
			j++;
			k = 0;
		}
		i++;
	}
}

