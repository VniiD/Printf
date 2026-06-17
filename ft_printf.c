/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:22:36 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:28:05 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
}

int	ft_handle_print(char specifier, va_list args, t_flags *flags)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_print_char(va_arg(args, int), flags);
	else if (specifier == 's')
		len += ft_print_str(va_arg(args, char *), flags);
	else if (specifier == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long), flags);
	else if (specifier == 'd' || specifier == 'i')
		len += ft_print_int(va_arg(args, int), flags);
	else if (specifier == 'u')
		len += ft_print_uint(va_arg(args, unsigned int), flags);
	else if (specifier == 'x')
		len += ft_print_hex(va_arg(args, unsigned int), 0, flags);
	else if (specifier == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), 1, flags);
	else if (specifier == '%')
		len += ft_print_char('%', flags);
	return (len);
}

static int	ft_parse_and_print(const char *format, int *i, va_list args)
{
	t_flags	flags;
	int		len;

	len = 0;
	if (format[*i] == '%' && format[*i + 1])
	{
		ft_init_flags(&flags);
		ft_parse_flags(format, i, &flags, args);
		if (format[*i])
			len += ft_handle_print(format[*i], args, &flags);
	}
	else
		len += ft_putchar_len(format[*i]);
	if (format[*i])
		(*i)++;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
		len += ft_parse_and_print(format, &i, args);
	va_end(args);
	return (len);
}
