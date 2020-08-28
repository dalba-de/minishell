/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 20:00:54 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/28 20:01:06 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*delete_quotes(char *ret)
{
	unsigned int		i;
	int		j;
	char	*aux;
	char	*original;
	int		flag;

	original = ret;
	i = 0;
	j = 0;
	flag = 0;
	aux = malloc(sizeof(char * ) * (ft_strlen(ret) + 1));
	while(ret[i])
	{
		if (ret[i] == '\'')
		{
			i++;
			while (ret[i] != '\'' && ret[i])
			{
				aux[j++] = ret[i++];
				if (i == ft_strlen(ret) && ret[i] != '\'')
					flag = 1;
			}	
		}
		else if (ret[i] == '\"')
		{
			i++;
			while (ret[i] != '\"' && ret[i])
			{
				aux[j++] = ret[i++];
				if (i == ft_strlen(ret) && ret[i] != '\"')
					flag = 1;
			}	
		}
		else
			aux[j++] = ret[i];
		i++;
	}
	aux[j] = '\0';
	if (flag)
		aux = original;
	return (aux);
}
