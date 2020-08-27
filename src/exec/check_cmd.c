/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:18:46 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/27 12:37:37 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_cmds(char **list_cmds)
{
	list_cmds[0] = "echo";
	list_cmds[1] = "cd";
	list_cmds[2] = "pwd";
	list_cmds[3] = "export";
	list_cmds[4] = "unset";
	list_cmds[5] = "env";
	list_cmds[6] = "exit";
	list_cmds[7] = "help";
}

int		check_own_cmd(char *cmd)
{
	char	*list_cmds[8];
	int		i;

	i = 0;
	fill_cmds(list_cmds);
	while (i < 8)
	{
		if (ft_strncmp(cmd, list_cmds[i], ft_strlen(cmd)) == 0)
			return (i);
		i++;
	}
	return (0);
}
