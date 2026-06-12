/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:07:30 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 20:42:08 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	long	nbr;
	int		len;

	len = 0;
	nbr = n;
	if (nbr < 0)
	{
		len += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		len += ft_print_nbr(nbr / 10);
	len += ft_print_char((nbr % 10) + '0');
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += ft_print_char((n % 10 ) + '0');
	return (len);
}