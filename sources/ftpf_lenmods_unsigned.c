/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_lenmods_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:30:56 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 22:18:29 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_manage_lenmod_u(va_list *ap, t_env *e)
{
	char	*itoa_ret;

	itoa_ret = NULL;
	if (!e->mod[0] && e->conversion != 'U')
	{
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
		itoa_ret = ft_itoa_ull(e->param->u, 10);
	}
	else if (!ft_strcmp(e->mod, "l") || e->conversion == 'U')
	{
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
		itoa_ret = ft_itoa_ull(e->param->ul, 10);
	}
	else if (!ft_strcmp(e->mod, "hh"))
	{
		e->param->uc = (unsigned int)va_arg(*ap, unsigned int);
		itoa_ret = ft_itoa_ull(e->param->uc, 10);
	}
	else
		ftpf_manage_lenmod_u_sub(ap, e, &itoa_ret);
	e->outputlen = ft_strlen(itoa_ret);
	if (itoa_ret)
		ft_strdel(&itoa_ret);
}

void	ftpf_manage_lenmod_u_sub(va_list *ap, t_env *e, char **itoa_ret)
{
	if (!ft_strcmp(e->mod, "h"))
	{
		e->param->ush = (unsigned int)va_arg(*ap, unsigned int);
		*itoa_ret = ft_itoa_ull(e->param->ush, 10);
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
		*itoa_ret = ft_itoa_ull(e->param->ull, 10);
	}
	else if (!ft_strcmp(e->mod, "j"))
	{
		e->param->imax = (uintmax_t)va_arg(*ap, uintmax_t);
		*itoa_ret = ft_itoa_ull(e->param->imax, 10);
	}
	else if (!ft_strcmp(e->mod, "z"))
	{
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
		*itoa_ret = ft_itoa_ull(e->param->ul, 10);
	}
}

void	ftpf_manage_lenmod_o(va_list *ap, t_env *e)
{
	char	*itoa_ret;

	itoa_ret = NULL;
	if (!e->mod[0] && e->conversion != 'O')
	{
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
		itoa_ret = ft_itoa_ull(e->param->u, 8);
	}
	else if (!ft_strcmp(e->mod, "l") || e->conversion == 'O')
	{
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
		itoa_ret = ft_itoa_ull(e->param->ul, 8);
	}
	else if (!ft_strcmp(e->mod, "hh"))
	{
		e->param->uc = (unsigned int)va_arg(*ap, unsigned int);
		itoa_ret = ft_itoa_ull(e->param->uc, 8);
	}
	else
		ftpf_manage_lenmod_o_sub(ap, e, &itoa_ret);
	e->outputlen = ft_strlen(itoa_ret);
	if (itoa_ret)
		ft_strdel(&itoa_ret);
}

void	ftpf_manage_lenmod_o_sub(va_list *ap, t_env *e, char **itoa_ret)
{
	if (!ft_strcmp(e->mod, "h"))
	{
		e->param->ush = (unsigned int)va_arg(*ap, unsigned int);
		*itoa_ret = ft_itoa_ull(e->param->ush, 8);
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
		*itoa_ret = ft_itoa_ull(e->param->ull, 8);
	}
	else if (!ft_strcmp(e->mod, "j"))
	{
		e->param->imax = (uintmax_t)va_arg(*ap, uintmax_t);
		*itoa_ret = ft_itoa_ull(e->param->imax, 8);
	}
	else if (!ft_strcmp(e->mod, "z"))
	{
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
		*itoa_ret = ft_itoa_ull(e->param->ul, 8);
	}
}
