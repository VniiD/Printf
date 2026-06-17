//cabeçalho

#include "ft_printf.h"

static int	ft_get_hex_len(unsigned int n, t_flags *flags)
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
		n /= 16;
	}
	return (len);
}

static int	ft_put_prefix(int uppercase, t_flags *flags)
{
	if (flags->hash)
	{
		if (uppercase)
			return (ft_putstr_len("0X", 2));
		return (ft_putstr_len("0x", 2));
	}
	return (0);
}

static int	ft_write_hex(unsigned int n, int uppercase, t_flags *flags)
{
	int	len;

	len = 0;
	if (n == 0 && flags->dot && flags->precision == 0)
		return (0);
	if (n >= 16)
		len += ft_write_hex(n / 16, uppercase, flags);
	if ((n % 16) < 10)
		len += ft_putchar_len((n % 16) + '0');
	else
	{
		if (uppercase)
			len += ft_putchar_len((n % 16) - 10 + 'A');
		else
			len += ft_putchar_len((n % 16) - 10 + 'a');
	}
	return (len);
}

static int	ft_pad_hex(unsigned int n, int uppercase, int len_base, t_flags *f)
{
	int	len;
	int	zeros;
	int	spaces;
	int	hash_len;

	hash_len = (f->hash && n != 0) * 2;
	zeros = 0;
	if (f->precision > len_base)
		zeros = f->precision - len_base;
	else if (f->zero && !f->dot && f->width > (len_base + hash_len))
		zeros = f->width - len_base - hash_len;
	spaces = f->width - len_base - zeros - hash_len;
	len = 0;
	while (!f->minus && (!f->zero || f->dot) && spaces-- > 0)
		len += ft_putchar_len(' ');
	if (n != 0)
		len += ft_put_prefix(uppercase, f);
	while (!f->minus && f->zero && !f->dot && spaces-- > 0)
		len += ft_putchar_len('0');
	while (zeros-- > 0)
		len += ft_putchar_len('0');
	len += ft_write_hex(n, uppercase, f);
	while (f->minus && spaces-- > 0)
		len += ft_putchar_len(' ');
	return (len);
}

int	ft_print_hex(unsigned int n, int uppercase, t_flags *flags)
{
	int	len_base;

	len_base = ft_get_hex_len(n, flags);
	return (ft_pad_hex(n, uppercase, len_base, flags));
}
