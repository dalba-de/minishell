#include "minishell.h"

char	*create_strco1(t_mini *all, int *cont)
{
	char	*str;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '\'');
	while (all->strl[*cont] && all->strl[*cont] != '\'')
		(*cont)++;
	all->strl[*cont] == '\'' ? ((*cont)++) : 0;
	return (str);
}
