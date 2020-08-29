/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:58:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 12:18:18 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_mini *all)
{
	int i;

	i = 0;
	while (all->ev[i] != NULL)
	{
		ft_putstr_fd(all->ev[i][0], 1);
		ft_putchar_fd('=', 1);
		ft_putendl_fd(all->ev[i][1], 1);
		i++;
	}
}
