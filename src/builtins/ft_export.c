#include "minishell.h"

int		ft_formatev(t_mini *all, int arg)
{
	int		cont;
	int		flag;
	char	c;

	flag = 0;
	cont = 0;
	while ((c = all->my_argv[arg][cont]) != '\0')
	{
		if (c == '=')
			flag = 1;
		if ((cont == 0 && !(ft_isalpha(c) || c == '_')) || c == '"' ||
			c == '\'' || (flag == 0 && c == ' '))
			return (1);
		cont++;
	}
	return (0);
}

void print_error_export(t_mini *all, int arg)
{
	ft_putstr_fd("-bash: export: `", 1);
	ft_putstr_fd(all->my_argv[arg], 1);
	ft_putendl_fd("´':not a valid identifier", 1);
}

void	ft_export(t_mini *all)
{
	int		cont;
	char	*arr1;
	char	*arr2;

	cont = 1;
	while (all->my_argv[cont])
	{
		
		if (ft_formatev(all, cont))
		{
			print_error_export(all, cont);
			cont++;
			continue;
		}
		if (!search_key_ev(all->ev, arr1 = ft_strcdup(all->my_argv[cont], '=')))
		{
			addev(all, arr1, arr2 = ft_strcdupinv(all->my_argv[cont], '='));
			free(arr2);
		}
		free(arr1);
		cont++;
	}
}