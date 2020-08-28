/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:18:46 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 19:52:27 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_cmds(char **list_cmds)
{
	list_cmds[0] = "invalid";
	list_cmds[ECHO] = "echo";
	list_cmds[CD] = "cd";
	list_cmds[PWD] = "pwd";
	list_cmds[EXPORT] = "export";
	list_cmds[UNSET] = "unset";
	list_cmds[ENV] = "env";
	list_cmds[EXIT] = "exit";
	list_cmds[HELP] = "help";
}

int		check_own_cmd(char *cmd)
{
	char	*list_cmds[9];
	int		i;

	i = 0;
	fill_cmds(list_cmds);
	while (i < 9)
	{
		if (ft_strncmp(cmd, list_cmds[i], ft_strlen(cmd)) == 0)
			return (i);
		i++;
	}
	return (0);
}
