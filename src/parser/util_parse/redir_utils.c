/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 00:18:59 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/05 01:13:41 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_file(char *tmp)
{
	int fd;

	if ((fd = open(tmp, O_RDONLY)) == -1)
	{
		fd = open(tmp, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
		close(fd);
	}
	return (tmp);
}

int		find_redir(t_mini *all, char **tmp, int i, char **file)
{
	int j;

	all->double_redir = 0;
	tmp[i][1] == '>' ? all->double_redir = 1 : 0;
	if (tmp[i + 1] != NULL)
		*file = check_file(tmp[i + 1]);
	else
		return (-1);
	j = i;
	while (tmp[j - 1] != NULL)
	{
		tmp[j] = tmp[j + 2];
		j++;
	}
	return (0);
}

int		check_in(char **tmp, char **input_file, t_mini *all)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == '<')
		{
			if (find_redir(all, tmp, i, input_file))
				return (-1);
			flag = 1;
			continue;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}

int		check_out(char **tmp, char **output_file, t_mini *all)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i][0] == '>')
		{
			if (find_redir(all, tmp, i, output_file))
				return (-1);
			flag = 1;
			continue;
		}
		i++;
	}
	if (flag)
		return (1);
	return (0);
}
