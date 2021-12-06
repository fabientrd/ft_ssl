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

#endif