/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:49:12 by amulin            #+#    #+#             */
/*   Updated: 2015/12/04 17:24:37 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_di(va_list *ap, t_env *e)
{
	int	buf;

	if (!e->mod[0])
		e->param->i = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "hh"))
		e->param->sc = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "h"))
		e->param->sh = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "l"))
		e->param->l = (long)va_arg(*ap, long);
	else if (!ft_strcmp(e->mod, "ll"))
		e->param->ll = (long long)va_arg(*ap, long long);
	else if (!ft_strcmp(e->mod, "j"))
		e->param->imax = (intmax_t)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(e->mod, "z"))
		e->param->l = (long)va_arg(*ap, long);

	e->outputlen = ft_strlen(ft_itoa(e->param->i));

//	printf("Precision = %d\n", e->precision);
//	printf("Outpulen = %d\n", e->outputlen);

	if (e->precision > e->outputlen)
	{
		buf = e->outputlen;
		e->outputlen = e->precision;
		if (e->param->i < 0)
			e->outputlen++;
		e->precision = e->outputlen - buf;
	}
	else
		e->precisflag = 0;

//	printf("Field Width = %d\n", e->field_width);
//	printf("\ne->neg = %d\n", e->neg);
//	printf("\ne->zero = %d\n", e->zero);
//	printf("Precision = %d\n", e->precision);
//	printf("Outpulen = %d\n", e->outputlen);
	
	manage_flags((e->param->i > 0), e);
	
	if (!e->neg)
		manage_field_width(e);

	manage_precision(&(e->param->i), (e->param->i < 0), e);

	if (e->plus && e->param->i > 0)
		ft_putchar('+');

	manage_print_all(e);

	if (e->neg)
		manage_field_width(e);
}

void	convert_uU(va_list *ap, t_env *e)
{
	int	buf;
	if (e->conversion == 'U')
	{
		e->conversion = 'u';
		e->mod[0] = 'l';
		convert_uU(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		e->outputlen = ft_strlen(ft_itoa_ll(e->param->u, 10));
		if (e->precision > e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else
			e->precisflag = 0;

//		printf("Precision = %d\n", e->precision);
//		printf("Outpulen = %d\n", e->outputlen);

		manage_flags(1, e);
		
		if (!e->neg)
			manage_field_width(e);

		manage_precision(&(e->param->u), 0, e);

		manage_print_all(e);
		
		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_cC(va_list *ap, t_env *e)
{
	if (e->conversion == 'C')
	{
		e->conversion = 'c';
		e->mod[0] = 'l';
		convert_cC(ap, e);
	}
	else
	{
		if (e->mod[0] == 'l')
			e->param->wi = (wint_t)va_arg(*ap, wint_t);
		e->param->i = (int)va_arg(*ap, int);
	}
	manage_print_all(e);
}

void	convert_oO(va_list *ap, t_env *e)
{
	int	buf;

	if (e->conversion == 'O')
	{
		e->conversion = 'o';
		e->mod[0] = 'l';
		convert_oO(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		e->outputlen = ft_strlen(ft_itoa_ll(e->param->u, 8));
		if (e->precision > e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else
			e->precisflag = 0;

		manage_flags(0, e);
	
		if (!e->neg)
			manage_field_width(e);

		manage_precision(&(e->param->u), 0, e);

		manage_print_all(e);
			
		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_xX(va_list *ap, t_env *e)
{
	int	buf;

	manage_modifiers_ouxX(ap, e);

	e->outputlen = ft_strlen(ft_itoa_ll(e->param->u, 16));
	if (e->precision > e->outputlen)
	{
		buf = e->outputlen;
		e->outputlen = e->precision;
		e->precision = e->outputlen - buf;
	}
	else
		e->precisflag = 0;

	manage_flags(0, e);

	if (!e->neg)
		manage_field_width(e);

	if (e->alt && !e->param->i)
		ft_putstr(NULL_PTR);
	else if (e->neg && e->alt && e->conversion == 'x' && !e->zero)
		ft_putstr("0x");
	else if (e->neg && e->alt && e->conversion == 'X' && !e->zero)
		ft_putstr("0X");
	manage_precision(&(e->param->u), 0, e);

	manage_print_all(e);			
	
	if (e->neg)
		manage_field_width(e);	
}
