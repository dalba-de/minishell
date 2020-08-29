#include "minishell.h"

void	ft_echo(t_mini *all)
{
	int		cont;
	char	*arr;
	int		nflag;

	nflag = 0;
	cont = 1;
	while (all->my_argv[cont])
	{
		if (all->my_argv[cont][0] == '$' && all->my_argv[cont][1] == '?')
			ft_putnbr_fd(all->exit_status, 1);
		else if (all->my_argv[cont][0] == '$')
		{
			if ((arr = search_key_ev(all->ev, ++all->my_argv[cont])) != NULL)
			{
				if (cont > 1)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd(arr, 1);
			}
		}
		else if(all->my_argv[cont][0] == '-' && all->my_argv[cont][1] == 'n' && nflag == 0)
		{
			nflag = 1;
			cont++;
			continue ;
		}
		else
		{
			if (cont > 1 && nflag != 1)
			{
				nflag = 2;
				ft_putchar_fd(' ', 1);
			}	
			ft_putstr_fd(all->my_argv[cont], 1);
			nflag = 2;
		}
		cont++;
	}
	if (ft_strncmp(all->my_argv[1], "-n", 2) != 0)
		ft_putchar_fd('\n', 1);
	all->exit_status = 0;
}
