/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_signed_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:46:36 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 21:33:58 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_write_di_param(t_env *e)
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

void	ftpf_convert_di(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_di(ap, e);
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
		ftpf_manage_field_width(e);
	ftpf_manage_precision(&(e->param->ll), e);
	if (!e->noconv)
		ftpf_write_di_param(e);
	if (e->neg)
		ftpf_manage_field_width(e);
}
