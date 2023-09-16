#include "libft.h"
#include <stdio.h>

static int	count_size(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return 1;
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int n)
{
    int size;
    int i;
    char *result;

    i = 0;
    size = count_size(n);
    if(n < 0)
        size++;
    result = malloc(sizeof(char) * size + 1);
    if (!result)
        return NULL;
    result[size] = '\0';
    if (n < 0)
	{
		n = n * -1;
		result[0] = '-';
        i++;
	}
    while(size > i)
    {
        size--;
        result[size] = (n % 10) + '0';
        n /= 10;
    }
    return result;
}
/*
int main()
{
    printf("result : %s\n", ft_itoa(-1999));
    printf("result : %s\n", ft_itoa(758934));
    printf("result : %s\n", ft_itoa(0));
    printf("result : %s\n", ft_itoa(-0));
    printf("result : %s\n", ft_itoa(-483098));
    printf("result : %s\n", ft_itoa(1));

    return 0;
}
*/