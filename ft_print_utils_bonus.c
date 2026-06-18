#include "ft_printf_bonus.h"

int ft_putchar_len(int c)
{
    return (write(1, &c, 1));
}

int ft_pad_width(int width, int len, int has_zero)
{
    int count;

    count = 0;
    while (width > len)
    {
        if (has_zero)
            count += write(1, "0", 1);
        else
            count += write(1, " ", 1);
        width--;
    }
    return (count);
}

int ft_print_char_bonus(int c, t_flags flags)
{
    int count;

    count = 0;
    if (flags.minus == 1)
        count += ft_putchar_len(c);
    count += ft_pad_width(flags.width, 1, 0);
    if (flags.minus == 0)
        count += ft_putchar_len(c);
    return (count);
}

static int ft_putnstr(char *str, int len)
{
    int i;

    i = 0;
    while (i < len)
        write(1, &str[i++], 1);
    return (len);
}

int ft_print_str_bonus(char *str, t_flags flags)
{
    int count;
    int len;

    if (!str)
    {
        str = "(null)";
        if (flags.dot && flags.precision < 6)
            str = "";
    }
    len = 0;
    while (str[len])
        len++;
    if (flags.dot && flags.precision < len)
        len = flags.precision;
    if (flags.minus == 1)
    {
        count = ft_putnstr(str, len);
        count += ft_pad_width(flags.width, len, 0);
    }
    else
    {
        count = ft_pad_width(flags.width, len, 0);
        count += ft_putnstr(str, len);
    }
    return (count);
}
