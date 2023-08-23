/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:21:07 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 22:59:49 by dpotvin          ###   ########.fr       */
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

// Join the two string together
static char	*ft_join(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// Read the File and store the data in an array
static char	*open_file(char *map)
{
	int		fd;
	int		buffersize;
	int		byte_read;
	char	*buffer;
	char	*temp;

	buffersize = 1000;
	temp = ft_calloc(1, sizeof(char));
	fd = open(map, O_RDONLY);
	buffer = ft_calloc(buffersize + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, buffersize);
		if (byte_read == -1)
		{
			free(buffer);
			close(fd);
			return (NULL);
		}
		buffer[byte_read] = 0;
		temp = ft_join(temp, buffer);
	}
	free(buffer);
	close(fd);
	return (temp);
}

// Do pretty much all the parsing
bool	map_isbad(char *map)
{
	char	*mapcontent;
	
	if (!is_format_supported(map) || !does_file_exist(map))
		return (true);
	mapcontent = open_file(map);
	if (!readfile(mapcontent))
		return (true);
	// Check if all the textures file and RGB color are fine
	
	// Parse the actual map

	free(mapcontent);
	return (false);
}
