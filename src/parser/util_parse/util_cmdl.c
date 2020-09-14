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


char	***add_cmdtcmdl(char **cmd, char ***cmdl)
{
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

char	**add_argtcmd(char *arg, char **cmd)
{
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
		exit(EXIT_FAILURE);
	free(str);
	free(arg);
	return (result);
}

char	*create_strco1(t_mini *all, int *cont)
{
	char	*str;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '\'');
	while (all->strl[*cont] && all->strl[*cont] != '\'')
		(*cont)++;
	all->strl[*cont] == '\'' ? ((*cont)++) : 0;
	return (str);
}

char	*parse_dollar(char *str, int start, t_mini *all)
{
	int		i;
	int		j;
	int		k;
	char	*dollar;
	char	*key;
	char	*ret;
	
	ret = malloc(sizeof(char *) * 1024);
	j = -1;
	while (++j < start)
		ret[j] = str[j];
	k = j;
	start++;
	j = start;
	i = 0;
	if (str[j] == '?')
	{
		dollar = ft_itoa(all->exit_status);
		ft_strncat(ret, dollar, ft_strlen(dollar));
		i = ft_strlen(dollar) + k + 1;
		while (str[j])
		{
			ret[i] = str[j];
			i++;
			j++;
		}	
		ret[i] = '\0';
		return (ret);
	}
	while (str[j] != '$' && str[j] != ' ' && str[j] != '\0')
	{
		i++;
		j++;
	}
	key = ft_substr(str, start, i);
	dollar = search_key_ev(all->ev, key);
	ft_strncat(ret, dollar, ft_strlen(dollar));
	i = ft_strlen(dollar) + k;
	while (str[j])
	{
		ret[i] = str[j];
		i++;
		j++;
	}	
	ret[i] = '\0';
	return (ret);
}

char	*create_strco2(t_mini *all, int *cont)
{
	char	*str;
	int		i;
	
	(*cont)++;
	str = ft_strcdup(&all->strl[*cont], '"');
	while (all->strl[*cont] && all->strl[*cont] != '"')
		(*cont)++;
	all->strl[*cont] == '"' ? ((*cont)++) : 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			str = parse_dollar(str, i, all);   //Nueva funcion encima
		i++;
	}
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

int		dollar_lenght(t_mini *all, int i, char **dollar)
{
	int		cont;
	char	*key;
	int		start;

	cont = 0;
	i++;
	start = i;
	while (all->strl[i] != '\0' && all->strl[i] != '$'
	&& !is_final_arg(all->strl[i]))
	{
		i++;
		cont++;
	}
	key = ft_substr(all->strl, start, cont);
	*dollar = search_key_ev(all->ev, key);
	cont++;
	return (cont);
}

char	*join_dollar(char *str1, char *str2)
{
	char	*arr;

	arr = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (arr);
}

char	*create_dollar(t_mini *all, int *cont, int cont2)
{
	char	*dollar;
	char	*str;

	if (all->strl[(*cont) + cont2 + 1] == '?')
	{
		str = ft_substr(all->strl, *cont, cont2);
		cont2 += 2;
		dollar = ft_itoa(all->exit_status);
		str = join_dollar(str, dollar);
		*cont = cont2 + *cont;
		return (str);
	}
	else
	{
		str = ft_substr(all->strl, *cont, cont2);
		cont2 += dollar_lenght(all, ((*cont) + cont2), &dollar);
		str = join_dollar(str, dollar);
		while(all->strl[cont2 + *cont] == ' ' && str[0] == '\0')
			(*cont)++;
		*cont = cont2 + *cont;
		return (str);
	}
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
		{
			if (all->strl[(*cont) + cont2] == '$')			//Nuevo + 2 funciones superiores
				return (create_dollar(all, cont, cont2));
			cont2++;
		}
		if (is_pipe(all->strl[(*cont) + cont2]))
			flag[0] = 0;
	}
	str = ft_substr(all->strl, *cont, cont2);
	*cont = cont2 + *cont;
	return (str);
}
