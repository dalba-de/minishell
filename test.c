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
	char *str = "avion";
	char *str1;

	ft_substr(str, 0, 2);
	printf("%s\n", str1);
	return 0;
}