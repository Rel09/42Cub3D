/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:21:07 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/24 03:32:53 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Check if the file is .cub
bool	is_file_format_supported(char *map, char *format) {
	int	i;
	int	len;

	len = ft_strlen(format);
	i = ft_strlen(map);
	if (i >= len + 1 && !ft_strncmp(&map[i - 4], format, ft_strlen(format)))
		return (true);
	return (false);
}

// Join the two string together
static char	*ft_join(char *buffer, char *buf) {
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

// Read the File and store the data in an array
static char	*open_file(char *map) {
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

// Check if the file exist
bool	does_file_exist(char *file) {
	int fd;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

// Do pretty much all the parsing
bool	map_isbad(char *map) {
	char	*mapcontent;
	
	if (!is_file_format_supported(map, ".cub"))
	{
		printf("[-] Error\n[-] Map Format not supported\n");
		return (true);
	}
	if (!does_file_exist(map))
	{
		printf("[-] Error\n[-] Map [%s] doesn't exist\n", map);
		return (true);
	}
	mapcontent = open_file(map);
	if (!readfile(mapcontent) || !read_rgb_color() || !open_png_files() || !readmap(mapcontent))
	{
		free(mapcontent);
		return (true);
	}
	free(mapcontent);
	return (false);
}
