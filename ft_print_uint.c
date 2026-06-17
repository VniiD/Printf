//cabeçalho

#include "ft_printf.h"

static int	ft_get_uint_len(unsigned int n, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		return (0);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_write_uint(unsigned int n, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		return (0);
	if (n >= 10)
		len += ft_write_uint(n / 10, flags);
	len += ft_putchar_len((n % 10) + '0');
	return (len);
}

static int	ft_pad_uint(unsigned int n, int num_len, t_flags *flags)
{
	int	len;
	int	zeros;
	int	spaces;

	zeros = 0;
	if (flags->precision > num_len)
		zeros = flags->precision - num_len;
	else if (flags->zero && !flags->dot && flags->width > num_len)
		zeros = flags->width - num_len;
	spaces = flags->width - num_len - zeros;
	len = 0;
	while (!flags->minus && spaces-- > 0)
		len += ft_putchar_len(' ');
	while (zeros-- > 0)
		len += ft_putchar_len('0');
	len += ft_write_uint(n, flags);
	while (flags->minus && spaces-- > 0)
		len += ft_putchar_len(' ');
	return (len);
}

int	ft_print_uint(unsigned int n, t_flags *flags)
{
	int	num_len;

	num_len = ft_get_uint_len(n, flags);
	return (ft_pad_uint(n, num_len, flags));
}
