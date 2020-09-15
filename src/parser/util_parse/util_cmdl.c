/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_cmdl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:13:20 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/15 12:13:21 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_cmdlen(char ***cmdl)
{
	int	cont;

	if (cmdl == NULL)
		return (0);
	cont = 0;
	while (cmdl[cont])
		cont++;
	return (cont);
}

int		ft_arglen(char **cmd)
{
	int	cont;

	if (cmd == NULL)
		return (0);
	cont = 0;
	while (cmd[cont])
		cont++;
	return (cont);
}

int		is_pipe(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int		is_final_arg(char c)
{
	if (c == ' ' || c == ';' || c == '"' || c == '\'' || is_pipe(c))
		return (1);
	return (0);
}
