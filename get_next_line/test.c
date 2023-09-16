#include "get_next_line.h"

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

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join_and_free(char *s1, char *s2)
{
	char	*joined;
	int		i = 0, j = 0;

	if (!(joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

int		process_buffer(char **buf, char **line)
{
	int		i = 0;
	char	*tmp;

	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if ((*buf)[i] == '\n')
	{
		(*buf)[i] = '\0';
		*line = ft_strdup(*buf);
		tmp = *buf;
		*buf = ft_strdup(*buf + i + 1);
		free(tmp);
		return (1);
	}
	else if (ft_strlen(*buf) > 0)
	{
		*line = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
		return (0);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			reader;

	if (!buf)
		buf = ft_strdup("");
	while (1)
	{
		reader = read(fd, buffer, BUFF_SIZE);
		if (reader <= 0)
			break;
		buffer[reader] = '\0';
		buf = join_and_free(buf, buffer);
		if (strchr(buf, '\n')) // fonction a recoder, cherche '\n' dans la string
			break;
	}
	if (reader < 0)
		return (-1);
	return process_buffer(&buf, line);
}

int		main()
{
    int fd = open("test.txt", O_RDONLY);
    char *str = NULL;

    printf("%d\n",get_next_line(fd, &str));
    printf("%s", str);
    close(fd);
	return (0);
}
