#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2000

typedef struct s_list
{
    char            *str;
    struct s_list *next; 
} t_list; 

