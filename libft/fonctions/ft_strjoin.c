#include "libft.h"

int ft_strlen(char *s);


char *ft_strjoin(char *s1, char *s2)
{
    int len;
    int i;
    char *result;
    int j;
    if(!s1 && !s2)
        return NULL;
    len = ft_strlen(s1) + ft_strlen(s2);
    if(!len)
        return (NULL);
    result = malloc(sizeof(char) * len + 1);
    i = 0;
    j = 0;
    while(s1[i])
        result[j++] = s1[i++];
    i = 0;
    while(s2[i])
        result[j++] = s2[i++];
    result[j] = '\0';
    return (result); 
}
