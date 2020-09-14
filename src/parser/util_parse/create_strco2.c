#include "minishell.h"

char	*parse_dollar(char *str, int start, t_mini *all)
{
	int		i;
	int		j;
	int		k;
	char	*dollar;
	char	*key;
	char	*ret;
	
	ret = malloc(sizeof(char *) * 1024);
	j = -1;
	while (++j < start)
		ret[j] = str[j];
	k = j;
	start++;
	j = start;
	i = 0;
	if (str[j] == '?')
	{
		dollar = ft_itoa(all->exit_status);
		ft_strncat(ret, dollar, ft_strlen(dollar));
		i = ft_strlen(dollar) + k + 1;
		while (str[j])
		{
			ret[i] = str[j];
			i++;
			j++;
		}	
		ret[i] = '\0';
		return (ret);
	}
	while (str[j] != '$' && str[j] != ' ' && str[j] != '\0')
	{
		i++;
		j++;
	}
	key = ft_substr(str, start, i);
	dollar = search_key_ev(all->ev, key);
	ft_strncat(ret, dollar, ft_strlen(dollar));
	i = ft_strlen(dollar) + k;
	while (str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}	
	ret[i] = '\0';
	return (ret);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	int		i;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '"');
	while (all->strl[*cont] && all->strl[*cont] != '"')
		(*cont)++;
	all->strl[*cont] == '"' ? ((*cont)++) : 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str = parse_dollar(str, i, all);
		i++;
	}
	return (str);
}
