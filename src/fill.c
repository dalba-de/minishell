/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 20:21:10 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_my_argv(t_mini *all, int index, char *ret)
{
	char	*aux;
	int		i;

	i = 0;
	if (ret[i] != '\0')
	{
		all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
		aux = delete_quotes(ret);
		all->my_argv[index] = ft_strncpy(all->my_argv[index], aux, ft_strlen(aux));
		all->my_argv[index] = ft_strncat(all->my_argv[index], "\0", 1);
		index++;
		all->my_argv[index] = '\0';
	}
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
	ft_bzero(all->my_argv, 100);
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
