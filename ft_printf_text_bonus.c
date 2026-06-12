/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:46:25 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 21:47:25 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_char(char c, t_flags *flags)
{
	int	len;

	len = 0;
	if (flags->dash == 1)
	{
		len += write(1, &c, 1);
		len += ft_print_pad(flags->width, 1, 0);
	}
	else
	{
		len += ft_print_pad(flags->width, 1, flags->zero);
		len += write(1, &c, 1);
	}
	return (len);
}

static int	ft_putstr_precision(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_handle_str(char *str, t_flags *flags)
{
	int	len;
	int	str_len;

	len = 0;
	if (!str)
		str = "(null)";
	str_len = 0;
	while (str[str_len])
		str_len++;
	if (flags->dot && flags->precision < str_len)
		str_len = flags->precision;
	if (flags->dash == 1)
	{
		len += ft_putstr_precision(str, str_len);
		len += ft_print_pad(flags->width, str_len, 0);
	}
	else
	{
		len += ft_print_pad(flags->width, str_len, flags->zero);
		len += ft_putstr_precision(str, str_len);
	}
	return (len);
}
