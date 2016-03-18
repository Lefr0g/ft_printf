/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenmods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:00:44 by amulin            #+#    #+#             */
/*   Updated: 2016/03/18 20:32:42 by amulin           ###   ########.fr       */
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
		e->outputlen = ft_strlen(ft_itoa(e->param->sc));
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
	if (ft_strchr("xX", e->conversion) && e->mod[0] == 'h')
	{
		if (!ft_strcmp(e->mod, "hh"))
		{
			if (!(e->param->uc = (unsigned char)va_arg(*ap, unsigned int)))
				e->isnull = 1;
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->uc, 16));
		}
		else if (!ft_strcmp(e->mod, "h"))
		{
			if (!(e->param->ush = (unsigned short)va_arg(*ap, unsigned int)))
				e->isnull = 1;
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->ush, 16));
		}
	}
	else
	{
		if (!(e->param->ul = (unsigned long)va_arg(*ap, unsigned int*)))
			e->isnull = 1;
		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 16));
	}
}

void	manage_modifiers_cC(va_list *ap, t_env *e)
{
	if (!ft_strcmp(e->mod, "l") || e->conversion == 'C')
	{
		e->param->wi = (wint_t)va_arg(*ap, wint_t);
		e->outputlen += ft_wchar_utf8len(e->param->wi);
	}
	else
	{
		e->param->i = (int)va_arg(*ap, int);
		e->outputlen++;
	}
}

void	ftpf_sS_nullexception(t_env *e)
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

void	manage_modifiers_sS(va_list *ap, t_env *e)
{
	char	*str;
	wchar_t	*wstr;
	
	if (!ft_strcmp(e->mod, "l") || e->conversion == 'S')
	{
		wstr = (wchar_t*)va_arg(*ap, wchar_t*);
		if (wstr)
			e->param->ws = (wchar_t*)ft_memalloc(ft_wstr_memsize(wstr) + 4);
		else
			ftpf_sS_nullexception(e);
		if (wstr && e->param->ws)
		{
			if (!e->precisflag)
				ft_wcsncpy(e->param->ws, wstr, ft_wcslen(wstr));
			else
				ft_utf8ncpy(e->param->ws, wstr, e->precision);
			e->outputlen += ft_wstr_utf8len(e->param->ws);
		}
	}
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
			ftpf_sS_nullexception(e);
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
