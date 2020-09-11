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

int main()
{
	pid_t pid;
	char *arg[] = {"/bin/echo", "\0", "hola", NULL};
	char *env[] = {NULL};

	if ((pid = fork()) == 0)
	{
		execve(arg[0], arg, env);
		exit(EXIT_FAILURE);
	}
	return (0);
}