/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:02:51 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/03 01:52:34 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_screen(char **envp)
{
	char	*cmdl[2];
	pid_t	pid;

	cmdl[0] = ft_strdup("clear");
	cmdl[1] = NULL;
	if ((pid = fork()) == 0)
		execve("/usr/bin/clear", cmdl, envp);
	else
		wait(NULL);
	free(cmdl[0]);
}

void	magic(char **envp)
{
	clear_screen(envp);
	ft_putendl_fd("", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	████  ████╗██╗████   ██╗██╗███████╗██╗  ██╗███████╗██╗    ██╗    ", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	██╔████═██║██║██╔██  ██║██║██╔════╝██║  ██║██╔════╝██║    ██║    ", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	██║ ██  ██║██║██║ ██ ██║██║███████╗███████║█████╗  ██║    ██║    ", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	██║     ██║██║██║  ████║██║╚════██║██║  ██║██╔══╝  ██║    ██║    ", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	██║     ██║██║██║   ███║██║███████║██║  ██║███████╗██████╗██████╗", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\
	╚═╝     ╚═╝╚═╝╚═╝   ╚══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚═════╝╚═════╝", 1);
	ft_putendl_fd("\033[1;36m\t\t\t\t\t\t\t\t\t\tBy agarrido && dalba-de", 1);
	ft_putendl_fd("", 1);
}

void	open_help(t_mini *all)
{
	magic(all->original_ev);
	ft_putendl_fd("\t\t\t\t\t\t\t\033[1;36m***WELCOME TO MY SHELL HELP***", 1);
	ft_putendl_fd("\033[1;32m\n\t\t\t\t\t\
	Copyright @ Alberto Garrido && David Alba", 1);
	ft_putendl_fd("\t\t\t\t\t\tList of Builtins supported:", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* echo", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* cd", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* pwd", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* export", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* unset", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* env", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* exit", 1);
	ft_putendl_fd("\n\t\t\t\t\t\
	List of Commands supported:", 1);
	ft_putendl_fd("\t\t\t\t\t\t\
	* general commands available in UNIX shell", 1);
	ft_putendl_fd("\t\t\t\t\t\t\t* pipe and redirections", 1);
	ft_putendl_fd("\n\t\t\t\t\t\
	\t\033[1;31mWARNING! Use at your own risk\033[0m", 1);
	ft_putendl_fd("", 1);
}
