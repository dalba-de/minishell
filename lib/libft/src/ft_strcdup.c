/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:13:40 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/14 18:13:42 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
