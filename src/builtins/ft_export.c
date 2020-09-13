/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:20:24 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/13 18:38:47 by dalba-de         ###   ########.fr       */
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

void	sort_env(t_mini *all, char **cmdl)
{
	cmdl[0] = ft_strdup("env");
	cmdl[1] = ft_strdup("|");
	cmdl[2] = ft_strdup("sort");
	cmdl[3] = NULL;
	parse_pipes(cmdl, all);
}

void	ft_export(t_mini *all, char **cmdl)
{
	int		cont;
	char	*arr1;
	char	*arr2;

	cont = 1;
	if (cmdl[1] == NULL)
		return (sort_env(all, cmdl));
	while (cmdl[cont])
	{
		if (ft_formatev(cont, cmdl))
		{
			print_error_export(all, cont);
			cont++;
			continue;
		}
		if (!search_key_ev(all->ev, arr1 = ft_strcdup(cmdl[cont], '=')))
		{
			addev(all, arr1, arr2 = ft_strcdupinv(cmdl[cont], '='));
			free(arr2);
			all->exit_status = 0;
		}
		free(arr1);
		cont++;
	}
}
