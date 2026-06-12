/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:44:48 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 15:50:39 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_hex_mecanism(unsigned long long n, t_flags *flags, char *pref, int p_len)
{
	int	len;
	int	num_len;
	int	actual_len;

	len = 0;
	num_len = ft_nbrlen_base(n, 16);
	if (n == 0 && flags->dot && flags->precision == 0)
		num_len = 0;
	actual_len = num_len;
	if (flags->precision > num_len)
		actual_len = flags->precision;
	if (!flags->dash && !flags->zero)
		len += ft_print_pad(flags->width, actual_len + p_len, 0);
	len += write(1, pref, p_len);
	if (!flags->dash && flags->zero)
		len += ft_print_pad(flags->width, actual_len + p_len, 1);
	len += ft_print_pad(flags->precision, num_len, 1);
	if (!(n == 0 && flags->dot && flags->precision == 0))
		ft_puthex_long(n, flags->type);
	len += num_len;
	if (flags->dash)
		len += ft_print_pad(flags->width, actual_len + p_len, 0);
	return (len);
}

int	ft_handle_hex(unsigned int n, t_flags *flags)
{
	char	prefix[2];
	int		p_len;

	p_len = 0;
	if (flags->dot)
		flags->zero = 0;
	if (flags->hash && n != 0)
	{
		prefix[0] = '0';
		prefix[1] = flags->type;
		p_len = 2;
	}
	return (ft_print_hex_mecanism(n, flags, prefix, p_len));
}

int	ft_handle_ptr(unsigned long long ptr, t_flags *flags)
{
	char	prefix[2];

	if (!ptr)
	{
		if (flags->dash)
		{
			write(1, "(nil)", 5);
			return (5 + ft_print_pad(flags->width, 5, 0));
		}
		return (ft_print_pad(flags->width, 5, 0) + write(1, "(nil)", 5));
	}
	prefix[0] = '0';
	prefix[1] = 'x';
	flags->type = 'x';
	return (ft_print_hex_mecanism(ptr, flags, prefix, 2));
}