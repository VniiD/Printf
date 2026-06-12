/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:49:00 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 15:50:51 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_nbrlen_base(unsigned long long nbr, int base)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

void	ft_putnbr_long(long nbr)
{
	if (nbr >= 10)
		ft_putnbr_long(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
}

void	ft_puthex_long(unsigned long long nbr, char type)
{
	if (nbr >= 16)
		ft_puthex_long(nbr / 16, type);
	if (type == 'X')
		write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		write(1, &"0123456789abcdef"[nbr % 16], 1);
}

int	ft_handle_uint(unsigned int n, t_flags *flags)
{
	if (flags->dot)
		flags->zero = 0;
	return (ft_print_hex_mecanism(n, flags, "", 0));
}