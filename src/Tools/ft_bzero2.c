/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:05:12 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/25 23:06:08 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_bzero2(void *s, size_t n, void *s1, size_t n1)
{
	unsigned char	*str;
	unsigned char	*str1;

	str = s;
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
	str1 = s1;
	while (n1 > 0)
	{
		*str1++ = '\0';
		n1--;
	}
}
