/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/17 16:39:40 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redir(char **cmdl)
{
	int i;

	i = 0;
	while (cmdl[i])
	{
		if (cmdl[i][0] == '>' || cmdl[i][0] == '<')
			return (1);
		i++;
	}
	return (0);
}

int		piping(char **cmdl, t_mini *all)
{
	int i;

	i = 0;
	while (cmdl[i])
	{
		if (cmdl[i][0] == PIPE)
		{
			all->pipe_count = 0;
			while (cmdl[i])
			{
				if (cmdl[i][0] == PIPE)
					all->pipe_count++;
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	bridge(char **cmdl, t_mini *all)
{
	if (piping(cmdl, all))
		parse_pipes(cmdl, all);
	else if (redir(cmdl))
		parse_redir(cmdl, all);
	else
		try_exec(all, cmdl);
}
