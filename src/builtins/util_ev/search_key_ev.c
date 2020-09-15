/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_ev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:53:06 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:37:25 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_strcmp(char *s1, char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] && s2[cont])
	{
		if (s1[cont] != s2[cont])
			return (s1[cont] - s2[cont]);
		cont++;
	}
	return (s1[cont] == '\0' && s2[cont] == '\0' ? (0) : (s1[cont] - s2[cont]));
}

char	*search_key_ev(char ***ev, char *key)
{
	int	cont;

	cont = 0;
	while (ev[cont])
	{
		if (ft_strcmp(ev[cont][0], key) == 0)
			return (ft_strdup(ev[cont][1]));
		cont++;
	}
	return (NULL);
}
