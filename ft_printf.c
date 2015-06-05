/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:30 by amulin            #+#    #+#             */
/*   Updated: 2015/06/05 16:06:14 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(long n, char *mode)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 15)
	{
		ft_puthex(n / 16, mode);
		ft_puthex(n % 16, mode);
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

int	convert(const char *restrict format, va_list ap)
{
	t_param	param;
	int	i;

	i = 1;
	if (format[i] == 'd')
	{
		param.d = (int)va_arg(ap, int);
		ft_putnbr(param.d);
	}
	else if (format[i] == 'c')
	{
		param.c = (unsigned char)va_arg(ap, int);
		ft_putchar(param.c);
	}
	else if (format[i] == 's')
	{
		param.s = (char*)va_arg(ap, char*);
		ft_putstr(param.s);
	}
	else if (format[i] == 'x')
	{
		param.d = (int)va_arg(ap, int);
		ft_puthex(param.d, "min");
	}
	else if (format[i] == 'X')
	{
		param.d = (int)va_arg(ap, int);
		ft_puthex(param.d, "maj");
	}
	else if (format[i] == 'p')
	{
		param.l = (long)va_arg(ap, void*);
		ft_putstr("0x");
		ft_puthex(param.l, "min");
	}
	else if (format[i] == '%')
	{
		param.c = (unsigned char)va_arg(ap, int);
		ft_putchar('%');
	}
	else
		return (-1);
	return (i);
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		j;

	(void)ap;
	(void)format;
	i = 0;
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			if ((j = convert(&format[i], ap)) > 0)
				i = i + j;
			else
			{
				ft_putendl("\nError : invalid conversion identifier");
				exit(1);
			}
		}
		i++;
	}
	va_end(ap);
	return (0);
}
