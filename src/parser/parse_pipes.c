/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:43:21 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 14:12:18 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	loop_pipe(char ***cmd, char **env)
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
			dup2(fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(p[1], 1);
			close(p[0]);
			execve((*cmd)[0], *cmd, env);
			exit(EXIT_FAILURE);
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

void	attach_pipe(char ***cmd, t_mini *all)
{
	int i;

	i = 0;
	while (cmd[i] != NULL)
	{
		attach_path(all, cmd[i][0]);
		i++;
	}
}

void	fixed_cmd(char ***cmd, t_mini *all)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[i] != NULL)
	{
		j = 0;
		while (cmd[i][j] != NULL)
		{
			cmd[i][j] = delete_quotes(cmd[i][j]);
			j++;
		}
		i++;
	}
	attach_pipe(cmd, all);
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
	fixed_cmd(cmd, all);
	loop_pipe(cmd, all->env);
}
