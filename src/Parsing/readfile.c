/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:40:55 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 22:45:20 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Read the file and Store everything in GameStruct with Add_to_Data
bool readfile(char *mapcontent)
{
	char buffer[1000];
	char keychar[3];

	ft_bzero(keychar, 3);
	ft_bzero(buffer, 1000);
	for (int i = 0; mapcontent[i]; i++)
	{
		if (ft_iskeyword(&mapcontent[i]))
		{
			ft_strncat(keychar, &mapcontent[i], ft_iskeyword(&mapcontent[i]));
			i += ft_iskeyword(&mapcontent[i]);
			while (mapcontent[i] && mapcontent[i] != '\n')
			{
				if (!ft_isspace(mapcontent[i]))
					ft_charncat(buffer, mapcontent[i]);
				i++;
			}
			if (!add_to_data(buffer, keychar))
				return (false);
			ft_bzero(keychar, 3);
			ft_bzero(buffer, 1000);
		}
	}
	return (true);
}
