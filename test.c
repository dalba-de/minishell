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
	char *arg[] = {"ls", "-la", NULL};
	char *env[] = {NULL};

	pid_t pid = fork();
	if (pid == 0)
	{
		execve("/bin/ls", arg, env);
		return (0);
	}
}