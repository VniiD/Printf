/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-alme <vde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:18:17 by vde-alme          #+#    #+#             */
/*   Updated: 2026/06/11 16:24:14 by vde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_eval_format(va_list args, const char format);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_pct(void);

#endif