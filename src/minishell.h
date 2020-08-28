#ifndef MINISHELL_H
# define MINISHELL_H
# define PIPE '|'
# define COMMA ';'
# define CD 1
# define PWD 2
# define EXPORT 3
# define UNSET 4
# define ENV 5
# define EXIT 6
# define HELP 7
# define ECHO 8
# include <get_next_line/src/get_next_line.h>
# include <libft/src/libft.h>
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
# include <signal.h>

typedef struct	s_mini
{
	int			pipe_flag;
	char		**lines;
	char		*input;
	int			start;
	char		***ev;
	char		**env;
	char		*path_str;
	char		*search_path[10];
	char 		*my_argv[100];
	char		*cmd;
	int			status;
	pid_t		pid;
	int			exit_status;
	int			rd;
	int			fd;
	char		*original_str;
}				t_mini;

char	***loadev(char **envp);
void	check_pipes(char *line, t_mini *all);
void	get_path_string(char ***tmp_envp, char *bin_path);
void 	insert_path_str_to_search(char *path_str, t_mini *all);
void	fill_argv(char *tmp_argv, t_mini *all);
int		try_exec(t_mini *all);
int		check_own_cmd(char *cmd);
void	bridge_own_cmd(int index, t_mini *all);
/*
** ---------------------utilev------------------
*/
char	*search_key_ev(char	***ev, char *key);
void	change_ev(t_mini *all, char *key, char *value);
void	addev(t_mini *all, char *key, char *value);
void	delev(t_mini *all, char *key);
void	freecer(char ***ev, int len);
int		count_line(char ***envp);
/*
** ---------------------builtins------------------
*/
void	ft_echo(t_mini *all);
void	ft_cd(t_mini *all);
void	ft_pwd();
void	ft_export(t_mini *all);
void	ft_unset(t_mini *all);
void	ft_env(t_mini *all);
void	ft_exit(t_mini *all);

#endif