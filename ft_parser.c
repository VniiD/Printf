/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:23:51 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:59:06 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_bonus_flags(const char *format, int *i, t_flags *flags)
{
	while (format[*i] == '-' || format[*i] == '0' || format[*i] == '#'
		|| format[*i] == ' ' || format[*i] == '+')
	{
		if (format[*i] == '-')
			flags->minus = 1;
		else if (format[*i] == '0')
			flags->zero = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		else if (format[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	if (flags->minus == 1)
		flags->zero = 0;
	if (flags->plus == 1)
		flags->space = 0;
}

void	ft_parse_flags(const char *format, int *i, t_flags *flags)
{
	(*i)++;
	ft_parse_bonus_flags(format, i, flags);
	while (ft_isdigit(format[*i]))
	{
		flags->width = (flags->width * 10) + (format[*i] - '0');
		(*i)++;
	}
	if (format[*i] == '.')
	{
		flags->dot = 1;
		flags->zero = 0;
		(*i)++;
		while (ft_isdigit(format[*i]))
		{
			flags->precision = (flags->precision * 10) + 
				(format[*i] - '0');
			(*i)++;
		}
	}
}
