/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:00:44 by amulin            #+#    #+#             */
/*   Updated: 2015/12/02 19:08:04 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_modifiers_ouxX(va_list *ap, t_env *e)
{
	if (!e->mod[0])
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(e->mod, "hh"))
		e->param->uc = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(e->mod, "h"))
		e->param->ush = (unsigned int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(e->mod, "l"))
		e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
	else if (!ft_strcmp(e->mod, "ll"))
		e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (!ft_strcmp(e->mod, "j"))
		e->param->uimax = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(e->mod, "z"))
		e->param->st = (size_t)va_arg(*ap, size_t);
}
