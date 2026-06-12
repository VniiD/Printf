/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 21:36:27 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/12 15:42:40 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_flags
{
	int		dash;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_parse_flags(const char *format, int i, t_flags *flags);
int		ft_parse_digits(const char *format, int i, t_flags *flags);
int		ft_is_conversion(char c);
void	ft_init_flags(t_flags *flags);

int		ft_processor(va_list args, t_flags *flags);
int		ft_print_pad(int total_width, int len, int has_zero);
int		ft_handle_char(char c, t_flags *flags);
int		ft_handle_str(char *str, t_flags *flags);

int		ft_handle_int(int n, t_flags *flags);
int		ft_handle_uint(unsigned int n, t_flags *flags);
int		ft_handle_hex(unsigned int n, t_flags *flags);
int		ft_handle_ptr(unsigned long long ptr, t_flags *flags);

void	ft_putnbr_long(long nbr);
void	ft_puthex_long(unsigned long long nbr, char type);
int		ft_nbrlen_base(unsigned long long nbr, int base);

#endif