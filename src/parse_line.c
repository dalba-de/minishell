/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:43:55 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/26 12:44:57 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	separate_lines(t_mini *all, int lenght, int total, char *line)
{
	int		finish;
	char	**aux;
	int		k;

	k = 0;
	finish = lenght - all->start;
	aux = malloc(sizeof(char *) * (total + 1));
	while (k < total)
	{
		aux[k] = all->lines[k];
		k++;
	}
	aux[total] = ft_substr(line, all->start, finish);
	if (total > 0)
		free(all->lines);
	all->start = lenght + 1;
	all->lines = aux;
	all->lines[total + 1] = '\0';
}

void	check_pipes(char *line, t_mini *all)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == PIPE || line[i] == COMMA || line[i] == '\0')
		{
			separate_lines(all, i, ret, line);
			ret++;
		}
		i++;
	}
	separate_lines(all, i, ret, line);
}
