// cabeçalho

#include "ft_printf.h"

int ft_print_char(char c, t_flags *flags)
{
    int len;

    len = 0;
    if (flags->minus == 1)
    {
        len += ft_putchar_len(c);
        while (len < flags->width)
            len += ft_putchar_len(' ');
    }
    else
    {
        while (len < flags->width - 1)
            len += ft_putchar_len(' ');
        len += ft_putchar_len(c);
    }
    return (len);
}
