/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strco1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:13:09 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:11 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_strco1(t_mini *all, int *cont)
{
	char	*str;

	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '\'');
	while (all->strl[*cont] && all->strl[*cont] != '\'')
		(*cont)++;
	all->strl[*cont] == '\'' ? ((*cont)++) : 0;
	return (str);
}
