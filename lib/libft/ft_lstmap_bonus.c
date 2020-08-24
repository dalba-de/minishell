/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:20:52 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/18 11:50:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *first;

	if (!lst)
		return (0);
	newlist = ft_lstnew(f(lst->content));
	first = newlist;
	while (lst)
	{
		if (lst->next != NULL)
		{
			newlist->next = ft_lstnew(f(lst->next->content));
			if (newlist->next == NULL)
			{
				ft_lstclear(&first, del);
				return (0);
			}
			newlist = newlist->next;
		}
		lst = lst->next;
	}
	newlist->next = NULL;
	return (first);
}
