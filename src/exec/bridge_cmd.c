/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bridge_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:31:35 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/27 13:27:39 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bridge_own_cmd(int index, t_mini *all)
{
	if (index == ECHO)
		ft_echo(all);
	else if (index == CD)
		ft_cd(all);
	else if (index == PWD)
		ft_pwd();
	else if (index == EXPORT)
		ft_export(all);
	else if (index == UNSET)
		ft_unset(all);
	else if (index == ENV)
		ft_env(all);
	else if (index == EXIT)
		ft_exit(all);
}