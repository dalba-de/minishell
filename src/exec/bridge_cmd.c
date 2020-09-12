/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:31:35 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 01:11:23 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bridge_own_cmd(int index, t_mini *all, char **cmdl)
{
	if (index == ECHO)
		ft_echo(all, cmdl);
	else if (index == CD)
		ft_cd(all, cmdl);
	else if (index == PWD)
		ft_pwd(all, cmdl);
	else if (index == EXPORT)
		ft_export(all, cmdl);
	else if (index == UNSET)
		ft_unset(all, cmdl);
	else if (index == ENV)
		ft_env(all);
	else if (index == EXIT)
		ft_exit(all, cmdl);
	return (index);
}
