/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:33:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/11 17:45:41 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_triple_line(char ***env)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static int	count_line_envp(char **envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
}

char		**env_to_double(char ***env)
{
	int		i;
	char	**aux;
	char	*aux1;
	int		lines;

	lines = count_triple_line(env);
	aux = malloc (sizeof(char **) * (lines + 1));
	i = 0;
	while (env[i])
	{
		aux1 = ft_strjoin(env[i][0], "=");
		aux[i] = ft_strjoin(aux1, env[i][1]);
		free(aux1);
		i++;
	}
	aux[i] = NULL;
	return (aux);
}

char		***loadev(char **envp)
{
	int		lenline;
	char	***arr;
	int		cont;
	int		cont2;

	lenline = count_line_envp(envp);
	arr = malloc(sizeof(char *) * (lenline + 1));
	cont = 0;
	while (cont < lenline)
	{
		arr[cont] = malloc(sizeof(char *) * (2));
		cont2 = 0;
		while (cont2 < 2)
		{
			arr[cont][cont2] = (cont2 == 0) ?
			ft_strcdup(envp[cont], '=') : ft_strcdupinv(envp[cont], '=');
			cont2++;
		}
		cont++;
	}
	arr[cont] = NULL;
	return (arr);
}
