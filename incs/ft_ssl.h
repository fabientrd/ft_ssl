#ifndef FT_SSL_H
# define FT_SSL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

typedef struct  s_env{
    int         cmd;
    int         p;
    int         q;
    int         r;
    int         s;
    int         begin;
    int         bytes;
    char        buf[2048];
}               t_env;

void ft_md5(char **av, t_env *env);
void ft_sha256(char **av, t_env *env);

#endif