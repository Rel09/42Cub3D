/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:42:02 by dpotvin           #+#    #+#             */
/*   Updated: 2022/10/24 12:04:19 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				temp;
	char			*str;
	unsigned char	cc;

	i = 0;
	temp = -1;
	str = (char *)s;
	cc = (unsigned char) c;
	while (str[i])
	{
		if (str[i] == cc)
			temp = i;
		i++;
	}
	if (str[i] == cc)
		return (&str[i]);
	if (temp > -1)
		return (&str[temp]);
	return (0);
}

/*
int main()
{
	char a[] = "test1 tests1 test1 test";

	printf("%s",ft_srchr(a, '1'));
	return (0);
}
*/
