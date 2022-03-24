#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

char    *removedouble(char *str)
{
    int i = 0;
    int j;
    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if(str[i] == str[j])
                str[j] == '\200';
            j++;
        }
        i++;
    }
    return(str);
}

char    *removedouble2(char *str1, char *str2)
{
    int i = 0;
    int j;
    while(str1[i])
    {
        j = 0;
        while(str2[j])
        {
            if(str1[i] == str2[j])
                str2[j] == '\200';
            j++;
        }
        i++;
    }
    return(str2);
}

void    unionn(char *str1, char *str2)
{
    int i = 0;

    str1 = removedouble(str1);
    str2 = removedouble(str2);
    str2 = removedouble2(str1, str2);

    while(str1[i])
    {
        if(str1[i] && str1[i] != '\200')
            ft_putchar(str1[i]);
        i++;
    }
    i = 0;
    while(str2[i])
    {
        if(str2[i] && str2[i] != '\200')
            ft_putchar(str2[i]);
        i++;
    }
    ft_putchar('\n');
}

int main(int argc, char **argv)
{
    if(argc == 3)
        unionn(argv[1], argv[2]);
    else
        ft_putchar('\n');
    return(0);
}