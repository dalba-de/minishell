/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:44:02 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/17 22:38:35 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long n)
{
	unsigned int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char				*str;
	unsigned long int	nb;
	int					len;

	nb = n;
	len = nb_len(nb);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
