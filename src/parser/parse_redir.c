/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:10:58 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/05 01:12:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_fork(t_mini *all, char **cmdl, char *input, char *output)
{
	int fd_in;
	int fd_out;

	if (all->in)
	{
		fd_in = open(input, O_RDONLY);
		dup2(fd_in, 0);
		close(fd_in);
	}
	if (all->out)
	{
		if (!all->double_redir)
			fd_out = open(output, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		else
			fd_out = open(output, O_RDWR | O_CREAT | O_APPEND,
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		dup2(fd_out, 1);
		close(fd_out);
	}
	try_exec(all, cmdl);
	exit(EXIT_FAILURE);
}

void	do_command(char **cmdl, char *input, char *output, t_mini *all)
{
	if ((all->pid = fork()) == 0)
		redir_fork(all, cmdl, input, output);
	else
	{
		waitpid(all->pid, &all->status, 0);
		if (WIFEXITED(all->status))
			all->exit_status = WEXITSTATUS(all->status);
	}
}

void	parse_redir(char **cmdl, t_mini *all)
{
	char *input_file;
	char *output_file;

	all->double_redir = 0;
	all->in = check_in(cmdl, &input_file, all);
	all->out = check_out(cmdl, &output_file, all);
	if (all->in == -1 || all->out == -1)
	{
		ft_putendl_fd("syntax error", STDERR_FILENO);
		return ;
	}
	do_command(cmdl, input_file, output_file, all);
}
