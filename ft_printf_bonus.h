#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
    int minus;
    int zero;
    int dot;
    int precision;
    int width;
    int hash;
    int space;
    int plus;
}   t_flags;

int ft_printf(const char *format, ...);

t_flags ft_init_flags(void);

int ft_pad_width(int width, int len, int has_zero);

int ft_print_char_bonus(int c, t_flags flags);
int ft_print_str_bonus(char *str, t_flags flags);
int ft_print_nbr_bonus(long n, t_flags flags);
int ft_print_hex_bonus(unsigned int num, int is_upper, t_flags flags);
int ft_print_ptr_bonus(unsigned long long ptr, t_flags flags);

int ft_putchar_len(int c);
int ft_putstr_len(char *str);

#endif