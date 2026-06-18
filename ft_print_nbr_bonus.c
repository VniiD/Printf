#include "ft_printf_bonus.h"

static int get_nbr_len(long n, t_flags flags)
{
    int len;

    if (n == 0 && flags.dot && flags.precision == 0)
        return (0);
    if (n == 0)
        return (1);
    len = 0;
    if (n < 0)
        n = -n;
    while (n > 0)
    {
        len++;
        n /= 10;
    }
    return (len);
}

static int get_zeros(long n, int len, t_flags flags)
{
    int z;

    z = 0;
    if (flags.precision > len)
        z = flags.precision - len;
    else if (flags.zero && !flags.minus && !flags.dot)
        z = flags.width - len - (n < 0 || flags.plus || flags.space);
    if (z < 0)
        return (0);
    return (z);
}

static int print_sign(long n, t_flags flags)
{
    if (n < 0)
        return (write(1, "-", 1));
    if (flags.plus)
        return (write(1, "+", 1));
    if (flags.space)
        return (write(1, " ", 1));
    return (0);
}

static int print_unbr(long n)
{
    int c;

    c = 0;
    if (n < 0)
        n = -n;
    if (n > 9)
        c += print_unbr(n / 10);
    c += ft_putchar_len((n % 10) + '0');
    return (c);
}

int ft_print_nbr_bonus(long n, t_flags flags)
{
    int c;
    int len;
    int z;
    int s;

    len = get_nbr_len(n, flags);
    z = get_zeros(n, len, flags);
    s = flags.width - len - z - (n < 0 || flags.plus || flags.space);
    c = 0;
    if (!flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    c += print_sign(n, flags);
    if (z > 0)
        c += ft_pad_width(z, 0, 1);
    if (len > 0)
        c += print_unbr(n);
    if (flags.minus && s > 0)
        c += ft_pad_width(s, 0, 0);
    return (c);
}
