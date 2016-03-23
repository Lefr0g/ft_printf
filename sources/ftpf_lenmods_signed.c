/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:00:44 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 21:55:55 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_manage_lenmod_di(va_list *ap, t_env *e)
{
	char	*itoa_ret;

	itoa_ret = NULL;
	if (!e->mod[0] && e->conversion != 'D')
	{
		if ((e->param->i = (int)va_arg(*ap, int)) < 0)
			e->isneg = 1;
		itoa_ret = ft_itoa(e->param->i);
	}
	else if (!ft_strcmp(e->mod, "l") || e->conversion == 'D')
	{
		if ((e->param->l = (long)va_arg(*ap, long)) < 0)
			e->isneg = 1;
		itoa_ret = ft_itoa_ll(e->param->l, 10);
	}
	else if (!ft_strcmp(e->mod, "hh"))
	{
		if ((e->param->sc = (int)va_arg(*ap, int)) < 0)
			e->isneg = 1;
		itoa_ret = ft_itoa(e->param->sc);
	}
	else
		ftpf_manage_lenmod_di_sub(ap, e, &itoa_ret);
	if (itoa_ret && (e->outputlen = ft_strlen(itoa_ret)))
		ft_strdel(&itoa_ret);
}

void	ftpf_manage_lenmod_di_sub(va_list *ap, t_env *e, char **itoa_ret)
{
	if (!ft_strcmp(e->mod, "h"))
	{
		if ((e->param->sh = (int)va_arg(*ap, int)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa(e->param->sh);
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		if ((e->param->ll = (long long)va_arg(*ap, long long)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->ll, 10);
	}
	else if (!ft_strcmp(e->mod, "j"))
	{
		if ((e->param->imax = (intmax_t)va_arg(*ap, intmax_t)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->imax, 10);
	}
	else if (!ft_strcmp(e->mod, "z"))
	{
		if ((e->param->l = (long)va_arg(*ap, long)) < 0)
			e->isneg = 1;
		*itoa_ret = ft_itoa_ll(e->param->l, 10);
	}
}
