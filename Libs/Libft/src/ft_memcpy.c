/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:02:16 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	void			*temp;

	temp = dest;
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (!d && !s)
		return (0);
	while (n--)
		(*d++ = *s++);
	return (temp);
}
