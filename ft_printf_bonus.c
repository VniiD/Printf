/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:39:13 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 21:47:42 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_flags(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->type = 0;
}

int	ft_parse_flags(const char *format, int i, t_flags *flags)
{
	while (format[i] && !flags->type)
	{
		if (format[i] == '-')
			flags->dash = 1;
		else if (format[i] == '0' && !flags->width && !flags->dot)
			flags->zero = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == '.')
			flags->dot = 1;
		else if (format[i] >= '0' && format[i] <= '9')
			i = ft_parse_digits(format, i, flags);
		else if (ft_is_conversion(format[i]))
			flags->type = format[i];
		if (!flags->type)
			i++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		i;
	int		print_length;

	i = 0;
	print_length = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_init_flags(&flags);
			i = ft_parse_flags(format, i + 1, &flags);
			print_length += ft_processor(args, &flags);
		}
		else
			print_length += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (print_length);
}
