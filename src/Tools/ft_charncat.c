/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:32:27 by dpotvin           #+#    #+#             */
/*   Updated: 2023/08/26 00:42:19 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_charncat(char *dest, const char src)
{
	char	*dest_end;

	dest_end = dest + strlen(dest);
	if (src)
		*dest_end++ = src;
	*dest_end = 0;
}
