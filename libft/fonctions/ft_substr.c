#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	if (i < start)
		return (strdup(""));
	j = 0;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (j < len && s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
