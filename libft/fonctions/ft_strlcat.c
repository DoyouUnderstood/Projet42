#include "libft.h"

int ft_strlen(char *s);

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	dlen;
	int	slen;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	j = dlen;
	if (size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (slen + dlen);
}