/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdupinv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:17:03 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 17:17:05 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
