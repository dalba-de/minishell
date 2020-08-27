#include "minishell.h"

void	ft_echo(t_mini *all)
{
	int		cont;
	char	*arr;

	cont = 1;
	while (all->my_argv[cont])
	{
		if (all->my_argv[cont][0] == '$')
		{
			if ((arr = search_key_ev(all->ev, ++all->my_argv[cont])) != NULL)
			{
				if (cont > 1)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd(arr, 1);
			}
		}
		else
		{
			if (cont > 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(all->my_argv[cont], 1);
		}
		cont++;
	}
	ft_putchar_fd('\n', 1);
}