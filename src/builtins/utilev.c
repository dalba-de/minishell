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
		//free(ev[cont]); Porque freezeas dos veces el mismo punto?
		cont++;
	}
	free(ev);
	ev = NULL;
}

int		count_line(char ***envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
}