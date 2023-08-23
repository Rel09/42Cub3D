/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:51:15 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/22 22:03:20 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j] && j < n)
		s1[i++] = s2[j++];
	s1[i] = 0;
	return (s1);
}
