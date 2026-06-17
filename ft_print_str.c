// cabeçalho

#include "ft_printf.h"

static int	ft_print_str_pad(int pad_len)
{
	int	len;

	len = 0;
	while (len < pad_len)
		len += ft_putchar_len(' ');
	return (len);
}

static char	*ft_get_base_str(char *str, t_flags *flags, int *str_len)
{
	char	*base;

	base = str;
	if (!base)
	{
		if (flags->dot && flags->precision < 6)
			*str_len = 0;
		else
		{
			base = "(null)";
			*str_len = 6;
		}
	}
	else
	{
		*str_len = ft_strlen(base);
		if (flags->dot && flags->precision < *str_len)
			*str_len = flags->precision;
	}
	return (base);
}

int	ft_print_str(char *str, t_flags *flags)
{
	int		len;
	int		str_len;
	char	*base_str;

	len = 0;
	base_str = ft_get_base_str(str, flags, &str_len);
	if (flags->minus == 0)
		len += ft_print_str_pad(flags->width - str_len);
	if (str_len > 0)
		len += ft_putstr_len(base_str, str_len);
	if (flags->minus == 1)
		len += ft_print_str_pad(flags->width - str_len);
	return (len);
}
