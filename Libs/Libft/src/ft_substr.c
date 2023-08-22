/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 06:20:14 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		slen = 0;
	else
		slen = ft_strlen(s + start);
	if (len > slen)
		str = malloc(slen + 1);
	else
		str = malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len && i < slen)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
