/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 07:56:24 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	countw(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		num++;
		while (*s && *s != c)
			s++;
		while (*s == c && c != '\0')
			s++;
	}
	return (num);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static const char	*nextw(char const *s, char c, char *a)
{
	int	i;

	i = 0;
	while (*s && *s != c)
		a[i++] = *s++;
	a[i] = '\0';
	while (*s && *s == c)
		s++;
	return (s);
}

void	freeall(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		w;
	char	**a;

	while (*s == c && c != '\0')
		s++;
	w = (countw(s, c));
	a = (char **)malloc((w + 1) * sizeof(char *));
	if (!a)
		return (0);
	i = 0;
	while (i < w)
	{
		a[i] = (char *)malloc((wordlen(s, c) + 1));
		if (!a[i])
		{
			freeall(a);
			free(a);
			return (0);
		}
		s = nextw(s, c, a[i]);
		i++;
	}
	a[i] = 0;
	return (a);
}
