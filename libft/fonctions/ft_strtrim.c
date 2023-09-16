#include "libft.h"
int ft_strlen(char *s);


static int ft_char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char    *ft_strtrim(char  *s1, char  *set)
{
	char	*str;
	int	i;
	int	start;
	int	end;

	start = 0;
	while (s1[start] && ft_char_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(s1[end - 1], set))
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
/*
int main()
{
    printf("%s\n", ft_strtrim("allons garcon ca va pas se faire touttttt saulaa", "a"));
  
}
*/