/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:22:26 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/17 14:22:30 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	width;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}	t_flags;

int	ft_printf(const char *format, ...);
int	ft_parse_flags(const char *format, int *i, t_flags *flags, va_list args);
int	ft_handle_print(char specifier, va_list args, t_flags *flags);

int	ft_print_char(char c, t_flags *flags);
int	ft_print_str(char *str, t_flags *flags);
int	ft_print_ptr(unsigned long ptr, t_flags *flags);
int	ft_print_int(int n, t_flags *flags);
int	ft_print_uint(unsigned int n, t_flags *flags);
int	ft_print_hex(unsigned int n, int uppercase, t_flags *flags);

int	ft_putchar_len(char c);
int	ft_putstr_len(char *s, int len);
int	ft_isdigit(int c);
int	ft_strlen(const char *s);

#endif