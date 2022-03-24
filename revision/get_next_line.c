#include"get_next_line.h"

int find_new_line(char *str)
{
    int i = -1;
    if(!str)
        return(-1);
    while(str[++i])
        if(str[i] == '\n')
            return(i);
    return(-1);
}

int ft_strlen(char *str)
{
    int i = 0;
    if(!str)
        return 0 ;
    while(str[i])
        i++;
    return(i);
}

char    *ft_calc_line(char *line, char buf)
{
    int i = -1;
    char *res;
    res = malloc(ft_strlen(line) + 2);
    while(line[++i])
        res[i] = line[i];
    res[i] = buf;
    i++;
    res[i] = '\0';
    free(line);
    return(res);
}

char    *get_next_line(int fd)
{
    int bytes_read = 1;
    char *line;
    char buf;

    if(fd<0)
        return(NULL);
    line = malloc(1);
    line[0] = '\0';
    while(find_new_line(line) == -1 && bytes_read)
    {
        bytes_read = read(fd, &buf, 1);
        if(bytes_read <= 0 || bytes_read == -1)
        {
            if(!line[0])
                free(line);
            return(NULL);
        }
        line = ft_calc_line(line, buf);
    }
    return(line);
}