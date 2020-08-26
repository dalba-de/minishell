/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:45:11 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/26 13:58:11 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_mini	*all)
{
	ft_bzero(all, sizeof(all));
	all->path_str = (char *)malloc(sizeof(char) * 256);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_mini	all;

	(void)argc;
	(void)argv;
	init(&all);
	all.ev = loadev(envp);
	get_path_string(all.ev, all.path_str);
	insert_path_str_to_search(all.path_str, &all);
	while (1)
	{
		all.start = 0;
		ft_putstr_fd("\033[31mMinishell>> \033[0m", 1);
		get_next_line(STDIN_FILENO, &line);
		check_pipes(line, &all);
		/*int i = 0;
		while (all.ev[i][0] != NULL)
		{
			ft_putendl_fd(all.ev[i][0], 1);
			i++;
		}*/
	}
	return (0);
}
