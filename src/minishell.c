/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:45:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/05 01:36:09 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2d(char **str)
{
	int i;
	int	len;

	len = count_double_str(str);
	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_3d(char ***str)
{
	int len;
	int	i;

	len = count_triple_str(str);
	i = 0;
	while (i < len)
	{
		free_2d(str[i]);
		i++;
	}
	free(str);
}

void	handle_signal(int signo)
{
	(void)signo;
	if (!g_signal)
		ft_putstr_fd("\n\033[1;31mMinishell>> \033[0m", 1);
}

void	init(t_mini *all, char **envp)
{
	ft_bzero(all, sizeof(t_mini));
	all->ev = loadev(envp);
	all->exit_status = 0;
	all->piping = 0;
	all->double_redir = 0;
	all->path_str = NULL;
	all->original_ev = envp;
	g_signal = 0;
	magic(envp);
}

void		minishell(char *envp[])
{
	char	*line;
	t_mini	all;
	int		i;
	char	***cmdl;

	signal(SIGINT, handle_signal);
	init(&all, envp);
	while (1)
	{
		ft_putstr_fd("\033[1;31mMinishell>> \033[0m", STDERR_FILENO);
		if (get_next_line(STDIN_FILENO, &line) < 1)
			break ;
		all.strl = line;
		if ((cmdl = parse_cmdlist(&all)) == NULL)
			continue ;
		i = 0;
		while (cmdl[i] != NULL)
			bridge(cmdl[i++], &all);
		free(line);
		free_3d(cmdl);
	}
}
