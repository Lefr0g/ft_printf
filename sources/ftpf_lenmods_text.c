/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_lenmods_text.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:55:05 by amulin            #+#    #+#             */
/*   Updated: 2016/03/26 17:46:52 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_manage_lenmod_c(va_list *ap, t_env *e)
{
	int	len;

	if (!ft_strcmp(e->mod, "l") || e->conversion == 'C')
	{
		e->param->wi = (wint_t)va_arg(*ap, wint_t);
		if (!(len = ft_wchar_utf8len(e->param->wi)))
			e->error = 1;
		else
			e->outputlen += len;
	}
	else
	{
		e->param->u = (unsigned int)va_arg(*ap, unsigned int);
		e->outputlen++;
	}
}

void	ftpf_s_nullexception(t_env *e)
{
	e->mod[0] = 0;
	if (!e->precisflag)
		e->param->s = ft_strdup("(null)");
	else
	{
		e->param->s = ft_strnew(6);
		ft_strncpy(e->param->s, "(null)", e->precision);
	}
	e->isnull = 1;
	e->outputlen += ft_strlen(e->param->s);
}

void	ftpf_manage_lenmod_s(va_list *ap, t_env *e)
{
	char	*str;

	if (!ft_strcmp(e->mod, "l") || e->conversion == 'S')
		ftpf_manage_lenmod_s_wide(ap, e);
	else
	{
		str = (char*)va_arg(*ap, char*);
		if (str)
		{
			e->param->s = ft_strdup(str);
			if (e->precisflag)
				e->param->s[e->precision] = '\0';
			e->outputlen += ft_strlen(e->param->s);
		}
		else
			ftpf_s_nullexception(e);
	}
}

void	ftpf_manage_lenmod_s_wide(va_list *ap, t_env *e)
{
	wchar_t	*wstr;

	wstr = (wchar_t*)va_arg(*ap, wchar_t*);
	if (wstr)
		e->param->ws = (wchar_t*)ft_memalloc(ft_wstr_memsize(wstr) + 4);
	else
		ftpf_s_nullexception(e);
	if (wstr && e->param->ws)
	{
		if (!e->precisflag)
			ft_wcsncpy(e->param->ws, wstr, ft_wcslen(wstr));
		else
			ft_utf8ncpy(e->param->ws, wstr, e->precision);
		e->outputlen += ft_wstr_utf8len(e->param->ws);
	}
}
