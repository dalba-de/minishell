/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:06:58 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 01:15:49 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_mini *all, char **cmdl)
{
	char cwd[1024];

	if (cmdl[1] != NULL)
	{
		ft_putendl_fd("pwd: too many arguments", STDERR_FILENO);
		all->exit_status = 1;
		return ;
	}
	getcwd(cwd, sizeof(cwd));
	ft_putendl_fd(cwd, 1);
	all->exit_status = 0;
}
