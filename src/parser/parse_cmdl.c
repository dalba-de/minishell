#include "minishell.h"

/*char	***parse_cmdlist(t_mini *all)
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
		(*cont)++;
	}
	return (cmdl);
}

char	**create_cmd(t_mini *all, int *cont)
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
			cmd = add_argtcmd(all, arg, cmd);
		}
		(*cont)++;
	}
	return (cmd);
}

char	*create_arg(t_mini *all, int *cont)
{
	char	*arg;
	char	*str;

	arg = NULL;
	str = NULL;
	if (all->strl[*cont] == '|' || all->strl[*cont] == '<' || all->strl[*cont] == '>')
		return ( create_strpipe(all, cont));
	while (all->strl[*cont])
	{
		if (all->strl[*cont] == '\'')
			str = create_strco1(all, cont);
		else if (all->strl[*cont] == '"')
			str = create_strco2(all, cont);
		else if (all->strl[*cont] == '|' || all->strl[*cont] == '<' || all->strl[*cont] == '>')
		{
			(*cont)--;
			break ;
		}
		else if (all->strl[*cont] == ' ' || all->strl[*cont] == ';')
			break ;
		else
			str = create_strtc(all, cont);
		arg = add_strtarg(all, str, arg);
	}
	return (arg);
}
*/