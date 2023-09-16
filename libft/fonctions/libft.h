#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <ctype.h>

int ft_isalnum(char c);
int ft_isalpha(char c);
int ft_isascii(int c); 
int ft_isdigit(char c);
int ft_isprint(char c);
char ft_tolower(char c);
char ft_toupper(char c);

char    *ft_strrchr( char *s, int c);
char    *ft_strchr( char *s, int c);
char	*ft_strnstr(const char *str, const char *to_find, int len);
int	ft_strlcpy(char *dest, const char *src, int size);
int	ft_strlcat(char *dest, char *src, int size);
int	ft_atoi(const char *nptr);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memmove(void *dest, const void *src, int n);
int	ft_memcmp(const void *s1, const void *s2, int n);
void	ft_bzero(void *s, int n);
void *calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char  *s1, char  *s2);
char	**ft_split(char const *s, char c);
char *ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));










#endif