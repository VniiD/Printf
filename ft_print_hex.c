/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:44:43 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 21:26:53 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	int len;
	
	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, format);
	}
	if (n % 16 < 10)
	{
		len += ft_print_char((n % 16) + 0);
	}
	else
	{
		if (format == 'x')
			len += ft_print_char((n % 16) - 10 + 'a');
		else if (format == 'X')
			len += ft_print_char((n % 16) - 10 + 'A');
	}
	return (len);
}

static int	ft_print_ptr_hex(unsigned long long n)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_ptr_hex(n / 16);
	if (n % 16 < 10)
		len += ft_print_char((n % 16) + '0');
	else
		len += ft_print_char((n % 16) - 10 + 'a');
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len += write(1, "0x", 2);
	len += ft_print_ptr_hex(ptr);
	return (len);
}