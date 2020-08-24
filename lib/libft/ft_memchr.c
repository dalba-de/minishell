/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:45:44 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/15 16:44:55 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*s;
	size_t	i;

	s = (char*)str;
	i = 0;
	while (i < n)
	{
		if (s[i] != c)
			i++;
		else
			return ((void *)&s[i]);
	}
	return (NULL);
}
