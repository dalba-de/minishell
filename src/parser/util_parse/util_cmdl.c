#include "minishell.h"

int		ft_cmdlen(char ***cmdl)
{
	int	cont;

	if (cmdl == NULL)
		return (0);
	cont = 0;
	while (cmdl[cont])
		cont++;
	return (cont);
}

int		ft_arglen(char **cmd)
{
	int	cont;

	if (cmd == NULL)
		return (0);
	cont = 0;
	while (cmd[cont])
		cont++;
	return (cont);
}


char	***add_cmdtcmdl(t_mini *all, char **cmd, char ***cmdl)
{
	(void)all;
	char	***result;
	int		cont;

	if (!(result = malloc(sizeof(char ***) * (ft_cmdlen(cmdl) + 2))))
			exit(1);
	cont = 0;
	while (cmdl != NULL && cmdl[cont])
	{
		result[cont] = cmdl[cont];
		cont++;
	}
	result[cont] = cmd;
	result[cont + 1] = NULL;
	cmdl != NULL ? (free(cmdl)) : (0);
	return (result);
}

char	**add_argtcmd(t_mini *all, char *arg, char **cmd)
{
	(void)all;
	char	**result;
	int		cont;

	if (!(result = malloc(sizeof(char **) * (ft_arglen(cmd) + 2))))
			exit(1);
	cont = 0;
	while (cmd != NULL && cmd[cont])
	{
		result[cont] = cmd[cont];
		cont++;
	}
	result[cont] = arg;
	result[cont + 1] = NULL;
	cmd != NULL ? (free(cmd)) : (0);
	return (result);
}

char		*add_strtarg(t_mini *all, char *str, char *arg)
{
	(void)all;
	char	*result;

	if (arg == NULL)
		return (str);
	if (!(result = ft_strjoin(arg, str)))
		exit(1); //comentarlo
	free(str);
	free(arg);
	return (result);
}

char	*create_strco1(t_mini *all, int *cont)
{
	char	*str;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '\'');
	while (all->strl[*cont] && all->strl[*cont] != '\'') //cambiado &&
		(*cont)++;
	all->strl[*cont] == '\'' ? ((*cont)++) : 0;
	return (str);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '"');
	while (all->strl[*cont] && all->strl[*cont] != '"') //cambiado &&
		(*cont)++;
	all->strl[*cont] == '"' ? ((*cont)++) : 0;
	return (str);
}

static	int		is_pipe(char c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

static	int		is_final_arg(char c)
{
	if (c == ' ' || c == ';' || c == '"' || c == '\'' || is_pipe(c))
		return (1);
	return (0);
}

char	*create_strtstr(t_mini *all, int *cont, int *flag)
{
	char	*str;
	int		cont2;

	cont2 = 0;
	if (is_pipe(all->strl[(*cont)]))
	{
		flag[0] = 0;
		cont2++;
		all->strl[(*cont)] == '>' && all->strl[(*cont) + 1] == '>' ? (cont2++) : (0);
	}
	else
	{
		while (all->strl[(*cont) + cont2] && !is_final_arg(all->strl[(*cont) + cont2]))
			cont2++;
	}
	str = ft_substr(all->strl, *cont, cont2);
	*cont = cont2 + *cont;
	return (str);
}
