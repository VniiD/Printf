#include "ft_printf_bonus.h"

t_flags ft_init_flags(void)
{
    t_flags flags;

    flags.minus = 0;
    flags.zero = 0;
    flags.dot = 0;
    flags.precision = 0;
    flags.width = 0;
    flags.hash = 0;
    flags.space = 0;
    flags.plus = 0;
    return (flags);
}

static int parse_flags(const char *str, int i, t_flags *flags)
{
    while (str[i] == '-' || str[i] == '0' || str[i] == '#' ||
           str[i] == ' ' || str[i] == '+')
    {
        if (str[i] == '-')
            flags->minus = 1;
        else if (str[i] == '0')
            flags->zero = 1;
        else if (str[i] == '#')
            flags->hash = 1;
        else if (str[i] == ' ')
            flags->space = 1;
        else if (str[i] == '+')
            flags->plus = 1;
        i++;
    }
    return (i);
}

static int parse_width_prec(const char *str, int i, t_flags *flags)
{
    while (str[i] >= '0' && str[i] <= '9')
    {
        flags->width = (flags->width * 10) + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        flags->dot = 1;
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            flags->precision = (flags->precision * 10) + (str[i] - '0');
            i++;
        }
    }
    return (i);
}

static int ft_formats_bonus(va_list args, const char format, t_flags flags)
{
    int count;

    count = 0;
    if (format == 'c')
        count += ft_print_char_bonus(va_arg(args, int), flags);
    else if (format == 's')
        count += ft_print_str_bonus(va_arg(args, char *), flags);
    else if (format == 'p')
        count += ft_print_ptr_bonus(va_arg(args, unsigned long long), flags);
    else if (format == 'd' || format == 'i')
        count += ft_print_nbr_bonus(va_arg(args, int), flags);
    else if (format == 'u')
        count += ft_print_nbr_bonus(va_arg(args, unsigned int), flags);
    else if (format == 'x')
        count += ft_print_hex_bonus(va_arg(args, unsigned int), 0, flags);
    else if (format == 'X')
        count += ft_print_hex_bonus(va_arg(args, unsigned int), 1, flags);
    else if (format == '%')
        count += write(1, "%", 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    int     i;
    int     print_length;
    va_list args;
    t_flags flags;

    i = 0;
    print_length = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            flags = ft_init_flags();
            i = parse_flags(format, i + 1, &flags);
            i = parse_width_prec(format, i, &flags);
            print_length += ft_formats_bonus(args, format[i], flags);
        }
        else
            print_length += write(1, &format[i], 1);
        if (format[i])
            i++;
    }
    va_end(args);
    return (print_length);
}