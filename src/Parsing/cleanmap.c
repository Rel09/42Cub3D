/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:19:47 by dpotvin           #+#    #+#             */
/*   Updated: 2023/09/19 16:31:52 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Count all the char in a string, to remove if non-pertinent
static int	count_char(char *str)
{
	int	i;
	int	count;

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

void	parse_mapfile0(char *map, char *temp, int *index, int *count)
{
	ft_bzero(temp, 1000);
	while (map[*index] && map[*index] != '\n')
	{
		ft_charncat(temp, map[*index]);
		(*index)++;
	}
	if (!map[*index])
		return ;
	(*index)++;
	*count = count_char(temp);
}

bool	parse_mapfile1(char *map, char *temp, int *index, int *count)
{
	ft_bzero(temp, 1000);
	printf("Starting at [%i]\n", *index);
	while (map[*index] && map[*index] != '\n')
	{
		if (ft_strlen(temp) >= 999)
		{
			printf("[-] Error\n[-] Map too large -> Returning empty map\n");
			return (false);
		}
		ft_charncat(temp, map[*index]);
		(*index)++;
	}
	(*index)++;
	*count = count_char(temp);
	return (true);
}
