#include "libft.h"

char		*ft_strcdup(const char *s1, char c)
{
	int		cont;
	char	*arr;
	int		len;

	len = 0;
	while (s1[len] != '\0' && s1[len] != c)
	{
		len++;
	}
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		arr[cont] = s1[cont];
		cont++;
	}
	arr[cont] = '\0';
	return (arr);
}
