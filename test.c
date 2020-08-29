#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include "lib/libft/src/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

static int		ft_count_words(char const *s, char c)
{
	int i;
	int words;
	int hasword;

	i = 0;
	words = 0;
	hasword = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			hasword = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				words++;
		}
		else
			i++;
	}
	return (words + hasword);
}

static	char	*ft_alloc_word(char const *s, char c)
{
	int		size;
	char	*tab;

	size = 0;
	tab = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(tab, s, size + 1);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int		count;
	int		words;
	char	**tab;

	count = -1;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++count < words)
	{
		while (s[0] == c)
			s++;
		if (!(tab[count] = ft_alloc_word(s, c)))
		{
			while (count > 0)
				free(tab[count--]);
			free(tab);
			return (NULL);
		}
		s += strlen(tab[count]);
	}
	tab[count] = 0;
	return (tab);
}

int main()
{
	char *str = "hola amigos     como estais";
	char **split = ft_split(str, ' ');
	int i = 0;
	while (split[i] != NULL)
		ft_putendl_fd(split[i++], 1);
		return 0;
}