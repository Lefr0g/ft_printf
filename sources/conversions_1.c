/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:49:12 by amulin            #+#    #+#             */
/*   Updated: 2015/12/14 14:44:07 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_di(va_list *ap, t_env *e)
{
	int	buf;

	manage_modifiers_di(ap, e);
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

		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 10));
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
		else
			e->param->i = (int)va_arg(*ap, int);
		manage_print_all(e);
	}
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

		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 8));
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

	if (e->conversion == 'x')
		ft_strcpy(e->xX_prefix, "0x");
	else
		ft_strcpy(e->xX_prefix, "0X");
	
	e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 16));

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
	if (e->alt && !e->param->i && e->p_conv)
		print_null_ptr(e);
	if (e->neg && e->alt && ft_strchr("xX", e->conversion) && !e->zero
			&& e->param->i)
		ft_putstr(e->xX_prefix);

	manage_precision(&(e->param->u), 0, e);

	manage_print_all(e);			
	
	if (e->neg)
		manage_field_width(e);
}

void	convert_sS(va_list *ap, t_env *e)
{
	char	*str;

	if (e->conversion == 'S')
	{
		e->conversion = 's';
		e->mod[0] = 'l';
		convert_sS(ap, e);
	}
	else
	{
//		if (e->plus)
//			ft_putendl_fd("\nError : '+' flag used with s conversion", 2);
		str = (char*)va_arg(*ap, char*);
		if (str)
			e->param->s = ft_strdup(str);
		else
			e->param->s = ft_strdup("(null)");
		if (!e->param->s)
			ft_putendl_fd("\nError : string copy failed", 2);
		e->outputlen = ft_strlen(e->param->s);
		if (e->outputlen < e->field_width)
			manage_field_width(e);
		if (e->precisflag)
			e->param->s = manage_precision_s(e->param->s, e);
		ft_putstr(e->param->s);
	}
}
