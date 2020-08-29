/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:44:40 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 12:19:00 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_mini *all)
{
	char oldvalue[1024];
	char value[1024];

	getcwd(oldvalue, sizeof(oldvalue));
	if (chdir(all->my_argv[1]) == -1)
	{
		ft_putstr_fd("cd : ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(all->my_argv[1], STDERR_FILENO);
	}
	else
	{
		change_ev(all, "OLDPWD", oldvalue);
		getcwd(value, sizeof(value));
		change_ev(all, "PWD", value);
	}
}
