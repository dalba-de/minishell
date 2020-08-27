/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 10:46:41 by dalba-de          #+#    #+#             */
/*   Updated: 2019/11/17 18:58:03 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void *memory;

	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	else
		ft_bzero(memory, size * count);
	return (memory);
}
