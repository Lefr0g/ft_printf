/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:49:12 by amulin            #+#    #+#             */
/*   Updated: 2016/03/22 17:24:16 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	ftpf_write_dDi_param(t_env *e)
{
	if (e->isneg)
		ft_putchar(CONV_MINUS);
	if (e->param->ll == LLONG_MIN)
		ft_putstr("9223372036854775808");
	else
	{
		if (e->conversion == 'd' || e->conversion == 'i')
		{
			if (!e->mod[0] && e->param->i != INT_MIN)
				ft_putnbr_ll(ft_abs(e->param->i));
			else if (!ft_strcmp(e->mod, "h"))
				ft_putnbr(ft_abs(e->param->sh));
			else if (!ft_strcmp(e->mod, "hh"))
				ft_putnbr(ft_abs(e->param->sc));
			else
				ft_putnbr_ll(ft_abs_ll(e->param->ll));
		}
		else if (e->conversion == 'D')
			ft_putnbr_ll(ft_abs_ll(e->param->ll));
	}
}

void	ftpf_convert_dDi(va_list *ap, t_env *e)
{
	manage_modifiers_dDi(ap, e);
	if (e->precisflag && !e->precision && !e->param->ll)
		e->noconv = 1;
	ftpf_process_flags(e);
	ftpf_process_output_rules(e);
	if (e->space && !e->isneg && !e->plus)
		ft_putchar(' ');
	if (e->plus && !e->isneg && e->zero && !e->precisflag)
	{
		ft_putchar('+');
		e->plus = 0;
	}
	if (e->isneg && e->zero && !e->precisflag)
	{
		ft_putchar('-');
		e->isneg = 0;
	}
	if (!e->neg)
		manage_field_width(e);
	manage_precision(&(e->param->ll), e);
	if (!e->noconv)
		ftpf_write_dDi_param(e);
	if (e->neg)
		manage_field_width(e);
//	free(&e->param->ll);
}


void	ftpf_convert_uU(va_list *ap, t_env *e)
{
	manage_modifiers_uU(ap, e);
	if (e->precisflag && !e->precision && !e->param->ull)
		e->noconv = 1;
	ftpf_process_flags(e);
	ftpf_process_output_rules(e);
	if (!e->neg)
		manage_field_width(e);
	manage_precision(&(e->param->ull), e);
	if (!e->noconv)
		ft_putnbr_ull(e->param->ull);
//		ftpf_write_dDi_param(e);
	if (e->neg)
		manage_field_width(e);
//	free(&e->param->ull);
}

void	ftpf_write_oO_param(t_env *e)
{
	if (e->conversion == 'o')
	{
		if (!ft_strcmp(e->mod, "h"))
			ft_putoctal(e->param->ush);
		else if (!ft_strcmp(e->mod, "hh"))
			ft_putoctal(e->param->uc);
		else
			ft_putoctal(e->param->ull);
	}
	else if (e->conversion == 'O')
		ft_putoctal(e->param->ul);
}

void	ftpf_convert_oO(va_list *ap, t_env *e)
{
	manage_modifiers_oO(ap, e);
	if (e->precisflag && !e->precision && !e->param->ull && !e->alt)
		e->noconv = 1;
	ftpf_process_flags(e);
	ftpf_process_output_rules(e);
	if (!e->neg)
		manage_field_width(e);
	manage_precision(&(e->param->ull), e);
	if (!e->noconv)
		ftpf_write_oO_param(e);
	if (e->neg)
		manage_field_width(e);
//	free(&e->param->ull);
}

//	LEGACY
void	convert_uU(va_list *ap, t_env *e)
{
	int	buf;
	if (e->conversion == 'U' && !e->mod[0])
	{
//		e->conversion = 'u';
		e->mod[0] = 'l';
		convert_uU(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 10));
		if (e->precision > e->outputlen && e->param->u)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else if (e->precisflag && !e->param->u)
			e->outputlen = 0;
		else
			e->precision = 0;

//		printf("Precision = %d\n", e->precision);
//		printf("Outpulen = %d\n", e->outputlen);

		ftpf_process_flags(e);
		
		if (!e->neg)
			manage_field_width(e);

		manage_precision(&(e->param->u), e);

		if (!(e->precisflag && !e->precision && !e->param->i))
			manage_print_all(e);
		
		if (e->neg)
			manage_field_width(e);
	}
}

void	ftpf_convert_cC(va_list *ap, t_env *e)
{
//	printf("CHECK\n");
	manage_modifiers_cC(ap, e);
	ftpf_process_flags(e);
	e->precision = 0;
	ftpf_process_output_rules(e);
	if (!e->neg)
		manage_field_width(e);

	if (!ft_strcmp(e->mod, "l") || e->conversion == 'C')
		ft_putwchar(e->param->wc);
	else
		ft_putchar(e->param->uc);

	if (e->neg)
		manage_field_width(e);
//	free(&e->param->wc);
}


//	LEGACY
void	convert_oO(va_list *ap, t_env *e)
{
	int	buf;
	
	if (e->conversion == 'O' && !e->mod[0])
	{
//		e->conversion = 'o';
		if (!e->mod[0])
			e->mod[0] = 'l';
		convert_oO(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		if (e->param->u || !(e->precisflag && !e->precision) || e->alt)
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 8));

//		printf("Precision = %d, Outputlen = %d\n", e->precision, e->outputlen);

		if (e->precision > e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else
			e->precision = 0;

		ftpf_process_flags(e);
	
		if (!e->neg)
			manage_field_width(e);

//		printf("Precision = %d\n", e->precision);

		manage_precision(&(e->param->u), e);
		
//		if (e->param->ull || e->precisflag)
		if (e->param->u || !(e->precisflag && !e->precision) || e->alt)
			manage_print_all(e);
			
		if (e->neg)
			manage_field_width(e);
	}
}

void	ftpf_write_xXp_param(t_env *e)
{
	if (ft_strchr("xp", e->conversion))
	{
		if (e->conversion == 'x' && !ft_strcmp(e->mod, "h"))
			ft_puthex_ull(e->param->ush, "min");
		else if (e->conversion == 'x' && !ft_strcmp(e->mod, "hh"))
			ft_puthex_ull(e->param->uc, "min");
		else if (e->conversion == 'x' && !e->mod[0])
			ft_puthex_ull(e->param->u, "min");
		else
			ft_puthex_ull(e->param->ull, "min");
	}
	else if (e->conversion == 'X')
	{
		if (!ft_strcmp(e->mod, "h"))
			ft_puthex_ull(e->param->ush, "maj");
		else if (!ft_strcmp(e->mod, "hh"))
			ft_puthex_ull(e->param->uc, "maj");
		else if (!e->mod[0])
			ft_puthex_ull(e->param->u, "maj");
		else
			ft_puthex_ull(e->param->ull, "maj");
	}
}


void	ftpf_convert_xXp(va_list *ap, t_env *e)
{
	manage_modifiers_xXp(ap, e);
//	printf("Precision = %d, Outputlen = %d, Fw = %d\n", e->precision, e->outputlen,
//			e->field_width);
	ftpf_process_flags(e);
	if (e->precisflag && !e->precision && e->isnull)
		e->noconv = 1;
	ftpf_process_output_rules(e);
	
	if (e->zero && !e->precisflag && ((ft_strchr("xX", e->conversion)
					&& e->alt && !e->isnull) || e->conversion == 'p'))
		ft_putstr(e->xX_prefix);

	if (!e->neg)
		manage_field_width(e);

//	printf("conversion = %c, alt = %d, xX_prefix = %s\n", e->conversion, e->alt,
//			e->xX_prefix);

	if ((!e->zero || e->precisflag) && ((ft_strchr("xX", e->conversion)
					&& e->alt && !e->isnull) || e->conversion == 'p'))
		ft_putstr(e->xX_prefix);
	manage_precision(&(e->param->ll), e);
	if (!e->noconv)
		ftpf_write_xXp_param(e);
	if (e->neg)
		manage_field_width(e);
	if (e->noconv && e->conversion == 'p' && !e->outputlen)
		e->outputlen += 2;
//	free(&e->param->ull);
}

void	ftpf_convert_sS(va_list *ap, t_env *e)
{
	manage_modifiers_sS(ap, e);
	ftpf_process_flags(e);
	e->precision = 0;
	ftpf_process_output_rules(e);
	if (!e->neg)
		manage_field_width(e);
	if ((!ft_strcmp(e->mod, "l") || e->conversion == 'S') && !(e->isnull))
	{
		ft_putwstr(e->param->ws);
//		ft_memdel((void**)&e->param->ws);
	}
	else
	{
		ft_putstr(e->param->s);
//		ft_memdel((void**)&e->param->s);
	}
	if (e->neg)
		manage_field_width(e);
//	free(&e->param->ull);
}
