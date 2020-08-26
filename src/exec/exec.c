/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 19:30:01 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/26 20:00:38 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void call_execve(char *cmd, t_mini *all)
{
	int i;

	if(fork() == 0)
	{
		i = execve(cmd, all->my_argv, all->env);
		if(i < 0)
			exit(1);		
	}
	else
		wait(NULL);
}

int attach_path(t_mini *all, char *cmd)
{
	char ret[100];
	int index;
	int fd;
	
	bzero(ret, 100);
	index = 0;
	while (all->search_path[index] != NULL)
	{
		ft_strcpy(ret, all->search_path[index]);
		ft_strncat(ret, cmd, ft_strlen(cmd));
		if((fd = open(ret, O_RDONLY)) > 0)
		{
			ft_strncpy(cmd, ret, ft_strlen(ret));
			close(fd);
			return (0);
		}
		index++;
	}
	return (1);
}

int	check_slash(char *cmd)
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

int	try_exec(t_mini *all)
{
	all->cmd = (char *)malloc(sizeof(char) * 100);
	ft_strncpy(all->cmd, all->my_argv[0], ft_strlen(all->my_argv[0]));
	ft_strncat(all->cmd, "\0", 1);
	if (!(check_slash(all->cmd)))
	{
		if (attach_path(all, all->cmd) == 0)
			call_execve(all->cmd, all);
		else
		{
			ft_putstr_fd(all->cmd, 1);
			ft_putendl_fd(": command not found", 1);
		}
	}
	return (0);
}