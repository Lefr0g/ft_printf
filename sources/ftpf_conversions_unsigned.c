/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_unsigned_conversions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:49:04 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 16:18:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_convert_u(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_u(ap, e);
	if (e->precisflag && !e->precision && !e->param->ull)
		e->noconv = 1;
	ftpf_process_flags(e);
	ftpf_process_output_rules(e);
	if (!e->neg)
		ftpf_manage_field_width(e);
	ftpf_manage_precision(&(e->param->ull), e);
	if (!e->noconv)
		ft_putnbr_ull(e->param->ull);
	if (e->neg)
		ftpf_manage_field_width(e);
}

void	ftpf_write_o_param(t_env *e)
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

void	ftpf_convert_o(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_o(ap, e);
	if (e->precisflag && !e->precision && !e->param->ull && !e->alt)
		e->noconv = 1;
	ftpf_process_flags(e);
	ftpf_process_output_rules(e);
	if (!e->neg)
		ftpf_manage_field_width(e);
	ftpf_manage_precision(&(e->param->ull), e);
	if (!e->noconv)
		ftpf_write_o_param(e);
	if (e->neg)
		ftpf_manage_field_width(e);
}

void	ftpf_convert_xp(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_xp(ap, e);
	ftpf_process_flags(e);
	if (e->precisflag && !e->precision && e->isnull)
		e->noconv = 1;
	ftpf_process_output_rules(e);
	if (e->zero && !e->precisflag && ((ft_strchr("xX", e->conversion)
					&& e->alt && !e->isnull) || e->conversion == 'p'))
		ft_putstr(e->x_prefix);
	if (!e->neg)
		ftpf_manage_field_width(e);
	if ((!e->zero || e->precisflag) && ((ft_strchr("xX", e->conversion)
					&& e->alt && !e->isnull) || e->conversion == 'p'))
		ft_putstr(e->x_prefix);
	ftpf_manage_precision(&(e->param->ll), e);
	if (!e->noconv)
		ftpf_write_xp_param(e);
	if (e->neg)
		ftpf_manage_field_width(e);
	if (e->noconv && e->conversion == 'p' && !e->outputlen)
		e->outputlen += 2;
}

void	ftpf_write_xp_param(t_env *e)
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
