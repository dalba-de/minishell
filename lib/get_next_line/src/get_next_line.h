/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:32:43 by dalba-de          #+#    #+#             */
/*   Updated: 2020/08/24 18:57:10 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*g_ft_strdup(const char *s);
char	*g_ft_strjoin(char const *s1, char const *s2);
char	*g_ft_substr(char const *s, unsigned int start, size_t len);
size_t	g_ft_strlen(const char *s);
char	*g_ft_strchr(const char *s, int c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32

#endif