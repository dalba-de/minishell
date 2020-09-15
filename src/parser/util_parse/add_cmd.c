/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:13:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:25 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	***add_cmdtcmdl(char **cmd, char ***cmdl)
{
	char	***result;
	int		cont;

	if (!(result = malloc(sizeof(char ***) * (ft_cmdlen(cmdl) + 2))))
		exit(1);
	cont = 0;
	while (cmdl != NULL && cmdl[cont])
	{
		result[cont] = cmdl[cont];
		cont++;
	}
	result[cont] = cmd;
	result[cont + 1] = NULL;
	cmdl != NULL ? (free(cmdl)) : (0);
	return (result);
}

char	**add_argtcmd(char *arg, char **cmd)
{
	char	**result;
	int		cont;

	if (!(result = malloc(sizeof(char **) * (ft_arglen(cmd) + 2))))
		exit(1);
	cont = 0;
	while (cmd != NULL && cmd[cont])
	{
		result[cont] = cmd[cont];
		cont++;
	}
	result[cont] = arg;
	result[cont + 1] = NULL;
	cmd != NULL ? (free(cmd)) : (0);
	return (result);
}

char	*add_strtarg(char *str, char *arg)
{
	char	*result;

	if (arg == NULL)
		return (str);
	if (!(result = ft_strjoin(arg, str)))
		exit(EXIT_FAILURE);
	free(str);
	free(arg);
	return (result);
}
