/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:57:29 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/18 11:06:13 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t count;
	size_t i;

	count = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (*src && i < (dstsize - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (count);
}
