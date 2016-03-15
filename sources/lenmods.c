/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:00:44 by amulin            #+#    #+#             */
/*   Updated: 2016/03/15 17:13:25 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_modifiers_dDi(va_list *ap, t_env *e)
{
	if (!e->mod[0] && e->conversion != 'D')
	{
		e->param->i = (int)va_arg(*ap, int);
		if (e->param->i < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa(e->param->i));
	}
	else if (!ft_strcmp(e->mod, "l") || e->conversion == 'D')
	{
		e->param->l = (long)va_arg(*ap, long);	
		if (e->param->l < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa_ll(e->param->l, 10));
	}
	else if (!ft_strcmp(e->mod, "hh"))
	{
		e->param->sc = (int)va_arg(*ap, int);	
		if (e->param->sc < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa(e->param->c));
	}
	else if (!ft_strcmp(e->mod, "h"))
	{
		e->param->sh = (int)va_arg(*ap, int);
		if (e->param->sh < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa(e->param->sh));
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		e->param->ll = (long long)va_arg(*ap, long long);
		if (e->param->ll < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa_ll(e->param->ll, 10));
	}
	else if (!ft_strcmp(e->mod, "j"))
	{
		e->param->imax = (intmax_t)va_arg(*ap, intmax_t);
		if (e->param->imax < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa_ll(e->param->imax, 10));
	}
	else if (!ft_strcmp(e->mod, "z"))
	{
		e->param->l = (long)va_arg(*ap, long);
		if (e->param->l < 0)
			e->isneg = 1;
		e->outputlen = ft_strlen(ft_itoa_ll(e->param->l, 10));
	}
}

void	manage_modifiers_xXp(va_list *ap, t_env *e)
{
	if (!ft_strcmp(e->mod, "hh"))
	{
		e->param->uc = (unsigned char)va_arg(*ap, unsigned int);
		e->outputlen = ft_strlen(ft_itoa_ull(e->param->uc, 16));
	}
	else if (!ft_strcmp(e->mod, "h"))
	{
		e->param->ush = (unsigned short)va_arg(*ap, unsigned int);
		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ush, 16));
	}
	else
	{
		e->param->ul = (unsigned long)va_arg(*ap, unsigned int*);
		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 16));
	}
}
	
	
//	LEGACY
void	manage_modifiers_ouxX(va_list *ap, t_env *e)
{
//	if (!e->mod[0] && !ft_strchr("xXp", e->conversion))
	if (!e->mod[0])
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
//		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (ft_strchr("xXp", e->conversion))
		e->param->ul = (unsigned long)va_arg(*ap, unsigned int*);
	else if (e->conversion == 'O' || e->conversion == 'U' || !ft_strcmp(e->mod, "l"))
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
	else if (!ft_strcmp(e->mod, "hh"))
		e->param->uc = (unsigned char)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(e->mod, "h"))
		e->param->ush = (unsigned short)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(e->mod, "ll"))
		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (!ft_strcmp(e->mod, "j"))
		e->param->uimax = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(e->mod, "z"))
		e->param->st = (size_t)va_arg(*ap, size_t);
}
