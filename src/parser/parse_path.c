/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:57:10 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/01 21:34:00 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_path_string(char ***tmp_envp, char *bin_path, t_mini *all)
{
	int count;

	all->free_signal = 0;
	count = 0;
	while (tmp_envp[count] != NULL)
	{
		if (ft_strncmp(tmp_envp[count][0], "PATH", 4) == 0)
		{
			ft_strcpy(bin_path, tmp_envp[count][1]);
			break ;
		}
		count++;
	}
}

void	insert_path_str_to_search(char *path_str, t_mini *all)
{
	int		index;
	char	ret[100];

	ft_bzero(ret, 100);
	index = 0;
	while (*path_str != '\0')
	{
		if (*path_str == ':')
		{
			ft_strncat(ret, "/\0", 2);
			all->search_path[index] = ft_strdup(ret);
			index++;
			all->free_signal++;
			ft_bzero(ret, 100);
		}
		else
			ft_strncat(ret, path_str, 1);
		path_str++;
	}
	ft_strncat(ret, "/\0", 2);
	all->search_path[index] = ft_strdup(ret);
	index++;
	all->free_signal++;
	all->search_path[index] = NULL;
}
