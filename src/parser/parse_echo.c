/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 19:46:26 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 20:02:50 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_no_quotes(t_mini *all, char *ret, int index, int *i)
{
	int count;
	int	len;

	len = ft_strlen(ret);
	count = *i;
	while (ret[count++] == ' ')
		(*i)++;
	count = *i;
	while (ret[count] != ' ' && count <= len)
		count++;
	all->my_argv[index] = malloc(sizeof(char *) * count + 1);
	count = 0;
	while (ret[*i] != ' ' && count <= len)
	{
		all->my_argv[index][count] = ret[*i];
		(*i)++;
		count++;
	}
	all->my_argv[index][count] = '\0';
	if (ret[*i] == ' ')
		(*i)++;
}

void	parse_single_quotes(t_mini *all, char *ret, int index, int *i)
{
	int count;

	count = *i;
	while (ret[count] != '\'')
		count++;
	all->my_argv[index] = malloc(sizeof(char *) * count + 1);
	count = 0;
	while (ret[*i] != '\'')
	{
		all->my_argv[index][count] = ret[*i];
		(*i)++;
		count++;
	}
	all->my_argv[index][count] = '\0';
	(*i)++;
}

void	parse_double_quotes(t_mini *all, char *ret, int index, int *i)
{
	int count;

	count = *i;
	while (ret[count] != '\"')
		count++;
	all->my_argv[index] = malloc(sizeof(char *) * count + 1);
	count = 0;
	while (ret[*i] != '\"')
	{
		all->my_argv[index][count] = ret[*i];
		(*i)++;
		count++;
	}
	all->my_argv[index][count] = '\0';
	(*i)++;
}

void	parse_echo_argv(t_mini *all, char *ret, int index)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\"')
		{
			i++;
			parse_double_quotes(all, ret, index, &i);
		}
		else if (ret[i] == '\'')
		{
			i++;
			parse_single_quotes(all, ret, index, &i);
		}
		else if (ret[i] == ' ')
		{
			i++;
			index--;
		}
		else
			parse_no_quotes(all, ret, index, &i);
		index++;
	}
	all->my_argv[index] = NULL;
}
