// cabeçalho

#include "ft_printf.h"

static int  ft_print_str_pad(int pad_len)
{
    int len;

    len = 0;
    while (len < pad_len)
        len += ft_putchar_len( ' ');
    return (len);
}

int ft_print_str(char *str, t_flags *flags)
{
    int     len;
    int     str_len;
    char    *base_str;

    len = 0;
    base_str = str;
    if (!base_str)
        base_str = "(null)";
    str_len = ft_strlen(base_str);
    if (flags->dot && flags->precision < str_len)
        str_len = flags->precision;
    if (flags->minus == 0)
        len += ft_print_str_pad(flags->width - str_len);
    len += ft_putstr_len(base_str, str_len);
    if (flags->minus == 1)
        len +=ft_print_str_pad(flags->width - str_len);
    return (len);
}
