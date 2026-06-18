//cabeçalho
#include "ft_printf.h"

static int  ft_formats(va_list args, const char format)
{
	int print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format =='X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int ft_printf(const char *format, ...)
{
	int     i;
	int     print_length;
	va_list args;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
