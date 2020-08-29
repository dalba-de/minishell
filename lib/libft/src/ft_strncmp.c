/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:58:32 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/29 14:21:09 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (str1[i] == str2[i] && str1[i] != '\0'
			&& str2[i] != '\0' && (i < n - 1))
		i++;
	return ((unsigned char)str1[i] - str2[i]);
}
