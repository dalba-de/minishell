/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:43:21 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/09 17:03:23 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_pipe(char ***cmd, t_mini *all)
{
	int		p[2];
	pid_t	pid;
	int		fd_in;
	int		i;

	fd_in = 0;
	i = 0;
	while (*cmd != NULL)
	{
		pipe(p);
		if ((pid = fork()) == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			while ((*cmd)[i] != NULL)
			{
				all->my_argv[i] = (*cmd)[i];
				i++;
			}
			try_exec(all);
			exit(EXIT_SUCCESS);
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

void	parse_pipes(char *tmp_argv, t_mini *all)
{
	char	**tmp;
	char	**tmp2;
	char	**cmd[10];
	int		i;
	int		j;

	all->piping = 1;
	i = 0;
	j = 0;
	tmp = ft_split(tmp_argv, PIPE);
	while (tmp[i] != NULL)
	{
		tmp2 = ft_split(tmp[i], ' ');
		cmd[i] = malloc(sizeof(char *) * 4);
		while (tmp2[j] != NULL)
		{
			cmd[i][j] = tmp2[j];
			j++;
		}
		j = 0;
		i++;
	}
	cmd[i] = NULL;
	loop_pipe(cmd, all);
}
