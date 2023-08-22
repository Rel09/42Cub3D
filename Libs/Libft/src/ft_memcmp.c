/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:10:58 by dpotvin           #+#    #+#             */
/*   Updated: 2022/10/21 03:29:12 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, int n)
{
	unsigned char	*sstr1;
	unsigned char	*sstr2;

	sstr1 = (unsigned char *)str1;
	sstr2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*sstr1 != *sstr2)
			return (*sstr1 - *sstr2);
		n--;
		sstr1++;
		sstr2++;
	}
	return (0);
}
