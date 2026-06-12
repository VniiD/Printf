/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_processor_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:45:22 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 21:47:29 by vde-alme         ###   ########.fr       */
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
	else if (flags->type == '%')
		len += ft_handle_char('%', flags);
	// Os próximos "else if" para d, i, u, x, X, p entrarão na Parte 3
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
