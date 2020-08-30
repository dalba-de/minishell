/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_key_ev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:53:06 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/30 14:06:43 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_key_ev(char	***ev, char *key)
{
	int	cont;
	char *aux;

	aux = NULL;
	cont = 0;
	while (ev[cont])
	{
		if (ft_strncmp(ev[cont][0], key, ft_strlen(ev[cont][0])) == 0)
		{
			if (key[ft_strlen(ev[cont][0])] == '\0')
			{
				if (aux == NULL)
					return (ft_strdup(ev[cont][1]));
				else
				{
					ft_strncat(aux, ev[cont][1], ft_strlen(ev[cont][1]));
					return (aux);
				}	
			}
			else
			{
				aux = ft_strdup(ev[cont][1]);
				if (key[ft_strlen(ev[cont][0])] == '$')
					key = &key[ft_strlen(ev[cont][0]) + 1];
				else
					key = &key[ft_strlen(ev[cont][0])];
			}
			cont = -1;
		}	
		cont++;
	}
	return (NULL);
}