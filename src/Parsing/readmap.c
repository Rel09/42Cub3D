/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:16:42 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/19 16:40:04 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Remove all the already parsed data
static char	*cleaned_up_file(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_iskeyword(&map[i]))
		{
			while (map[i] && map[i] != '\n')
				i++;
			if (map[i] == '\n')
				map = &map[i + 1];
			else
				map = &map[i];
			i = 0;
		}
		else
			i++;
	}
	return (map);
}

// Updated remove_empty_lines function
static char	*remove_empty_lines(char *map)
{
	char	temp[1000];
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	if (!map[i[0]])
		return (0);
	while (!i[1])
	{
		parse_mapfile0(map, temp, &i[0], &i[1]);
		if (!i[1])
		{
			map = &map[i[0]];
			i[0] = 0;
		}
		if (!map[i[0]])
			break ;
	}
	while (i[1] > 0)
	{
		if (!parse_mapfile1(map, temp, &i[0], &i[1]))
			return (0);
	}
	map[i[0] - 1] = 0;
	return (map);
}

// Allocate uint8_t** for the map using CALLOC
uint8_t	**allocate_map(int x, int y)
{
	uint8_t	**t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t = ft_calloc(x, sizeof(uint8_t *));
	if (!t)
		return (readfile_error_6());
	while (i < x)
	{
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
	if (!mapcontent)
	{
		printf("[-] Error\n[-] No Map in file\n");
		return (false);
	}
	if (!replacetabswithspaces(mapcontent) || !game()->nmap)
		return (false);
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
