/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addev.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:53:12 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/17 18:50:41 by dalba-de         ###   ########.fr       */
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
		arr[cont][2] = NULL;
		cont++;
	}
	arr[cont] = malloc(sizeof(char *) * (2));
	arr[cont][0] = ft_strdup(key);
	arr[cont][1] = value == NULL ? (ft_strdup("")) : (ft_strdup(value));
	arr[cont][2] = NULL;
	arr[cont + 1] = NULL;
	free_3d(all->ev);
	all->ev = arr;
}
