/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:02:51 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/20 19:37:15 by dalba-de         ###   ########.fr       */
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
