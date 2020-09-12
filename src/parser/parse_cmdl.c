#include "minishell.h"

static	char	*create_arg(t_mini *all, int *cont)
{
	char	*arg;
	char	*str;
	int		flag[1];

	arg = NULL;
	str = NULL;
	flag[0] = 1;
	if (all->strl[*cont] == PIPE || all->strl[*cont] == '>' || all->strl[*cont] == '<')
	{
		str = create_strtstr(all, cont, flag);
		arg = add_strtarg(all, str, arg);
		return (arg);
	}	
	while (all->strl[*cont] && flag[0])
	{
		if (all->strl[*cont] == '\'')
			str = create_strco1(all, cont);
		else if (all->strl[*cont] == '"')
			str = create_strco2(all, cont);
		else if (all->strl[*cont] == ' ' || all->strl[*cont] == ';' || all->strl[*cont] == '|'
		|| all->strl[*cont] == '>' || all->strl[*cont] == '<')
			break ;
		else
			str = create_strtstr(all, cont, flag);
		arg = add_strtarg(all, str, arg);
	}
	return (arg);
}

static	char	**create_cmd(t_mini *all, int *cont)
{
	char	**cmd;
	char	*arg;

	cmd = NULL;
	arg = NULL;
	while (all->strl[*cont] && all->strl[*cont] != ';')
	{
		if (all->strl[*cont] != ' ')
		{
			arg = create_arg(all, cont);
			if (arg[0] != '\0') //Una guarreria?
				cmd = add_argtcmd(all, arg, cmd);
		}
		all->strl[*cont] == ' ' ?((*cont)++) : (0);
	}
	return (cmd);
}

char	***parse_cmdlist(t_mini *all)
{
	int	cont[1];
	char **cmd;
	char ***cmdl;

	*cont = 0;
	cmd = NULL;
	cmdl = NULL;
	while (all->strl[*cont])
	{
		if (all->strl[*cont] != ' ')
		{
			cmd = create_cmd(all, cont);
			cmdl = add_cmdtcmdl(all, cmd, cmdl);
		}
		all->strl[*cont] == '\0' ? (0) : ((*cont)++); //Añadido \0
	}
	return (cmdl);
}
