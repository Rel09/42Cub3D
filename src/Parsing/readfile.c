/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:40:55 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/18 20:29:02 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Add the Map Data to Our Struct
bool	add_to_data(char *data, char *keyword)
{
	char	**temp;

	temp = 0;
	if (!ft_strcmp(keyword, "NO"))
		temp = &game()->s_mapfile.texture_file[0];
	else if (!ft_strcmp(keyword, "SO"))
		temp = &game()->s_mapfile.texture_file[1];
	else if (!ft_strcmp(keyword, "WE"))
		temp = &game()->s_mapfile.texture_file[2];
	else if (!ft_strcmp(keyword, "EA"))
		temp = &game()->s_mapfile.texture_file[3];
	else if (!ft_strcmp(keyword, "F"))
		temp = &game()->s_mapfile.rgb_color[0];
	else if (!ft_strcmp(keyword, "C"))
		temp = &game()->s_mapfile.rgb_color[1];
	if (!*temp)
	{
		*temp = ft_strdup(data);
		return (true);
	}
	printf("[-] Error\n[-] Duplicate Data in Map: [%s]\n", keyword);
	return (false);
}

// Try to open the files and store them if all is fine
bool	open_png_files(void)
{
	int		i;
	char	*str;

	i = -1;
	while (++i < 4)
	{
		str = game()->s_mapfile.texture_file[i];
		if (!str)
			return (open_png_error_0());
		if (!is_file_format_supported(str, ".png"))
			return (open_png_error_1());
		if (!does_file_exist(str))
			return (open_png_error_2(str));
		gettexture()->textures[i] = mlx_load_png(str);
		free(game()->s_mapfile.texture_file[i]);
		game()->s_mapfile.texture_file[i] = 0;
		if (!gettexture()->textures[i])
			return (open_png_error_3(str));
	}
	return (true);
}

// Try to convert the string to RGB
bool	read_rgb_color(void)
{
	int		i;
	int		count;
	char	*temp;
	int		num[3];

	i = -1;
	while (++i < 2)
	{
		count = 0;
		temp = ft_strtok(game()->s_mapfile.rgb_color[i], ',');
		while (temp)
		{
			if (count > 2 || !ft_isnumeric(temp) || ft_strlen(temp) > 3)
				return (readfile_error_4(count, temp));
			num[count] = ft_atoi(temp);
			if (num[count] < 0 || num[count] > 255)
				return (readfile_error_2(num[count]));
			count++;
			temp = ft_strtok(0, ',');
		}
		if (count != 3)
			return (readfile_error_3());
		gettexture()->rgb[i] = rgba_to_pixels(num);
	}
	return (true);
}

// Read the file and Store everything in GameStruct with Add_to_Data
bool	readfile(char *mapcontent)
{
	char	buffer[1000];
	char	keychar[3];
	int		i;

	i = -1;
	while (mapcontent[++i])
	{
		if (ft_iskeyword(&mapcontent[i]))
		{
			ft_bzero2(keychar, 3, buffer, 1000);
			ft_strncat(keychar, &mapcontent[i], ft_iskeyword(&mapcontent[i]));
			i += ft_iskeyword(&mapcontent[i]);
			while (mapcontent[i] && mapcontent[i] != '\n')
			{
				if (ft_strlen(buffer) > 995)
					return (readfile_error_5());
				if (!ft_isspace(mapcontent[i]))
					ft_charncat(buffer, mapcontent[i]);
				i++;
			}
			if (!add_to_data(buffer, keychar))
				return (false);
		}
	}
	return (true);
}
