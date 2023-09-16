#include "libft.h"

int ft_strlen(char *s);

char *ft_strrchr(char *s, int c)
{
    int len;
    
    len = ft_strlen(s);
    while(len != 0)
    {
        if(s[len] == (char)c)
            return ((char*)s + len);
        len--;
    }
    return (NULL);
}