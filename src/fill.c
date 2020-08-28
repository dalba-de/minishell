/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 13:34:06 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_no_quotes(t_mini *all, char *ret, int index, int *i)
{
	int count;
	int	len;

	len = ft_strlen(ret);
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
			index++;
		}
		else if (ret[i] == '\'')
		{
			i++;
			parse_single_quotes(all, ret, index, &i);
			index++;
		}
		else
		{
			parse_no_quotes(all, ret, index, &i);
			index++;
		}
	}
	all->my_argv[index] = NULL;
}

void	fill_my_argv(t_mini *all, int index, char *ret)
{
	char *aux;

	all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
	if (index == 0 || ft_strncmp(all->my_argv[0],
	"echo", ft_strlen((all->my_argv[0]))) != 0)
		aux = ft_strtrim(ret, "\"\'");
	else
	{
		parse_echo_argv(all, ret, 1);
		return ;
	}
	all->my_argv[index] = ft_strncpy(all->my_argv[index], aux, ft_strlen(aux));
	all->my_argv[index] = ft_strncat(all->my_argv[index], "\0", 1);
	index++;
	all->my_argv[index] = '\0';
}

int		fill_gap(t_mini *all, char *ret, int index)
{
	char *aux;

	if (all->my_argv[index] == NULL)
		all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
	else
		ft_bzero(all->my_argv[index], strlen(all->my_argv[index]));
	if (index == 0 || ft_strncmp(all->my_argv[0],
	"echo", ft_strlen((all->my_argv[0]))) != 0)
		aux = ft_strtrim(ret, "\"\'");
	else
		return (1);
	ft_strncpy(all->my_argv[index], aux, ft_strlen(aux));
	ft_strncat(all->my_argv[index], "\0", 1);
	ft_bzero(ret, 100);
	return (0);
}

void	fill_argv(char *tmp_argv, t_mini *all)
{
	char	*foo;
	int		index;
	char	ret[100];

	foo = tmp_argv;
	index = 0;
	ft_bzero(ret, 100);
	while (*foo != '\0')
	{
		if (index == 10)
			break ;
		if (*foo == ' ')
		{
			while (*foo == ' ')
				foo++;
			if (fill_gap(all, ret, index))
				ft_strncat(ret, " ", 1);
			index++;
			foo--;
		}
		else
			ft_strncat(ret, foo, 1);
		foo++;
	}
	fill_my_argv(all, index, ret);
}
