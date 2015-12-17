/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:34:39 by amulin            #+#    #+#             */
/*   Updated: 2015/12/17 18:15:10 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// TO DO : FINIR CETTE VERSION !
//
// Rappel : le lenmod est gere automatiquement par l'union param
//
void	manage_print_all(t_env *e)
{
	if (e->conversion == 'c')
	{
		if (e->mod[0] == 'l' )
			ft_putwchar_t(e->param->wc);
//			ft_print_memory(&(e->param->wc), sizeof(wchar_t));
		else
			ft_putchar(e->param->uc);
		e->outputlen++;
	}
	else if (e->conversion == 'u')
		ft_putnbr_ull(e->param->ull);
	else if (e->conversion == 'd' || e->conversion == 'i')
	{
		if (!e->mod[0])
			ft_putnbr(e->param->i);
		else if (!ft_strcmp(e->mod, "h"))
			ft_putnbr_short(e->param->sh);
		else if (!ft_strcmp(e->mod, "hh"))
			ft_putnbr_char(e->param->sc);
		else
			ft_putnbr_ll(e->param->ll);
	}
	else if (e->conversion == 'o')
	{
//		if (!e->mod[0])
//			ft_putoctal(e->param->u);
//		else if (!ft_strcmp(e->mod, "l"))
			ft_putoctal(e->param->ull);
	}
	else if (e->conversion == 'x')
	{
//		First case (below) is to be replaced with a call to 's' conversion.
		if (!e->param->i && e->alt && e->p_conv && !ft_strcmp("linux", e->os))
			print_null_ptr(e);
		else
			ft_puthex_ull(e->param->ull, "min");
	}
	else if (e->conversion == 'X')
	{
		if (!e->param->i && e->alt && e->p_conv)
			print_null_ptr(e);
		else
			ft_puthex_ull(e->param->ull, "maj");
	}
}

void	print_null_ptr(t_env *e)
{
	if (!e->null_printed)
	{
		ft_putstr(NULL_PTR);
		e->null_printed = 1;
	}
}
