#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == 43)
		nptr++;
	else if (*nptr == 45)
	{
		sign = 1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr != '\0')
	{
		result = (*nptr++ - '0') + (result * 10);
	}
	if (sign == 1)
		return (-result);
	else
		return (result);
}