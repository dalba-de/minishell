/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:57:10 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/26 14:06:07 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_path_string(char ***tmp_envp, char *bin_path)
{
	int count;

	count = 0;
	while (tmp_envp[count][0] != NULL)
	{
		if (ft_strncmp(tmp_envp[count][0], "PATH", 4) == 0)
		{
			ft_strcpy(bin_path, tmp_envp[count][1]);
			break;
		}
		count++;
	}
}

void insert_path_str_to_search(char *path_str, t_mini *all) 
{
	int index=0;
	char *tmp = path_str;
	char ret[100];

	while(*tmp != '\0') {
		if(*tmp == ':') {
			ft_strncat(ret, "/", 1);
			all->search_path[index] = (char *) malloc(sizeof(char) * (ft_strlen(ret) + 1));
			ft_strncat(all->search_path[index], ret, ft_strlen(ret));
			ft_strncat(all->search_path[index], "\0", 1);
			index++;
			ft_bzero(ret, 100);
		} else {
			ft_strncat(ret, tmp, 1);
		}
		tmp++;
	}
	index = 0;
	while (all->search_path[index] != NULL)
	{
		ft_putendl_fd(all->search_path[index], 1);
		index++;
	}
}
