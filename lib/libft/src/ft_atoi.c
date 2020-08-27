/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:37:29 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/18 11:07:14 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char str)
{
	if (str == '-' || str == '+')
	{
		if (str == '-')
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			sg;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sg = ft_sign(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 2147483647 && sg == 1)
			return (-1);
		else if (res > 2147483648 && sg == -1)
			return (0);
	}
	return (res * sg);
}
