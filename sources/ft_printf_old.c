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

int	convert(const char *restrict format, va_list *ap)
{
	t_param	param;
	int	i;

	i = 1;
	if (format[i] == 'd')
	{
		param.d = (int)va_arg(*ap, int);
		ft_putnbr(param.d);
	}
	else if (format[i] == 'u')
	{
		param.d = (unsigned int)va_arg(*ap, int);
		ft_putnbr_ull(param.u);
	}
	else if (format[i] == 'c')
	{
		param.c = (unsigned char)va_arg(*ap, int);
		ft_putchar(param.c);
	}
	else if (format[i] == 's')
	{
		param.s = (char*)va_arg(*ap, char*);
		ft_putstr(param.s);
	}
	else if (format[i] == 'o')
	{
		param.d = (unsigned int)va_arg(*ap, int);
		ft_putoctal(param.d);
	}
	else if (format[i] == 'x')
	{
		param.d = (int)va_arg(*ap, int);
		ft_puthex(param.d, "min");
	}
	else if (format[i] == 'X')
	{
		param.d = (int)va_arg(*ap, int);
		ft_puthex(param.d, "maj");
	}
	else if (format[i] == 'p')
	{
		param.l = (unsigned long long int)va_arg(*ap, void*);
		ft_putstr("0x");
		ft_puthex_ull(param.l, "min");
	}
	else if (format[i] == '%')
	{
		param.c = (unsigned char)va_arg(*ap, int);
		ft_putchar('%');
	}
	else
		return (-1);
	return (i);
}
/*
int	check_directive(const char restrict *format, va_list ap)
{
	int		i;

	i = 1;
	if (format[i] == '#')
		alternate(&format[i], ap);
	else if (format[i] == '0')
		zero_padding(&format[i], ap);
	else if (format[i] == '-')
		neg_field_width(&format[i], ap);
	else if (format[i] == ' ')
		blank_pos(&format[i], ap);
	else if (format[i] == '+')
		explicit_sign(&format[i], ap);
	else if (isdigit(format[i]))
		field_width(&format[i], ap);
	else if (format[i] == '.')
		precision(&format[i], ap);
	else if (ft_charinstr(lenmod, format[i]))
		lenght_mod(&format[i], ap);
	else if (ft_charinstr(conversions, format[i]))
		convert(&format[i], ap);
	return (i);
}
*/
int	ft_printf(const char *restrict format, ...)
{
	t_env	e;
	va_list	ap;
	int		i;
	int		j;

	ft_printf_init(&e);
//	(void)ap;
//	(void)format;
	i = 0;
	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else
		{
			if ((j = convert(&format[i], &ap)) > 0)
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
