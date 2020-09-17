/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:05:54 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/17 16:06:41 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_char(char **s, char **line, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = g_ft_substr(s[fd], 0, i);
		aux = g_ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = aux;
	}
	else if (s[fd][i] == '\0')
	{
		*line = g_ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (1);
}

static int	result(int r, char **s, char **line, int fd)
{
	if (r < 0)
		return (-1);
	else if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
	{
		*line = g_ft_strdup("");
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (fill_char(s, line, fd));
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	int			r;
	char		*aux;
	static char	*s[4096];

	if (!(buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1)) ||
				fd < 0 || line == NULL)
		return (-1);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = g_ft_strdup(buffer);
		else
		{
			aux = g_ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = aux;
		}
		if (g_ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buffer);
	return (result(r, s, line, fd));
}
