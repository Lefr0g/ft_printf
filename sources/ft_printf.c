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

int	convert(va_list *ap, t_env *e)
{
	t_param	param;

	if (e->conversion == 'd')
	{
		param.d = (int)va_arg(*ap, int);
		ft_putnbr(param.d);
	}
	else if (e->conversion == 'u')
	{
		param.d = (unsigned int)va_arg(*ap, int);
		ft_putnbr_ull(param.u);
	}
	else if (e->conversion == 'c')
	{
		param.c = (unsigned char)va_arg(*ap, int);
		ft_putchar(param.c);
	}
	else if (e->conversion == 's')
	{
		param.s = (char*)va_arg(*ap, char*);
		ft_putstr(param.s);
	}
	else if (e->conversion == 'o')
	{
		param.d = (unsigned int)va_arg(*ap, int);
		ft_putoctal(param.d);
	}
	else if (e->conversion == 'x')
	{
		param.d = (int)va_arg(*ap, int);
		ft_puthex(param.d, "min");
	}
	else if (e->conversion == 'X')
	{
		param.d = (int)va_arg(*ap, int);
		ft_puthex(param.d, "maj");
	}
	else if (e->conversion == 'p')
	{
		param.l = (unsigned long long int)va_arg(*ap, void*);
		ft_putstr("0x");
		ft_puthex_ull(param.l, "min");
	}
	else if (e->conversion == '%')
		ft_putchar('%');
	else
		return (-1);
	return (0);
}

int	check_flags(const char *restrict format, t_env *e)
{
	int	i;

	i = 0;
	if (format[e->index] == '#')
		e->alt = 1;
	else if (format[e->index] == '0')
		e->zero = 1;
	else if (format[e->index] == '-')
		e->zero = 1;
	else if (format[e->index] == ' ')
		e->space = 1;
	else if (format[e->index] == '+')
		e->plus = 1;
	else
		return (1);
	e->index++;
	return (0);
}

int	directives(const char *restrict format, va_list *ap, t_env *e)
{
	check_flags(format, e);
	if (ft_isdigit(format[e->index]))
	{
		e->field_width = ft_atoi(&format[e->index]);
		e->index += ft_strlen(ft_itoa(e->field_width)) - 1;
	}
	else if (format[e->index] == '.')
	{
		e->precision = ft_atoi(&format[e->index + 1]);
		e->index += ft_strlen(ft_itoa(e->precision));
	}
	else if (ft_strchr(e->lenmods, format[e->index]))
		e->lenght = format[e->index];
	else if (ft_strchr(e->conversions, format[e->index]))
	{
		e->conversion = format[e->index];
		convert(ap, e);
	}
	else
	{
		ft_putendl("\nError : invalid conversion identifier");
		exit (1);
	}
//	if format[i + 1] != e->conversions => recursion
//	else call conversion and print function
	return (e->index);
}

int	ft_printf(const char *restrict format, ...)
{
	t_env	e;
	va_list	ap;

	ft_printf_init(&e);
	va_start(ap, format);

	while (format[e.index])
	{
		if (format[e.index] != '%')
			ft_putchar(format[e.index]);
		else
		{
			e.index++;
			directives(format, &ap, &e);
		}
		e.index++;
	}
	va_end(ap);
	return (0);
}
