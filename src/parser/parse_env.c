/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:33:28 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/27 14:21:05 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_strcdup(const char *s1, char c)
{
	int		cont;
	char	*arr;
	int		len;

	len = 0;
	while (s1[len] != '\0' && s1[len] != c)
	{
		len++;
	}
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		arr[cont] = s1[cont];
		cont++;
	}
	arr[cont] = '\0';
	return (arr);
}

char		*ft_strcdupinv(const char *s1, char c)
{
	int		cont;
	int		cont2;
	char	*arr;
	int		len;

	cont = 0;
	while (s1[cont] != c)
	{
		if (s1[cont++] == '\0')
			return (NULL);
	}
	cont++;
	len = 0;
	while (s1[cont + len] != '\0')
		len++;
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cont2 = 0;
	while (cont2 < len)
	{
		arr[cont2] = s1[cont + cont2];
		cont2++;
	}
	arr[cont2] = '\0';
	return (arr);
}

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
	arr[cont] = malloc(sizeof(char *) * (2));
	arr[cont][0] = NULL;
	arr[cont][1] = NULL;
	return (arr);
}
