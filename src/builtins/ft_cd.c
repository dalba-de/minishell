/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:44:40 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 17:29:01 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_mini *all, char **cmdl)
{
	char	oldvalue[1024];
	char	value[1024];

	ft_bzero(oldvalue, 1024);
	ft_bzero(value, 1024);
	getcwd(oldvalue, sizeof(oldvalue));
	if (cmdl[1] == NULL)
		cmdl[1] = search_key_ev(all->ev, "HOME");
	if (chdir(cmdl[1]) == -1)
	{
		ft_putstr_fd("cd : ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(cmdl[1], STDERR_FILENO);
		all->exit_status = 1;
	}
	else
	{
		change_ev(all, "OLDPWD", oldvalue);
		getcwd(value, sizeof(value));
		change_ev(all, "PWD", value);
		all->exit_status = 0;
	}
}
