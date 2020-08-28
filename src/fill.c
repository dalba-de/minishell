/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 19:48:40 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_quotes(char *ret)
{
	unsigned int		i;
	int		j;
	char	*aux;
	char	*original;
	int		flag;

	original = ret;
	i = 0;
	j = 0;
	flag = 0;
	aux = malloc(sizeof(char * ) * (ft_strlen(ret) + 1));
	while(ret[i])
	{
		if (ret[i] == '\'')
		{
			i++;
			while (ret[i] != '\'' && ret[i])
			{
				aux[j++] = ret[i++];
				if (i == ft_strlen(ret) && ret[i] != '\'')
					flag = 1;
			}	
		}
		else if (ret[i] == '\"')
		{
			i++;
			while (ret[i] != '\"' && ret[i])
			{
				aux[j++] = ret[i++];
				if (i == ft_strlen(ret) && ret[i] != '\"')
					flag = 1;
			}	
		}
		else
			aux[j++] = ret[i];
		i++;
	}
	aux[j] = '\0';
	if (flag)
		aux = original;
	return (aux);
}

void	fill_my_argv(t_mini *all, int index, char *ret)
{
	char *aux;

	all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
	aux = delete_quotes(ret);
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
	aux = delete_quotes(ret);
	ft_strncpy(all->my_argv[index], aux, ft_strlen(aux));
	ft_strncat(all->my_argv[index], "\0", 1);
	ft_bzero(ret, 100);
	if (ft_strncmp(all->my_argv[0], "echo", ft_strlen((all->my_argv[0]))) == 0)
		return (1);
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
			{
				ft_strcpy(ret, foo);
				parse_echo_argv(all, ret, 1);
				return ;
			}	
			index++;
			foo--;
		}
		else
			ft_strncat(ret, foo, 1);
		foo++;
	}
	fill_my_argv(all, index, ret);
}
