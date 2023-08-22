/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpotvin <dpotvin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 03:08:39 by dpotvin           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:49 by dpotvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*news;

	news = 0;
	if (!lst || !f)
		return (0);
	while (lst)
	{
		tmp = ft_lstnew(lst);
		if (!tmp)
		{
			ft_lstclear(&news, del);
			return (0);
		}
		else
		{
			tmp->next = 0;
			tmp->content = f(lst->content);
			ft_lstadd_back(&news, tmp);
		}
		lst = lst->next;
	}
	return (news);
}
