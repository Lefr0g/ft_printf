#include "ft_printf.h"

void ft_putoctal(unsigned int n)
{
	if (n > 7)
	{
		ft_putoctal(n / 8);
		ft_putoctal(n % 8);
	}
	else
		ft_putchar(n + '0');
}
