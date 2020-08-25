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


char	*ft_strcdup(const char *s1, char c)
{
	int		cont;
	char	*arr;
	int	len;

	len = 0;
	while (s1[len] != '\0' && s1[len] != c)
	{
		len++;
	}
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		arr[cont] = s1[cont];
		cont++;
	}
	arr[cont] = '\0';
	return (arr);
}

char	*ft_strcdupinv(const char *s1, char c)
{
	int		cont;
	int		cont2;
	char	*arr;
	int		len;

	cont = 0;
	while (s1[cont] != c)
	{
		if (s1[cont] == '\0')
			return (NULL);
		cont++;
	}
	cont++;
	len = 0;
	while (s1[cont + len] != '\0')
		len++;
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cont2 = 0;
	while (cont2 < len)
	{
		arr[cont2] = s1[cont + cont2];
		cont2++;
	}
	arr[cont2] = '\0';
	return (arr);
}

int		count_line(char **envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
}

char	***loadev(char **envp)
{
	int		lenline;
	char	***arr;
	int		cont;
	int		cont2;

	lenline = count_line(envp);
	arr = malloc(sizeof(char *) * (lenline + 1));
	cont = 0;
	while (cont < lenline)
	{
		arr[cont] = malloc(sizeof(char *) * (2));
		cont2 = 0;
		while (cont2 < 2)
		{
			arr[cont][cont2] = (cont2 == 0) ? ft_strcdup(envp[cont], '=') : ft_strcdupinv(envp[cont], '=');
			cont2++;
		}
		cont++;
	}
	return(arr);
}
int 	main(int argc, char **argv, char **envp)
{
	char 	*line;
	t_mini	all;

	(void)envp;
	(void)argc;
	(void)argv;
	all.ev = loadev(envp);
	ft_putstr_fd(all.ev[0][1], 1);
	write(1, "\n", 1);
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
		i = 0;
		while (envp[i] != NULL)
		{
			ft_putendl_fd(envp[i], 1);
			i++;
		}
	}
	return (0);
}