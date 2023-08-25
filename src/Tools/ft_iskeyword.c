/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iskeyword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:16:48 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/23 17:41:21 by dpotvin          ###   ########.fr       */
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
