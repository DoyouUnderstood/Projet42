#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new;
	size_t	total;

	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size) 
		return (NULL);

	new = malloc(total);
	if (!new)
		return (NULL);

	memset(new, 0, total);
	return (new);
}
