/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:22:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/11 18:22:40 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	freecer(char ***ev, int len)
{
	int	cont;

	cont = 0;
	while (cont < len)
	{
		free(ev[cont][0]);
		free(ev[cont][1]);
		cont++;
	}
	cont = 0;
	while (cont < len)
	{
		free(ev[cont]);
		cont++;
	}
	free(ev);
	ev = NULL;
}

int		count_line(char ***envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
}
