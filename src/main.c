#include "minishell.h"

void	separate_lines(t_mini *all, int lenght, int total, char *line)
{
	int				finish;
	char			**aux;
	int				k;

	k = 0;
	finish = lenght - all->start;
	aux = malloc(sizeof(char *) * (total + 1));
	while (k < total)
	{
		aux[k] = all->lines[k];
		k++;
	}
	aux[total] = ft_substr(line, all->start, finish);
	if (total > 0)
		free(all->lines);
	all->start = lenght + 1;
	all->lines = aux;
	all->lines[total + 1] = '\0';
}

void	check_pipes(char *line, t_mini *all)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == PIPE || line[i] == COMMA || line[i] == '\0')
		{
			separate_lines(all, i, ret, line);
			ret++;
		}	
		i++;
	}
	separate_lines(all, i, ret, line);
}

int 	main(int argc, char **argv, char **envp)
{
	char 	*line;
	t_mini	all;

	(void)envp;
	(void)argc;
	(void)argv;
	while (1)
	{
		ft_bzero(&all, sizeof(all));
		ft_putstr_fd("\033[31mMinishell>> \033[0m", 1);
		get_next_line(STDIN_FILENO, &line);
		check_pipes(line, &all);
		int i = 0;
		while (all.lines[i] != NULL)
		{
			ft_putendl_fd(all.lines[i], 1);
			i++;
		}
	}
	return (0);
}