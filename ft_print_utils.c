//Cabeçalho
#include "ft_printf.h"

int ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int ft_print_str(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int ft_print_nbr(int n)
{
	unsigned int    nb;
	int             count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		count += ft_print_nbr(nb / 10);
	count += ft_print_char(nb % 10 + '0');
	return (count);
}

int ft_print_unsigned(unsigned int n)
{
	int count;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char(n % 10 + '0');
	return (count);
}

int ft_print_percent(void)
{
	return (write(1, "%", 1));
}