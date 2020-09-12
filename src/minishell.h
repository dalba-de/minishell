/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalba-de <dalba-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:37:17 by dalba-de          #+#    #+#             */
/*   Updated: 2020/09/12 02:55:22 by dalba-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PIPE '|'
# define COMMA ';'
# define ECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7
# define HELP 8
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
	char		***ev;
	char		**env;
	char		*path_str;
	char		*search_path[10];
	char		*my_argv[100];
	char		*cmd;
	int			status;
	pid_t		pid;
	int			exit_status;
	int			rd;
	int			fd;
	int			piping;
	int			double_redir;
	char		*strl;
	int			in;
	int			out;
}				t_mini;

char			***loadev(char **envp);
void			check_pipes(char *line, t_mini *all);
void			get_path_string(char ***tmp_envp, char *bin_path);
void			insert_path_str_to_search(char *path_str, t_mini *all);
void			fill_argv(char **cmdl, t_mini *all);
int				try_exec(t_mini *all, char **cmdl);
int				check_own_cmd(char *cmd);
int				bridge_own_cmd(int index, t_mini *all, char **cmdl);
void			parse_echo_argv(t_mini *all, char *ret, int index);
char			*delete_quotes(char *ret);
void			parse_pipes(char **cmdl, t_mini *all);
int				attach_path(t_mini *all, char *cmd);
void			not_found(t_mini *all);
char			***parse_cmdlist(t_mini *all);
void			parse_redir(char **tmp_argv, t_mini *all);
/*
** ---------------------utilev------------------
*/
char			*search_key_ev(char	***ev, char *key);
void			change_ev(t_mini *all, char *key, char *value);
void			addev(t_mini *all, char *key, char *value);
void			delev(t_mini *all, char *key);
void			freecer(char ***ev, int len);
int				count_line(char ***envp);
char			**env_to_double(char ***env);
/*
** ---------------------utilcmdl------------------
*/
char			***add_cmdtcmdl(t_mini *all, char **cmd, char ***cmdl);
char			**add_argtcmd(t_mini *all, char *arg, char **cmd);
char			*add_strtarg(t_mini *all, char *str, char *arg);
char			*create_strco1(t_mini *all, int *cont);
char			*create_strco2(t_mini *all, int *cont);
char			*create_strtstr(t_mini *all, int *cont, int *flag);

/*
** ---------------------builtins------------------
*/
void			ft_echo(t_mini *all, char **cmdl);
void			ft_cd(t_mini *all, char **cmdl);
void			ft_pwd(t_mini *all, char **cmdl);
void			ft_export(t_mini *all, char **cmdl);
void			ft_unset(t_mini *all, char **cmdl);
void			ft_env(t_mini *all);
void			ft_exit(t_mini *all, char **cmdl);

#endif
