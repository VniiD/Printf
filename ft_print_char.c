/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:23:41 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:23:43 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(char c, t_flags *flags)
{
	int len;

	len = 0;
	if (flags->minus == 1)
	{
		len += ft_putchar_len(c);
		while (len < flags->width)
			len += ft_putchar_len(' ');
	}
	else
	{
		while (len < flags->width - 1)
			len += ft_putchar_len(' ');
		len += ft_putchar_len(c);
	}
	return (len);
}
