#include "minishell.h"

/*int		ft_cmdlen(char ***cmdl)
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
	char	***result;
	int		cont;

	if (!(result = malloc(sizeof(char ***) * (ft_cmdlen(cmdl) + 2))))
			ft_exit(all);
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
	char	**result;
	int		cont;

	if (!(result = malloc(sizeof(char **) * (ft_arglen(cmd) + 2))))
			ft_exit(all);
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
	char	result;

	if (arg == NULL)
		return (str);
	if (!(result = ft_strjoin(arg, str)))
		ft_exit(all);
	free(str);
	free(arg);
	return (result);
}

char	*create_strco1(t_mini *all, int *cont)
{
	char	*str;
	
	(*cont)++;
	str = ft_strcdup(all->strl[*cont], '\'');
	while (all->strl[*cont] || all->strl[*cont] != '\'')
		(*cont)++;
	all->strl[*cont] == '\'' ? ((*cont)++) : 0;
	return (str);
}*/