/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 22:24:07 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 00:37:41 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	readfile_error_4(int count, char *temp)
{
	if (count > 2)
		return (readfile_error_0());
	return (readfile_error_1(temp));
}

bool	open_png_error_0(void)
{
	printf("[-] Error\n[-] Missing Texture file\n");
	return (false);
}

bool	open_png_error_1(void)
{
	printf("[-] Error\n[-] Only accepting .png as Texture files\n");
	return (false);
}

bool	open_png_error_2(char *str)
{
	printf("[-] Error\n[-] [%s] Texture file doesn't exist\n", str);
	return (false);
}

bool	open_png_error_3(char *str)
{
	printf("[-] Error\n[-] Couldn't load texture [%s]\n", str);
	return (false);
}
