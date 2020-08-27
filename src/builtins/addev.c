/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:53:12 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/27 12:53:13 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	addev(t_mini *all, char *key, char *value)
{
	int		len;
	int		cont;
	char	***arr;

	len = count_line(all->ev);
	arr = malloc(sizeof(char *) * (len + 2));
	cont = 0;
	while (cont < len)
	{
		arr[cont] = malloc(sizeof(char *) * (2));
		arr[cont][0] = ft_strdup(all->ev[cont][0]);
		arr[cont][1] = ft_strdup(all->ev[cont][1]);
		cont++;
	}
	arr[cont] = malloc(sizeof(char *) * (2));
	arr[cont][0] = ft_strdup(key);
	arr[cont][1] = ft_strdup(value);
	arr[cont + 1] = malloc(sizeof(char *) * (2));
	arr[cont + 1][0] = NULL;
	arr[cont + 1][1] = NULL;
	freecer(all->ev, len + 2);
	all->ev = arr;
}