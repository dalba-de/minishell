/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_strstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:13:14 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:14 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		dollar_lenght(t_mini *all, int i, char **dollar)
{
	int		cont;
	char	*key;
	int		start;

	cont = 0;
	i++;
	start = i;
	while (all->strl[i] != '\0' && all->strl[i] != '$'
	&& !is_final_arg(all->strl[i]))
	{
		i++;
		cont++;
	}
	key = ft_substr(all->strl, start, cont);
	*dollar = search_key_ev(all->ev, key);
	cont++;
	return (cont);
}

char	*join_dollar(char *str1, char *str2)
{
	char	*arr;

	arr = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (arr);
}

char	*create_dollar(t_mini *all, int *cont, int cont2)
{
	char	*dollar;
	char	*str;

	if (all->strl[(*cont) + cont2 + 1] == '?')
	{
		str = ft_substr(all->strl, *cont, cont2);
		cont2 += 2;
		dollar = ft_itoa(all->exit_status);
		str = join_dollar(str, dollar);
		*cont = cont2 + *cont;
		return (str);
	}
	else
	{
		str = ft_substr(all->strl, *cont, cont2);
		cont2 += dollar_lenght(all, ((*cont) + cont2), &dollar);
		str = join_dollar(str, dollar);
		while (all->strl[cont2 + *cont] == ' ' && str[0] == '\0')
			(*cont)++;
		*cont = cont2 + *cont;
		return (str);
	}
}

char	*create_strtstr(t_mini *all, int *cont, int *flag)
{
	char	*str;
	int		cont2;

	cont2 = 0;
	if (is_pipe(all->strl[(*cont)]))
	{
		flag[0] = 0;
		all->strl[(*cont)] == '>' && all->strl[(*cont) + 1] == '>'
			? (cont2 = cont2 + 2) : (cont2++);
	}
	else
	{
		while (all->strl[(*cont) + cont2]
			&& !is_final_arg(all->strl[(*cont) + cont2]))
		{
			if (all->strl[(*cont) + cont2] == '$')
				return (create_dollar(all, cont, cont2));
			cont2++;
		}
		is_pipe(all->strl[(*cont) + cont2]) ? (flag[0] = 0) : (0);
	}
	str = ft_substr(all->strl, *cont, cont2);
	*cont = cont2 + *cont;
	return (str);
}
