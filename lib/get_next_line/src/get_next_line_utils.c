/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:07:36 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/17 16:07:36 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*g_ft_strdup(const char *s)
{
	char	*src;
	char	*dest;
	int		i;

	src = (char*)s;
	dest = malloc(g_ft_strlen(src) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*g_ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	concat = malloc((g_ft_strlen(s1) + g_ft_strlen(s2) + 1));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*g_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src;
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	src = (char*)s;
	if (g_ft_strlen(src) < start)
		return (g_ft_strdup(""));
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

size_t	g_ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*g_ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char*)&s[i]);
}
