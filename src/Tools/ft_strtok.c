/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:58:09 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/23 19:58:18 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ft_strtok(char *str, const char delim)
{
	static char	*stock;
	char		*output;
	bool		found;

	if (str)
		stock = str;
	output = 0;
	found = false;
	while (*stock)
	{
		if (!found && !(*stock == delim))
		{
			found = true;
			output = stock;
		}
		else if (found && *stock == delim)
		{
			*stock = 0;
			stock++;
			break ;
		}
		stock++;
	}
	return (output);
}
