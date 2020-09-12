/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:43:21 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 02:34:47 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	forking_pipe(t_mini *all, int p[2], int fd_in, char ***cmd)
{
	int		i;

	i = 0;
	dup2(fd_in, 0);
	if (*(cmd + 1) != NULL)
		dup2(p[1], 1);
	close(p[0]);
	while ((*cmd)[i] != NULL)
	{
		all->my_argv[i] = (*cmd)[i];
		i++;
	}
	try_exec(all, all->my_argv);
	exit(EXIT_SUCCESS);
}

void	loop_pipe(char ***cmd, t_mini *all)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;

	fd_in = 0;
	while (*cmd != NULL)
	{
		pipe(p);
		if ((pid = fork()) == 0)
		{
			forking_pipe(all, p, fd_in, cmd);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
}

void	parse_pipes(char **cmdl, t_mini *all)
{
	char	**cmd[10];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (cmdl[j] != NULL)
	{
		cmd[i] = malloc(sizeof(char *) * 4);
		k = 0;
		if (cmdl[j][0] == PIPE)
			j++;
		while (cmdl[j] && cmdl[j][0] != PIPE)
		{
			cmd[i][k] = cmdl[j];
			k++;
			j++;
		}
		cmd[i][k] = NULL;
		i++;
	}
	cmd[i] = NULL;
	loop_pipe(cmd, all);
}
