/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:46:59 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/17 19:21:02 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = -1;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (++i < n)
			d[n - 1 - i] = s[n - 1 - i];
	}
	else
	{
		i = 0;
		while (n-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
