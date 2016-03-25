/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_text_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:49:12 by amulin            #+#    #+#             */
/*   Updated: 2016/03/25 17:01:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_convert_c(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_c(ap, e);
	ftpf_process_flags(e);
	e->precision = 0;
	ftpf_process_output_rules(e);
	if (!e->neg)
		ftpf_manage_field_width(e);
	if (!ft_strcmp(e->mod, "l") || e->conversion == 'C')
		ft_putwchar(e->param->wc);
	else
		ft_putchar(e->param->uc);
	if (e->neg)
		ftpf_manage_field_width(e);
	if (e->error)
	{
		e->outputlen = -1;
		e->field_width = -1;
	}
}

void	ftpf_convert_s(va_list *ap, t_env *e)
{
	ftpf_manage_lenmod_s(ap, e);
	ftpf_process_flags(e);
	e->precision = 0;
	ftpf_process_output_rules(e);
	if (!e->neg)
		ftpf_manage_field_width(e);
	if ((!ft_strcmp(e->mod, "l") || e->conversion == 'S') && !(e->isnull))
	{
		ft_putwstr(e->param->ws);
		ft_memdel((void**)&e->param->ws);
	}
	else
	{
		ft_putstr(e->param->s);
		ft_memdel((void**)&e->param->s);
	}
	if (e->neg)
		ftpf_manage_field_width(e);
}
