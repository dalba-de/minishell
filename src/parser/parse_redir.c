/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:10:58 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 03:00:29 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void   do_command(char **cmdl, char *input, char *output, t_mini *all)
{
	int fd_in;
	int fd_out;

	if ((all->pid = fork()) == 0)
  	{
		if (all->in)
		{
			fd_in = open(input, O_RDONLY);
			dup2(fd_in, 0);
			close(fd_in);
		}
		if (all->out)
		{
			if (!all->double_redir)
				fd_out = open (output, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			else
				fd_out = open (output, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			dup2(fd_out, 1);
			close(fd_out);
		}
		try_exec(all, cmdl);
		exit(EXIT_FAILURE);
  	}
  	else
	{
		waitpid(all->pid, &all->status, 0);
    	if (WIFEXITED(all->status))
        	all->exit_status = WEXITSTATUS(all->status);
	}
}

int   redir_check(char **tmp, char **input_file, char c, t_mini *all)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == c)
		{
			if (c == '>' && (tmp[i][1] == c))
				all->double_redir = 1;
			if (tmp[i + 1] != NULL)
				*input_file = tmp[i + 1];
			else
				return (-1);
			while (tmp[i - 1] != NULL)
			{
				tmp[i] = tmp[i + 2];
				i++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	parse_redir(char **cmdl, t_mini *all)
{
	char *input_file;
	char *output_file;

	all->double_redir = 0;
	all->in = redir_check(cmdl, &input_file, '<', all);
	all->out = redir_check(cmdl, &output_file, '>', all);
	if (all->in == -1 || all->out == -1)
	{
		ft_putendl_fd("syntax error", STDERR_FILENO);
		return ;
	}
	do_command(cmdl, input_file, output_file, all);
}
