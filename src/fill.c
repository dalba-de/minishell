/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:14:53 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/26 18:27:52 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_gap(t_mini *all, int ret, int index)
{
	if (all->my_argv[index] == NULL)
		all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
	else
		ft_bzero(all->my_argv[index], strlen(all->my_argv[index]));
	ft_strncpy(all->my_argv[index], ret, ft_strlen(ret));
	ft_strncat(all->my_argv[index], "\0", 1);
	ft_bzero(ret, 100);
	index++;
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
			fill_gap(all, ret, index);
		else
			ft_strncat(ret, foo, 1);
		foo++;
	}
	all->my_argv[index] = (char *)malloc(sizeof(char) * ft_strlen(ret) + 1);
	ft_strncpy(all->my_argv[index], ret, ft_strlen(ret));
	ft_strncat(all->my_argv[index], "\0", 1);
}
