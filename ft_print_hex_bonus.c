#include "ft_printf_bonus.h"

static int get_hex_len(unsigned long long n, t_flags flags)
{
    int len;

    if (n == 0 && flags.dot && flags.precision == 0)
        return (0);
    if (n == 0)
        return (1);
    len = 0;
    while (n > 0)
    {
        len++;
        n /= 16;
    }
    return (len);
}

static int get_hex_zeros(unsigned long long n, int len, t_flags flags)
{
    int z;

    z = 0;
    if (flags.precision > len)
        z = flags.precision - len;
    else if (flags.zero && !flags.minus && !flags.dot)
        z = flags.width - len - ((flags.hash && n != 0) * 2);
    if (z < 0)
        return (0);
    return (z);
}

static int print_hex_num(unsigned long long n, int is_upper)
{
    int c;

    c = 0;
    if (n >= 16)
        c += print_hex_num(n / 16, is_upper);
    if (is_upper)
        c += ft_putchar_len("0123456789ABCDEF"[n % 16]);
    else
        c += ft_putchar_len("0123456789abcdef"[n % 16]);
    return (c);
}

int ft_print_hex_bonus(unsigned int num, int is_upper, t_flags flags)
{
    int c;
    int len;
    int z;
    int s;

    len = get_hex_len(num, flags);
    z = get_hex_zeros(num, len, flags);
    s = flags.width - len - z - ((flags.hash && num != 0) * 2);
    c = 0;
    if (!flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    if (flags.hash && num != 0 && is_upper)
        c += write(1, "0X", 2);
    if (flags.hash && num != 0 && !is_upper)
        c += write(1, "0x", 2);
    if (z > 0)
        c += ft_pad_width(z, 0, 1);
    if (len > 0)
        c += print_hex_num(num, is_upper);
    if (flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    return (c);
}

int ft_print_ptr_bonus(unsigned long long ptr, t_flags flags)
{
    int c;
    int len;
    int s;

    len = 5;
    if (ptr)
        len = get_hex_len(ptr, flags);
    s = flags.width - len - ((ptr != 0) * 2);
    c = 0;
    if (!flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    if (!ptr)
        c += write(1, "(nil)", 5);
    if (ptr)
        c += write(1, "0x", 2);
    if (ptr)
        c += print_hex_num(ptr, 0);
    if (flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    return (c);
}
