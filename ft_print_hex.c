//Cabeçalho
#include "ft_printf.h"

int ft_print_hex(unsigned int num, const char format)
{
    int     count;
    char    *base;

    count = 0;
    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if (num >= 16)
        count += ft_print_hex(num / 16, format);
    count += ft_print_char(base[num % 16]);
    return (count);
}

static int ft_print_ptr_hex(unsigned long long num)
{
    int     count;
    char    *base;

    count = 0;
    base = "0123456789abcdef";
    if (num >= 16)
        count += ft_print_ptr_hex(num / 16);
    count += ft_print_char(base[num % 16]);
    return (count);
}

int ft_print_ptr(unsigned long long ptr)
{
    int count;

    count = 0;
    if (!ptr)
        return (write(1, "(nil)", 5));
    count += write(1, "0x", 2);
    count += ft_print_ptr_hex(ptr);
    return (count);
}
