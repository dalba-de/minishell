/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:27:57 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/27 13:35:35 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_mini *all)
{
	int	cont;

	cont = 1;
	while (all->my_argv[cont])
	{
		delev(all, all->my_argv[cont]);
		cont++;
	}
}