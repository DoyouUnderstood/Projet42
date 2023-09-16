#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
    str[i] = '\0';
	return (str);
}

int get_next_line(char **line, int fd)
{
    char buffer[BUFF_SIZE + 1];
    static char *buf = NULL;
    int reader; 
    if(!buf)
        buf = ft_strdup("");
    while (1)
    {
        reader = read(fd, buffer, BUFF_SIZE);
    }
    
}
int main()
{
    int fd = open("test.txt",O_RDONLY);
    char *str = NULL;
    get_next_line(fd, &str);
    printf("str : %s\n", str);

    close(fd);
    return 0;
}
