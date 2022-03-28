#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int     ft_putchar(char c)
{
    write(1, &c, 1);
    return(1);
}

int ft_putstr(char *str)
{
    int i = 0;
    int len = 0;

    if(str == NULL)
    {
        ft_putstr("(null)");
        return(6);
    }
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
        len++;
    }
    return(len);
}

int ft_putnbr(int nb)
{
    int len = 0;
    if(nb < 0)
    {
        len+=ft_putchar('-');
        if(nb == "-2148473648")
        {
            len+=ft_putstr("2148473648");
            return(len);
        }
        nb *= -1;
    }
    if(nb >10)
        len+=ft_putnbr(nb/10);
    len+=ft_putnbr(nb%10 + '0');
    return(len);
}

int ft_hex(unsigned int n)
{
    int len = 0;
    char *base = "0123456789abcdef";

    if(n >= 16)
        len+=ft_hex(n / 16);
    len += ft_putchar(base[n%10]);
    return(len);
}

int ft_check(char c)
{
    int i = 0;
    char *str = "sdx%";

    while(str[i])
    {
        if(str[i] == c)
            return(1);
        i++;
    }
    return(0);
}

int check(char c, va_list list)
{
    int len = 0;
    if(c == 's')
        len+=ft_putstr(va_arg(list, char *));
    if(c == 'd')
        len+=ft_putnbr(va_arg(list, int));
    if(c == 'x')
        len+=ft_hex(va_arg(list, unsigned int));
    return(len);
}

int ft_printf(const char *str, ...)
{
    va_list list;
    int len = 0;
    int i = 0;

    va_start(list, str);
    while(str[i])
    {
        if(str[i] == '%' && ft_check(str[i++]) == 1)
        {
            i++;
            len +=check(str[--i], list);
        }
        else
            len+=ft_putchar(str[i]);
        i++;
    }
    va_end(list);
    return(len);
}
