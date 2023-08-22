/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:16:00 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*ss1;
	char	*ss2;

	ss1 = (char *) s1;
	ss2 = (char *) s2;
	if (*ss2 == '\0')
		return (ss1);
	i = 0;
	while (ss1[i] && i < n)
	{
		j = 0;
		while (ss1[i + j] == ss2[j] && ss1[i + j] && ss2[j])
		{
			if (ss2[j + 1] == '\0' && i + j < n)
				return (&ss1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
