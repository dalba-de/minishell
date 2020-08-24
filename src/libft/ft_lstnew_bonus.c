/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:12:16 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/18 13:01:59 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list *l;

	if (!(l = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		l->content = NULL;
		return (l);
	}
	else
	{
		l->content = malloc(sizeof(content));
		if (l->content == NULL)
			return (NULL);
		ft_memcpy(l->content, content, ft_strlen(content));
	}
	l->next = NULL;
	return (l);
}
