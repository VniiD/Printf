/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:43:58 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 15:44:02 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_get_int_prefix(long *nbr, t_flags *flags, char *prefix)
{
	if (*nbr < 0)
	{
		prefix[0] = '-';
		*nbr = -(*nbr);
		return (1);
	}
	else if (flags->plus)
	{
		prefix[0] = '+';
		return (1);
	}
	else if (flags->space)
	{
		prefix[0] = ' ';
		return (1);
	}
	return (0);
}

static int	ft_print_int_mecanism(long nbr, t_flags *flags, char *pref, int p_len)
{
	int	len;
	int	num_len;
	int	actual_len;

	len = 0;
	num_len = ft_nbrlen_base(nbr, 10);
	if (nbr == 0 && flags->dot && flags->precision == 0)
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
	if (!(nbr == 0 && flags->dot && flags->precision == 0))
		ft_putnbr_long(nbr);
	len += num_len;
	if (flags->dash)
		len += ft_print_pad(flags->width, actual_len + p_len, 0);
	return (len);
}

int	ft_handle_int(int n, t_flags *flags)
{
	long	nbr;
	char	prefix[1];
	int		prefix_len;

	nbr = n;
	prefix[0] = '\0';
	if (flags->dot)
		flags->zero = 0;
	prefix_len = ft_get_int_prefix(&nbr, flags, prefix);
	return (ft_print_int_mecanism(nbr, flags, prefix, prefix_len));
}