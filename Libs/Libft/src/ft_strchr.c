/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:24:28 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	cc;

	i = 0;
	str = (char *)s;
	cc = (unsigned char)c;
	if (c == 0)
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == cc)
			return (&str[i]);
		i++;
	}
	if (str[i] == cc)
		return (&str[i]);
	return (0);
}
