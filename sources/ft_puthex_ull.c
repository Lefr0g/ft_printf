/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "ft_printf.h"

void	ft_puthex_ull(unsigned long long int n, char *mode)
{
	if (n > 15)
	{
		ft_puthex_ull(n / 16, mode);
		ft_puthex_ull(n % 16, mode);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else if (!ft_strcmp(mode, "min"))
			ft_putchar((n - 10) + 'a');
		else if (!ft_strcmp(mode, "maj"))
			ft_putchar((n - 10) + 'A');
	}
}


