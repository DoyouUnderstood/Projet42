#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (n > 0)
	{
		if (str[i] == (unsigned char)c)
		{
			return (str + i);
		}
		i++;
		n--;
	}
	return (NULL);
}