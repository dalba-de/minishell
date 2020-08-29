/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:33:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 13:15:22 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_line_envp(char **envp)
{
	int	cont;

	cont = 0;
	while (envp[cont] != NULL)
		cont++;
	return (cont);
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
	/*arr[cont] = malloc(sizeof(char *) * (2));
	arr[cont][0] = NULL;
	arr[cont][1] = NULL;*/
	return (arr);
}
