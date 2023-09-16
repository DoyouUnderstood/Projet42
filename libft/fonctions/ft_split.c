#include "libft.h"


int count_word(char const *str, char c)
{
    int i;
    int nb;

    nb = 0;
    i = 0;  
    while (str[i])
    {
        while(str[i] && str[i] == c)
            i++;
        if(str[i] && str[i] != c)
        {
             nb++;
             while (str[i] && str[i] != c)
                i++;
        }
    }
    return nb;
}

char *worddup(const char *s, int len)
{
    int i;
    char *str;

    i = 0;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;
    while (len != 0)
    {
        str[i] = s[i];
        i++;
        len--;
    }
    str[i] = '\0';
    return str;
}

char	**ft_split(char const *s, char c)
{
    int i;
    int j;
    int k;
    char **result;

    i = 0;
    j = 0;
    result = malloc(sizeof(char*) * (count_word(s, c) + 1));

    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i] && s[i] != c)
        {
            k = i;
            while (s[i] && s[i] != c)
                i++;
            result[j] = worddup(s + k, i - k);
            if (!result[j])
                return NULL;
            j++;
        }
    }
    result[j] = NULL;
    return result;
}
/*
void display_split_array(char **arr)
{
    int i;

    if (!arr)
    {
        printf("Le tableau est NULL\n");
        return;
    }

    i = 0;
    while (arr[i])
    {
        printf("Mot %d : %s\n", i, arr[i]);
        i++;
    }
}

int main()
{
    char **result;
    char str[] = "Bonjour, comment allez-vous aujourd'hui ?";
    char delimiter = ' ';

    result = ft_split(str, delimiter);
    display_split_array(result);

    // Libérer la mémoire allouée
    int i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
*/