#include "minishell.h"

void	ft_export(t_mini *all)
{
	if (!search_key_ev(all->ev, all->my_argv[1]))
		addev(all, all->my_argv[1], all->my_argv[2]);
}