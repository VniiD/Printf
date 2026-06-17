//cabeçalho

#include "ft_printf.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int ft_strlen(const char *s)
{
    const char  *str;

    str = s;
    if (!s)
        return (0);
    while (*s)
        s++;
    return (s - str);
}

int ft_putchar_len(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr_len(char *s, int len)
{
    int i;

    i = 0;
    while (s[i] && i < len)
    {
        write (1, &s[i], 1);
        i++;
    }
    return (i);
}
