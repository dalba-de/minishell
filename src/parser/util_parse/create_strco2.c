/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strco2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:12:57 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:48:56 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*parse_dollar(char *s, int *cont, t_mini *all)
{
	char	*key;
	char	*dollar;
	int		start;
	int		len;

	(*cont)++;
	start = *cont;
	len = 0;
	if (s[*cont] == '?')
		return (ft_itoa(all->exit_status));
	while (s[*cont] && s[*cont] != '$' && s[*cont] != ' ' && s[*cont] != '"')
	{
		(*cont)++;
		len++;
	}
	key = ft_substr(s, start, len);
	dollar = search_key_ev(all->ev, key);
	free(key);
	(*cont)--;
	return (dollar);
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

char	*ft_charjoin(char const *s1, char const s2)
{
	char	*concat;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	concat = malloc((ft_strlen(s1) + (2 * sizeof(char))));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	concat[i] = s2;
	i++;
	concat[i] = '\0';
	return (concat);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	char	*arr;
	char	*dollar;

	(*cont)++;
	str = ft_strdup("");
	while (all->strl[*cont] && all->strl[*cont] != '"')
	{
		if (all->strl[*cont] == '$')
		{
			dollar = parse_dollar(all->strl, cont, all);
			if (dollar)
			{
				arr = ft_strjoin(str, dollar);
				free(str);
			}
			else
				arr = str;
			free(dollar);
			str = arr;
		}
		else
		{
			arr = ft_charjoin(str, all->strl[*cont]);
			free(str);
			str = arr;
		}
		(*cont)++;
	}
	all->strl[*cont] == '"' ? ((*cont)++) : 0;
	return (str);
}
