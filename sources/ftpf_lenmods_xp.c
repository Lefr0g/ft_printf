/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_lenmods_xp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 22:14:29 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 22:17:38 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_manage_lenmod_xp(va_list *ap, t_env *e)
{
	char	*itoa_ret;

	itoa_ret = NULL;
	if (ft_strchr("xX", e->conversion) && e->mod[0] == 'h')
	{
		if (!ft_strcmp(e->mod, "hh"))
		{
			if (!(e->param->uc = (unsigned char)va_arg(*ap, unsigned int)))
				e->isnull = 1;
			itoa_ret = ft_itoa_ull(e->param->uc, 16);
		}
		else if (!ft_strcmp(e->mod, "h"))
		{
			if (!(e->param->ush = (unsigned short)va_arg(*ap, unsigned int)))
				e->isnull = 1;
			itoa_ret = ft_itoa_ull(e->param->ush, 16);
		}
	}
	else
		ftpf_manage_lenmod_xp_sub(ap, e, &itoa_ret);
	e->outputlen = ft_strlen(itoa_ret);
	if (itoa_ret)
		ft_strdel(&itoa_ret);
}

void	ftpf_manage_lenmod_xp_sub(va_list *ap, t_env *e, char **itoa_ret)
{
	if (ft_strchr("xX", e->conversion) && !e->mod[0])
	{
		if (!(e->param->u = (unsigned int)va_arg(*ap, unsigned int*)))
			e->isnull = 1;
		*itoa_ret = ft_itoa_ull(e->param->u, 16);
	}
	else
	{
		if (!(e->param->ul = (unsigned long)va_arg(*ap, unsigned int*)))
			e->isnull = 1;
		*itoa_ret = ft_itoa_ull(e->param->ul, 16);
	}
}
