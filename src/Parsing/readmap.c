/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:16:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/24 23:51:18 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Remove all the already parsed data
static char *cleaned_up_file(char *map)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			index = i + 1;
		if (ft_iskeyword(&map[i]))
		{
			while (map[index] && map[index] != '\n')
				index++;

			if (map[index] == '\n')
				map = &map[index + 1];
			else
				map = &map[index];
				
		}
		i++;
	}
	return (map);
}

// Count all the char in a string, to remove if non-pertinent
static int	count_char(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] >= 33 && str[i] <= 126)
		{
			count++;
			i++;
		}
		i++;
	}
	return (count);
}

// Remove the additional useless lines
static char *remove_empty_lines(char *map)
{
	char temp[1000];
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!map[i])
		return (0);

	while (count == 0)
	{
		ft_bzero(temp, 1000);
		while (map[i] && map[i] != '\n')
			ft_charncat(temp, map[i++]);
		if (!map[i])
			return (0);
		i++;
		count = count_char(temp);
		if (!count)
		{
			map = &map[i];
			i = 0;
		}
	}
	while (count > 0)
	{
		ft_bzero(temp, 1000);
		while (map[i] && map[i] != '\n')
			ft_charncat(temp, map[i++]);
		i++;
		count = count_char(temp);
	}
	map[i - 2] = 0;
	return (map);
}

// Allocate uint8_t** for the map using CALLOC
uint8_t **allocate_map(int x, int y)
{
	uint8_t **t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t = ft_calloc(x, sizeof(uint8_t *));
	if (!t)
	{
		printf("[-] Error\n[-] Couldnt Malloc the Map [0]\n");
		return (0);
	}
	while (i < x) {
		t[i] = ft_calloc(y, sizeof(uint8_t));
		if (!t[i])
		{
			printf("[-] Error\n[-] Couldnt Malloc the Map [1]\n");
			while (j < i)
				free(t[j++]);
            free(t);
			return (0);
		}
		i++;
	}
    return (t);
}


// Return us the Map as uint8_t**
bool	readmap(char *mapcontent)
{
	mapcontent = cleaned_up_file(mapcontent);
	mapcontent = remove_empty_lines(mapcontent);
	getgamedata()->map_x = get_map_row(mapcontent) + 2;
	getgamedata()->map_y = get_map_height(mapcontent) + 2;
	
	getgamedata()->nmap = allocate_map(getgamedata()->map_y, getgamedata()->map_x);
	if (!getgamedata()->nmap)
		return (false);
	
	convert_map(mapcontent);
	if (!detail_parser())
	{
		printf("[-] Error\n[-] Spawning point is shit / Garbage in Map\n");
		return (false);
	}
	if (can_map_be_flooded())
		return (false);
	
	printf(BLACK_BG PINK_TEXT"[+] Map Loaded\x1B[0m\n");
	return (true);
}
