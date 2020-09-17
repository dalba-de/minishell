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

char	*parse_dollar(t_mini *all, int *cont)
{
	char	*key;
	char	*dollar;
	int		len;

	(*cont)++;
	if (all->strl[*cont] == '?')
		return (ft_itoa(all->exit_status));
	len = 0;
	while (ft_isalnum(all->strl[*cont + len]) || all->strl[*cont + len] == '_')
		len++;
	key = ft_substr(all->strl, *cont, len);
	dollar = search_key_ev(all->ev, key);
	free(key);
	(*cont) = ((*cont) + len - 1);
	return (dollar);
}

char	*ft_charjoin(char const *s1, char const s2)
{
	char	*arr;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if (!(arr = malloc(sizeof(char *) * (ft_strlen(s1) + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = s2;
	arr[i + 1] = '\0';
	return (arr);
}

char	*add_strtstr(char *str1, char *str2)
{
	char	*result;

	if (str2 == NULL)
		return (str1);
	if (!(result = ft_strjoin(str1, str2)))
		exit(EXIT_FAILURE);
	free(str1);
	free(str2);
	return (result);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	char	*arr;

	(*cont)++;
	str = ft_strdup("");
	while (all->strl[*cont] && all->strl[*cont] != '"')
	{
		if (all->strl[*cont] == '$')
			str = add_strtstr(str, parse_dollar(all, cont));
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
