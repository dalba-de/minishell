#include "minishell.h"

int		main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	minishell(envp);
	return (0);
}