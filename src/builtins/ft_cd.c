/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 12:44:40 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/30 00:15:33 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_value(t_mini *all)
{
	char	path[1024];
	int		i;
	int		j;
	
	i = 1;
	j = 0;
	while (all->my_argv[1][i] != '\0')
	{
		path[j] = all->my_argv[1][i];
		i++;
		j++;
	}
	path[j] = '\0';
	all->my_argv[1] = search_key_ev(all->ev, path);
}

void	ft_cd(t_mini *all)
{
	char	oldvalue[1024];
	char	value[1024];

	getcwd(oldvalue, sizeof(oldvalue));
	if (all->my_argv[1] == NULL)
		all->my_argv[1] = search_key_ev(all->ev, "HOME");
	else if (all->my_argv[1][0] == '$')
		change_value(all);
	if (chdir(all->my_argv[1]) == -1)
	{
		ft_putstr_fd("cd : ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(all->my_argv[1], STDERR_FILENO);
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
