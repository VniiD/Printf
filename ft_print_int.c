/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:23:20 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:23:22 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_num_len(long n, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_put_sign(long *n, t_flags *flags)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (ft_putchar_len('-'));
	}
	else if (flags->plus)
		return (ft_putchar_len('+'));
	else if (flags->space)
		return (ft_putchar_len(' '));
	return (0);
}

static int	ft_write_int(long n, int num_len, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		return (0);
	if (n >= 10)
		len += ft_write_int(n / 10, num_len, flags);
	len += ft_putchar_len((n % 10) + '0');
	return (len);
}

static int	ft_pad_and_print(long n, int num_len, t_flags *flags)
{
	int	len;
	int	zeros;
	int	spaces;
	int	sign;

	sign = (n < 0 || flags->plus || flags->space);
	zeros = 0;
	if (flags->precision > num_len)
		zeros = flags->precision - num_len;
	else if (flags->zero && !flags->dot && flags->width > (num_len + sign))
		zeros = flags->width - num_len - sign;
	spaces = flags->width - num_len - zeros - sign;
	len = 0;
	while (!flags->minus && (!flags->zero || flags->dot) && spaces-- > 0)
		len += ft_putchar_len(' ');
	len += ft_put_sign(&n, flags);
	while (!flags->minus && flags->zero && !flags->dot && spaces-- > 0)
		len += ft_putchar_len('0');
	while (zeros-- > 0)
		len += ft_putchar_len('0');
	len += ft_write_int(n, num_len, flags);
	while (flags->minus && spaces-- > 0)
		len += ft_putchar_len(' ');
	return (len);
}

int	ft_print_int(int n, t_flags *flags)
{
	long	num;
	int		num_len;

	num = n;
	num_len = ft_get_num_len(num, flags);
	return (ft_pad_and_print(num, num_len, flags));
}
