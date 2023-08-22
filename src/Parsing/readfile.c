/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:21:07 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 03:05:59 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Check if the file is .cub
static bool	is_format_supported(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i >= 5 && !ft_strncmp(&map[i - 4], ".cub", 4))
		return (true);
	printf("[-] Error\n[-] Map Format not supported\n");
	return (false);
}

// Check if the file exist
static bool	does_file_exist(char *map)
{
	int fd;
	
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("[-] Error\n[-] Map doesn't exist\n");
		return (false);
	}
	close(fd);
	return (true);
}

// Do pretty much all the parsing
bool	map_isbad(char *map)
{
	char	**mapcontent;
	
	if (!is_format_supported(map) || !does_file_exist(map))
		return (true);

	


	return (false);
}
