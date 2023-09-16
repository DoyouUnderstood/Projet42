#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, int n)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	int			i;

	i = 0;
	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	if (!cpy_dest && !cpy_src)
		return (NULL);
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}