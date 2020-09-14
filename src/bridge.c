/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 18:18:30 by dalba-de         ###   ########.fr       */
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

int		piping(char **cmdl)
{
	int i;

	i = 0;
	while (cmdl[i])
	{
		if (cmdl[i][0] == PIPE)
			return (1);
		i++;
	}
	return (0);
}

void	bridge(char **cmdl, t_mini *all)
{
	if (piping(cmdl))
		parse_pipes(cmdl, all);
	else if (redir(cmdl))
		parse_redir(cmdl, all);
	else
		try_exec(all, cmdl);
}
