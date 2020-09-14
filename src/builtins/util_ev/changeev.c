/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changeev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 13:07:06 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 18:35:05 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_ev(t_mini *all, char *key, char *value)
{
	int i;

	i = 0;
	while (all->ev[i])
	{
		if (ft_strncmp(all->ev[i][0], key, ft_strlen(all->ev[i][0])) == 0)
		{
			free(all->ev[i][1]);
			all->ev[i][1] = ft_strdup(value);
		}
		i++;
	}
}
