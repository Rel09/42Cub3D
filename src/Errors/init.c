/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:29:35 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 00:37:18 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Check if user gave us a map file
bool	argc_isbad(int argv)
{
	if (argv != 2)
	{
		printf("[-] Error\n[-] No Map = No Game\n");
		return (true);
	}
	return (false);
}

bool	readfile_error_0(void)
{
	printf("[-] Error\n[-] RGB value is 3 value only\n");
	return (false);
}

bool	readfile_error_1(char *value)
{
	printf("[-] Error\n[-] RGB [%s] is not numeric\n", value);
	return (false);
}

bool	readfile_error_2(int value)
{
	printf("[-] Error\n[-] RGB value [%i] isn't between 0 and 255\n", value);
	return (false);
}

bool	readfile_error_3(void)
{
	printf("[-] Error\n[-] RGB value doesnt have 3 value\n");
	return (false);
}
