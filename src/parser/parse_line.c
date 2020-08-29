/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:43:55 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 12:30:44 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_gap(char *line, int start)
{
	while (line[start] == ' ' || line[start] == ';' || line[start] == '|')
		start++;
	return (start);
}

int		check_spaces(char *line, int lenght)
{
	while (line[lenght] == ' ')
		lenght--;
	return (lenght + 1);
}

void	separate_lines(t_mini *all, int lenght, int total, char *line)
{
	int		finish;
	char	**aux;
	int		k;

	if (all->pipe_flag)
		lenght = check_spaces(line, lenght - 1);
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
	all->start = check_gap(line, all->start);
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
		if (line[i] == COMMA || line[i] == '\0')
		{
			all->pipe_flag = 1;
			separate_lines(all, i, ret, line);
			ret++;
		}
		i++;
	}
	separate_lines(all, i, ret, line);
}
