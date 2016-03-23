/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_bonus_conversions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:09:41 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 21:10:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_convert_b(va_list *ap, t_env *e)
{
	if (!e->mod[0])
	{
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
		e->outputlen = ft_putbin(e->param->u, sizeof(unsigned int));
	}
	else if (!ft_strcmp(e->mod, "hh"))
	{
		e->param->uc = (unsigned char)va_arg(*ap, unsigned int);
		e->outputlen = ft_putbin(e->param->uc, sizeof(unsigned char));
	}
	else if (!ft_strcmp(e->mod, "h"))
	{
		e->param->ush = (unsigned short)va_arg(*ap, unsigned int);
		e->outputlen = ft_putbin(e->param->ush, sizeof(unsigned short));
	}
	else if (e->mod[0] == 'l' || !ft_strcmp(e->mod, "j") ||
			ft_strcmp(e->mod, "z"))
	{
		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
		e->outputlen = ft_putbin(e->param->ull, sizeof(unsigned long long));
	}
}
