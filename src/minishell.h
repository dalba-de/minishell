#ifndef MINISHELL_H
# define MINISHELL_H
# define PIPE '|'
# define COMMA ';'
# include <get_next_line/src/get_next_line.h>
# include <libft/libft.h>
# include <stdio.h>
# include <errno.h>
# include <limits.h>
# include <linux/limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>
# include <string.h>

extern int errno;

typedef struct	s_mini
{
	char		**lines;
	char		*input;
	int			start;
	char		***ev;
	char		*path_str;
	char		*search_path[10];
	char 		*my_argv[100];
}				t_mini;

char	***loadev(char **envp);
void	check_pipes(char *line, t_mini *all);
void	get_path_string(char ***tmp_envp, char *bin_path);
void 	insert_path_str_to_search(char *path_str, t_mini *all);
void	fill_argv(char *tmp_argv, t_mini *all);
/*
** ---------------------utilev------------------
*/
void	freecer(char ***ev, int len);
int		count_line(char ***envp);

#endif