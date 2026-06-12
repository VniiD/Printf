/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_processor_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:45:22 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 15:43:05 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_processor(va_list args, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->type == 'c')
		len += ft_handle_char(va_arg(args, int), flags);
	else if (flags->type == 's')
		len += ft_handle_str(va_arg(args, char *), flags);
	else if (flags->type == 'd' || flags->type == 'i')
		len += ft_handle_int(va_arg(args, int), flags);
	else if (flags->type == 'u')
		len += ft_handle_uint(va_arg(args, unsigned int), flags);
	else if (flags->type == 'x' || flags->type == 'X')
		len += ft_handle_hex(va_arg(args, unsigned int), flags);
	else if (flags->type == 'p')
		len += ft_handle_ptr(va_arg(args, unsigned long long), flags);
	else if (flags->type == '%')
		len += ft_handle_char('%', flags);
	return (len);
}

int	ft_print_pad(int total_width, int len, int has_zero)
{
	int	count;

	count = 0;
	while (total_width > len)
	{
		if (has_zero)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		total_width--;
	}
	return (count);
}
