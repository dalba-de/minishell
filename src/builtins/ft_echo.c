/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:32:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 18:33:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_mini *all, char **cmdl)
{
	int i;
	int flagn;
	int flag_start;

	flagn = 0;
	flag_start = 0;
	i = 1;
	while (cmdl[i])
	{
		if (cmdl[i][0] == '-' && cmdl[i][1] == 'n'
		&& cmdl[i][2] == '\0' && !flag_start)
			flagn = 1;
		else
		{
			flag_start = 1;
			ft_putstr_fd(cmdl[i], 1);
			if (cmdl[i + 1] != NULL)
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (!flagn)
		ft_putchar_fd('\n', 1);
	all->exit_status = 0;
}
