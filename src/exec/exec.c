/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:30:01 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 01:08:35 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	not_found(t_mini *all)
{
	ft_putstr_fd(all->cmd, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	all->exit_status = 127;
}

void	call_execve(char *cmd, t_mini *all, char **cmdl)
{
	int i;

	if ((all->pid = fork()) == 0)
	{
		i = execve(cmd, cmdl, env_to_double(all->ev));
		if (i < 0)
		{
			ft_putstr_fd(all->cmd, 1);
			ft_putendl_fd(": command not found", 1);
			exit(127);
		}
	}
	else
		waitpid(all->pid, &all->status, 0);
	if (WIFEXITED(all->status))
		all->exit_status = WEXITSTATUS(all->status);
}

int		attach_path(t_mini *all, char *cmd)
{
	char	ret[100];
	int		index;
	int		fd;

	bzero(ret, 100);
	index = 0;
	while (all->search_path[index] != NULL)
	{
		ft_strcpy(ret, all->search_path[index]);
		ft_strncat(ret, cmd, ft_strlen(cmd));
		if ((fd = open(ret, O_RDONLY)) > 0)
		{
			ft_strncpy(cmd, ret, ft_strlen(ret));
			close(fd);
			return (0);
		}
		index++;
	}
	return (0);
}

int		check_slash(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int		try_exec(t_mini *all, char **cmdl)
{
	all->cmd = (char *)malloc(sizeof(char) * 100);
	ft_strncpy(all->cmd, cmdl[0], ft_strlen(cmdl[0]));
	ft_strncat(all->cmd, "\0", 1);
	if ((all->rd = check_own_cmd(all->cmd)) != 0)
		bridge_own_cmd(all->rd, all, cmdl);
	else
	{
		if (!(check_slash(all->cmd)))
		{
			if (attach_path(all, all->cmd) == 0)
				call_execve(all->cmd, all, cmdl);
		}
		else
		{
			if ((all->fd = open(all->cmd, O_RDONLY)) > 0)
			{
				close(all->fd);
				call_execve(all->cmd, all, cmdl);
			}
			else
				not_found(all);
		}
	}
	return (0);
}
