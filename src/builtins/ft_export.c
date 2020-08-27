#include "minishell.h"

void	ft_export(t_mini *all)
{
	char	*arr1;
	char	*arr2;

	if (!search_key_ev(all->ev, arr1 = ft_strcdup(all->my_argv[1], '=')))
	{
		addev(all, arr1, arr2 = ft_strcdupinv(all->my_argv[1], '='));
		free(arr2);
	}
	free(arr1);
}