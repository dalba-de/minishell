#include "minishell.h"

void	ft_echo(t_mini *all, char **cmdl)
{
	/*int		cont;
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
	all->exit_status = 0;*/
	(void)cmdl;
	int i;
	int j;
	int	flagn;
	char *key;

	flagn = 0;
	i = 0;
	if (all->my_argv[1][0] == '-' && all->my_argv[1][1] == 'n' && all->my_argv[1][2] == ' ')
	{
		flagn = 1;
		all->my_argv[1] = &all->my_argv[1][3];
	}
	while (all->my_argv[1][i])
	{
		j = 0;
		if (all->my_argv[1][i] != '$' && all->my_argv[1][i] != ' ')
			ft_putchar_fd(all->my_argv[1][i], 1);
		else if (all->my_argv[1][i] == ' ')
		{
			ft_putchar_fd(' ', 1);
			while (all->my_argv[1][i] == ' ')
				i++;
			continue;
		}
		else
		{
			if (all->my_argv[1][i + 1] == '?')
			{
				ft_putnbr_fd(all->exit_status, 1);
				i++;
			}
			else
			{
				j = i + 1;
				while (all->my_argv[1][j] != ' ' && all->my_argv[1][j] != '\0' && all->my_argv[1][j] != '$')
					j++;
				j--;
				key = ft_substr(all->my_argv[1], i + 1, j);
				ft_putstr_fd(search_key_ev(all->ev, key), 1);
				i += j;
			}
		}
		i++;
	}
	if (!flagn)
		ft_putchar_fd('\n', 1);
	all->exit_status = 0;
}
