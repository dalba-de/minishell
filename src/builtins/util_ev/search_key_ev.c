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

char	*search_key_ev(char ***ev, char *key)
{
	int	cont;

	cont = 0;
	while (ev[cont])
	{
		if (strcmp(ev[cont][0], key)  == 0)
			return (ft_strdup(ev[cont][1]));
		cont++;
	}
	return (NULL);
}
