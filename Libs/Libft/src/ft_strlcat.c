/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:15:05 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	j = 0;
	i = ft_strlen(dest);
	len_dest = ft_strlen(dest);
	if (size < 1)
		return (ft_strlen(src) + size);
	while (src[j] && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	if (size < len_dest)
		return (ft_strlen(src) + size);
	else
		return (len_dest + ft_strlen(src));
}
