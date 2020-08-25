/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:18:12 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/18 13:06:10 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

	aux = *alst;
	if (aux == NULL)
		*alst = new;
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
}
