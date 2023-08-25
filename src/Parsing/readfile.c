/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:40:55 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/23 21:16:35 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Add the Map Data to Our Struct
bool	add_to_data(char *data, char *keyword)
{
	char	**temp;

	temp = 0;
	if (!ft_strcmp(keyword, "NO"))
		temp = &getgamedata()->s_mapfile.texture_file[0];
	else if (!ft_strcmp(keyword, "SO"))
		temp = &getgamedata()->s_mapfile.texture_file[1];
	else if (!ft_strcmp(keyword, "WE"))
		temp = &getgamedata()->s_mapfile.texture_file[2];
	else if (!ft_strcmp(keyword, "EA"))
		temp = &getgamedata()->s_mapfile.texture_file[3];
	else if (!ft_strcmp(keyword, "F"))
		temp = &getgamedata()->s_mapfile.rgb_color[0];
	else if (!ft_strcmp(keyword, "C"))
		temp = &getgamedata()->s_mapfile.rgb_color[1];
	if (!*temp)
	{
		*temp = ft_strdup(data);
		return (true);
	}
	printf("[-] Error\n[-] Duplicate Data in Map: [%s]\n", keyword);
	return (false);
}

// Try to open the files and store them if all is fine
bool	open_png_files()
{
	int		i;
	char	*str;

	i = -1;
	while (++i < 4)
	{
		str = getgamedata()->s_mapfile.texture_file[i];
		if (!str)
		{
			printf("[-] Error\n[-] Missing Texture file\n");
			return (false);
		}
		if (!is_file_format_supported(str, ".png"))
		{
			printf("[-] Error\n[-] Only accepting .png as Texture files\n");
			return (false);
		}
		if (!does_file_exist(str))
		{
			printf("[-] Error\n[-] [%s] Texture file doesn't exist\n", str);
			return (false);
		}
		gettexture()->textures[i] = mlx_load_png(str);
		free(getgamedata()->s_mapfile.texture_file[i]);
		getgamedata()->s_mapfile.texture_file[i] = 0;
		if (!gettexture()->textures[i])
		{
			printf("[-] Error\n[-] Couldn't load texture [%s]\n", str);
			return (false);
		}
	}
	return (true);
}

// Try to convert the string to RGB
bool	read_rgb_color()
{
	int		i;
	int		count;
	char	*temp;
	int		temp_number[3];

	i = -1;
	while (++i < 2)
	{
		count = 0;
		
		// Load the RGB String
		char *temp = ft_strtok(getgamedata()->s_mapfile.rgb_color[i], ',');
		while (temp)
		{
			
			// Check if there's more than 3 Int value for RGB
			if (count > 2) {
				printf("[-] Error\n[-] RGB value is 3 value only\n");
				return (false);
			}
			// Check if the RGB int isnt numeric
			if (!ft_isnumeric(temp)) {
				printf("[-] Error\n[-] RGB [%s] is not numeric\n");
				return (false);
			}
			
			temp_number[count] = ft_atoi(temp);
			// Check if the RGB int is not a value RGB value (0 to 255)
			if (temp_number[count] < 0 || temp_number[count] > 255)
			{
				printf("[-] Error\n[-] RGB value [%i] isn't between 0 and 255\n", temp_number[count]);
				return (false);
			}
			count++;
			temp = ft_strtok(0, ',');
		}
		
		// Check if we have the 3 RGB Value
		if (count != 3)
		{
			printf("[-] Error\n[-] RGB value doesnt have 3 value\n");
			return (false);
		}
		gettexture()->rgb[i] = rgba_to_pixel(temp_number[0], temp_number[1], temp_number[2], 255);
		free(getgamedata()->s_mapfile.rgb_color[i]);
		getgamedata()->s_mapfile.rgb_color[i] = 0;
	}
	return (true);
}

// Read the file and Store everything in GameStruct with Add_to_Data
bool readfile(char *mapcontent)
{
	char buffer[1000];
	char keychar[3];

	for (int i = 0; mapcontent[i]; i++)
	{
		if (ft_iskeyword(&mapcontent[i]))
		{
			
			ft_bzero(keychar, 3);
			ft_bzero(buffer, 1000);
			ft_strncat(keychar, &mapcontent[i], ft_iskeyword(&mapcontent[i]));
			i += ft_iskeyword(&mapcontent[i]);
			while (mapcontent[i] && mapcontent[i] != '\n')
			{
				if (ft_strlen(buffer) > 995)
				{
					printf("[-] Error\n[-] Tester is crazy - Fix brain\n");
					return (false);
				}
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
