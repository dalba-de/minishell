/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:20:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/30 21:26:21 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_formatev(int arg, char **cmdl)
{
	int		cont;
	int		flag;
	char	c;

	flag = 0;
	cont = 0;
	while ((c = cmdl[arg][cont]) != '\0')
	{
		if (c == '=')
			flag = 1;
		if ((cont == 0 && !(ft_isalpha(c) || c == '_')) || c == '"' ||
			c == '\'' || (flag == 0 && c == ' '))
			return (1);
		cont++;
	}
	return (0);
}

void	print_error_export(t_mini *all, int arg)
{
	ft_putstr_fd("-bash: export: `", 1);
	ft_putstr_fd(all->my_argv[arg], 1);
	ft_putendl_fd("´':not a valid identifier", 1);
	all->exit_status = 1;
}

void	sort_env(t_mini *all)
{
	char	*cmdl[4];
	int		i;

	cmdl[0] = ft_strdup("env");
	cmdl[1] = ft_strdup("|");
	cmdl[2] = ft_strdup("sort");
	cmdl[3] = NULL;
	all->pipe_count = 1;
	parse_pipes(cmdl, all);
	i = 0;
	while (i < 3)
		free(cmdl[i++]);
}

void	ft_export(t_mini *all, char **cmdl)
{
	int		cont;
	char	*key;
	char	*value;
	char	*valuenew;

	cont = 1;
	if (cmdl[1] == NULL)
		return (sort_env(all));
	while (cmdl[cont])
	{
		if (ft_formatev(cont, cmdl))
		{
			print_error_export(all, cont);
			cont++;
			continue;
		}
		if ((value = search_key_ev(all->ev, key = ft_strcdup(cmdl[cont], '='))) != NULL)
			delev(all, key);
		addev(all, key, valuenew = ft_strcdupinv(cmdl[cont], '='));
		value != NULL ? (free(value)) : (0);
		valuenew != NULL ? (free(valuenew)) : (0);
		key != NULL ? (free(key)) : (0);
		all->exit_status = 0;
		cont++;
	}
}
