/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iskeyword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:48 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 22:43:17 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Return the length of the keyword if its a keyword, 0 otherwise
uint8_t ft_iskeyword(char *str)
{
	char	*word[6];
	int		i;

	i = 0;
	word[0] = "NO";
	word[1] = "SO";
	word[2] = "WE";
	word[3] = "EA";
	word[4] = "F";
	word[5] = "C";
	while (i < 6)
	{
		if (!ft_strncmp(str, word[i], ft_strlen(word[i])))
			return (ft_strlen(word[i]));
		i++;
	}
	return (false);
}

// Add the Map Data to Our Struct
bool	add_to_data(char *data, char *keyword)
{
	char	**temp;

	temp = 0;
	if (!ft_strcmp(keyword, "NO"))
		temp = &getgamedata()->s_mapfile.NO;
	else if (!ft_strcmp(keyword, "SO"))
		temp = &getgamedata()->s_mapfile.SO;
	else if (!ft_strcmp(keyword, "WE"))
		temp = &getgamedata()->s_mapfile.WE;
	else if (!ft_strcmp(keyword, "EA"))
		temp = &getgamedata()->s_mapfile.EA;
	else if (!ft_strcmp(keyword, "F"))
		temp = &getgamedata()->s_mapfile.F;
	else if (!ft_strcmp(keyword, "C"))
		temp = &getgamedata()->s_mapfile.C;
	if (!*temp)
	{
		*temp = ft_strdup(data);
		return (true);
	}
	printf("[-] Error\n[-] Duplicate Data in Map: [%s]\n", keyword);
	return (false);
}
