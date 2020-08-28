/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:45:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 13:10:33 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signo)
{
	(void)signo;
	ft_putstr_fd("\n\033[31mMinishell>> \033[0m", 1);
}

void	init(t_mini *all, char **envp)
{
	ft_bzero(all, sizeof(all));
	all->path_str = (char *)malloc(sizeof(char) * 256);
	all->env = envp;
	*all->my_argv = NULL;
	all->ev = loadev(envp);
	get_path_string(all->ev, all->path_str);
	insert_path_str_to_search(all->path_str, all);
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	t_mini	all;
	int		i;
	int		rd;

	(void)argc;
	(void)argv;
	signal(SIGINT, handle_signal);
	init(&all, envp);
	while (1)
	{
		all.start = 0;
		ft_putstr_fd("\033[31mMinishell>> \033[0m", 1);
		rd = get_next_line(STDIN_FILENO, &line);
		if (rd == 0)
			break ;
		check_pipes(line, &all);
		i = 0;
		while (all.lines[i] != NULL)
		{
			fill_argv(all.lines[i++], &all);
			try_exec(&all);
		}
	}
	return (0);
}
