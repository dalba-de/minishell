/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:27:57 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 01:16:20 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_mini *all, char **cmdl)
{
	int	cont;

	cont = 1;
	while (cmdl[cont])
	{
		delev(all, cmdl[cont]);
		cont++;
	}
}
