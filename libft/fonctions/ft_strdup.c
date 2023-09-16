#include "libft.h"

int ft_strlen(char *s);

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	if (!src)
		return (NULL);

	len = ft_strlen(src);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);

	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
