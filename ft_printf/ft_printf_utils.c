/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 19:52:19 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 20:05:48 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	char	*start;

	if (!str)
		write(1, "(NULL)", 6);
		return (6);
	start =  str;
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
	return (str - start);
}

int	ft_print_pct(void)
{
	write(1, "%", 1);
		return (1);
}