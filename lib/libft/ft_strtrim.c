/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:59:21 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/17 20:40:56 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strrchr(set, s1[len]))
		len--;
	result = ft_substr(s1, 0, len + 1);
	return (result);
}
