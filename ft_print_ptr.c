/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:23:10 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:23:12 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (5);
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len + 2);
}

static void	ft_write_ptr_hex(unsigned long num)
{
	if (num >= 16)
		ft_write_ptr_hex(num / 16);
	if ((num % 16) < 10)
		ft_putchar_len((num % 16) + '0');
	else
		ft_putchar_len((num % 16) - 10 + 'a');
}

static int	ft_put_ptr_data(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		len += ft_putstr_len("(nil)", 5);
	else
	{
		len += ft_putstr_len("0x", 2);
		ft_write_ptr_hex(ptr);
		len += ft_get_ptr_len(ptr) - 2;
	}
	return (len);
}

int	ft_print_ptr(unsigned long ptr, t_flags *flags)
{
	int	len;
	int	ptr_len;

	ptr_len = ft_get_ptr_len(ptr);
	len = 0;
	if (flags->minus == 0)
	{
		while (len < flags->width - ptr_len)
			len += ft_putchar_len(' ');
	}
	len += ft_put_ptr_data(ptr);
	if (flags->minus == 1)
	{
		while (len < flags->width)
			len += ft_putchar_len(' ');
	}
	return (len);
}
