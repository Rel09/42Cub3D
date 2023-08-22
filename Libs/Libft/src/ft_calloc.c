/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:43:10 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:22 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*str;

	str = malloc(nitems * size);
	if (!str)
		return (0);
	ft_bzero(str, nitems * size);
	return (str);
}
