/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:48:52 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 01:17:00 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_mini *all, char **cmdl)
{
	(void)cmdl;
	int i;

	if (cmdl[2] != NULL)
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		all->exit_status = 1;
		return ;
	}
	else if (cmdl[1] != NULL)
	{
		i = 0;
		while (cmdl[1][i])
		{
			if (!ft_isdigit(cmdl[1][i]))
				all->exit_status = 0;
			i++;
		}
		all->exit_status = ft_atoi(cmdl[1]);
	}
	exit(0);
}
