#include "minishell.h"

char	*parse_question(t_mini *all, )
{

}


char	*parse_dollar(char *str, int *start, t_mini *all)
{
	int		i;
	int		j;
	int		k;
	char	*dollar;
	char	*key;
	char	*ret;
	char	*arr;
	char	*arr2;
	
	arr = ft_strcdup(str, '$');

	ret = malloc(sizeof(char *) * 1024);
	j = -1;
	while (++j < start)
		ret[j] = str[j];
	k = j;
	start++;
	j = start;
	i = 0;

	if (str[start + 1] == '?')
	{
		dollar = ft_itoa(all->exit_status);
		arr2 = ft_strjoin(arr, dollar);
		free(dollar);
		free(arr);
		arr = arr2;
		return (arr);
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

char	*ft_strdupi(char *s, int i)
{
	char	*arr;
	int		cont;
	
	arr = malloc((i + 1));
	cont = 0;
	while (s[cont] && cont < i)
	{
		arr[cont] = s[cont];
		cont++;
	}
	arr[cont] = '\0';
	return (arr);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	char	*arr;
	char	*arr2;
	char	*arr3;
	int		i;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '"');
	while (all->strl[*cont] && all->strl[*cont] != '"')
		(*cont)++;
	all->strl[*cont] == '"' ? ((*cont)++) : 0;
	i = 0;
	arr = ft_strdup("");
	while (str[i])
	{
		if (str[i] == '$')
		{
			arr2 = ft_strjoin(arr, parse_dollar(&str[i], &i, all));
			free(arr);
			arr = arr2;
		}
		else
		{
			arr3 = ft_strdupi(&str[i], 1);
			arr2 = ft_strjoin(arr, arr3);
			free(arr);
			free(arr3);
			arr = arr2;
		}
		i++;
	}
	free(str);
	str = arr;
	return (str);
}


