#ifndef MINISHELL_H
# define MINISHELL_H
# define PIPE '|'
# define COMMA ';'
# include <get_next_line/src/get_next_line.h>
# include <libft/libft.h>
# include <stdio.h>
# include <limits.h>
# include <linux/limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_mini
{
	char		**lines;
	char		*input;
	int			start;
}				t_mini;

#endif