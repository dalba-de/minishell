/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:19:36 by dalba-de          #+#    #+#             */
/*   Updated: 2020/10/01 21:27:18 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_path(t_mini *all)
{
	all->path_str = (char *)malloc(sizeof(char) * 256);
	get_path_string(all->ev, all->path_str, all);
	insert_path_str_to_search(all->path_str, all);
}

void	free_path(t_mini *all)
{
	int j;

	j = -1;
	free(all->cmd);
	free(all->path_str);
	while (++j < all->free_signal)
		free(all->search_path[j]);
}
