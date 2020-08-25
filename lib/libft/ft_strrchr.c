/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:59:06 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/12 12:59:08 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str1;

	str1 = (char*)str;
	i = ft_strlen(str1);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i--;
	}
	return (NULL);
}
