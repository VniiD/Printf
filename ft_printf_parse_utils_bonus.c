/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:41:49 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 21:43:22 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_parse_digits(const char *format, int i, t_flags *flags)
{
	int	value;

	value = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		value = (value * 10) + (format[i] - '0');
		i++;
	}
	if (flags->dot == 1)
		flags->precision = value;
	else
		flags->width = value;
	return (i - 1);
}
