/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:19:54 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:28 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_char(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*special_case(char *s)
{
	s[0] = '-';
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	s[11] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*s;

	len = (count_char(n));
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n == -2147483648)
		return (special_case(s));
	s[len--] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n > 9)
	{
		s[len--] = (n % 10) + '0';
		n = n / 10;
	}
	s[len] = n % 10 + '0';
	return (s);
}
