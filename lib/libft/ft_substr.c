/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:54:23 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/17 20:39:53 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	src = (char*)s;
	if (ft_strlen(src) < start)
		return (ft_strdup(""));
	if (!(dest = malloc(len + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}
