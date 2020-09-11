/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:45:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 12:53:28 by dalba-de         ###   ########.fr       */
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
	ft_bzero(all->my_argv, 100);
	all->ev = loadev(envp);
	all->exit_status = 0;
	all->piping = 0;
	get_path_string(all->ev, all->path_str);
	insert_path_str_to_search(all->path_str, all);
}

int		main(int argc, char **argv, char **envp)
{
	char	*line;
	t_mini	all;
	int		i;
	char	***cmdl;

	(void)argc;
	(void)argv;
	signal(SIGINT, handle_signal);
	init(&all, envp);
	while (1)
	{
		all.start = 0;
		ft_putstr_fd("\033[31mMinishell>> \033[0m", 1);
		get_next_line(STDIN_FILENO, &line);
		all.strl = line;
		cmdl = parse_cmdlist(&all);
		check_pipes(line, &all);
		i = 0;
		while (all.lines[i] != NULL)
		{
			fill_argv(all.lines[i++], &all);
			if (all.my_argv[0] && !all.piping)
				try_exec(&all);
			all.piping = 0;
		}
		free(line);
	}
	return (0);
}
