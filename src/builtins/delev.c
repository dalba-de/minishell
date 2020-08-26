#include "minishell.h"

void	delev(t_mini *all, char *key)
{
	int		len;
	int		cont1;
	int		cont2;
	char	***arr;

	len = count_line(all->ev);
	arr = malloc(sizeof(char *) * (len));
	cont1 = 0;
	cont2 = 0;
	while (all->ev[cont1 + cont2][0])
	{
		if (ft_strncmp(all->ev[cont1 + cont2][0], key, ft_strlen(all->ev[cont1 + cont2][0])) != 0)
		{
			arr[cont1] = malloc(sizeof(char *) * (2));
			arr[cont1][0] = ft_strdup(all->ev[cont1 + cont2][0]);
			arr[cont1][1] = ft_strdup(all->ev[cont1 + cont2][1]);
			cont1++;
		}
		else
			cont2++;
	}
	arr[cont1 + 1] = malloc(sizeof(char *) * (2));
	arr[cont1 + 1][0] = NULL;
	arr[cont1 + 1][1] = NULL;
	freecer(all->ev, len);
	all->ev = arr;
}