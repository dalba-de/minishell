/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:45:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/30 21:37:23 by dalba-de         ###   ########.fr       */
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
	ft_putstr_fd("\n\033[31mMinishell>> \033[0m", 1);
}

void	init(t_mini *all, char **envp, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	ft_bzero(all, sizeof(t_mini));
	all->path_str = (char *)malloc(sizeof(char) * 256);
	all->ev = loadev(envp);
	all->exit_status = 0;
	all->piping = 0;
	all->double_redir = 0;
	get_path_string(all->ev, all->path_str);
	insert_path_str_to_search(all->path_str, all);
	magic(envp);
}

int		main(int argc, char **argv, char *envp[])
{
	char	*line;
	t_mini	all;
	int		i;
	char	***cmdl;
	int		rd;

	signal(SIGINT, handle_signal);
	init(&all, envp, argv, argc);
	while (1)
	{
		ft_putstr_fd("\033[1;31mMinishell>> \033[0m", STDOUT_FILENO);
		rd = get_next_line(STDIN_FILENO, &line);
		if (rd == 0)
			break ;
		all.strl = line;
		cmdl = parse_cmdlist(&all);
		if (cmdl == NULL)
			continue ;
		i = 0;
		while (cmdl[i] != NULL)
			bridge(cmdl[i++], &all);
		free(line);
		free_3d(cmdl);
	}
	return (0);
}
