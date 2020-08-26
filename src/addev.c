#include "minishell.h"

void	freecer(char ***ev, int len)
{
	int	cont;

	cont = 0;
	while (cont < len)
	{
		free(ev[cont][0]);
		free(ev[cont][1]);
		cont++;
	}
	cont = 0;
	while (cont < len)
	{
		free(ev[cont]);
		free(ev[cont]);
		cont++;
	}
	free(ev);
	ev = NULL;
}

static int		count_line(char ***envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
}

void	addev(t_mini *all, char *key, char *value)
{
	int		len;
	int		cont;
	char	***arr;

	len = count_line(all->ev);
	arr = malloc(sizeof(char *) * (len + 2));
	cont = 0;
	while (cont < len)
	{
		arr[cont] = malloc(sizeof(char *) * (2));
		arr[cont][0] = ft_strdup(all->ev[cont][0]);
		arr[cont][1] = ft_strdup(all->ev[cont][1]);
		cont++;
	}
	arr[cont] = malloc(sizeof(char *) * (2));
	arr[cont][0] = ft_strdup(key);
	arr[cont][1] = ft_strdup(value);
	arr[cont + 1] = malloc(sizeof(char *) * (2));
	arr[cont + 1][0] = NULL;
	arr[cont + 1][1] = NULL;
	freecer(all->ev, len + 2);
	all->ev = arr;
}