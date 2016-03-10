/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:34:39 by amulin            #+#    #+#             */
/*   Updated: 2016/03/10 18:22:13 by amulin           ###   ########.fr       */
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
		if (e->mod[0] == 'l')
			e->outputlen += ft_putwchar(e->param->wc);
		else
		{
			ft_putchar(e->param->uc);
			e->outputlen++;
		}
	}
	else if (e->conversion == 'u' || e->conversion == 'U')
		ft_putnbr_ull(e->param->ull);
	else if (e->conversion == 'o')
	{
		if (!ft_strcmp(e->mod, "h"))
			ft_putoctal(e->param->ush);
		else if (!ft_strcmp(e->mod, "hh"))
			ft_putoctal(e->param->uc);
		else
			ft_putoctal(e->param->ull);
	}
	else if (e->conversion == 'O')
		ft_putoctal(e->param->ul);
	else if (e->conversion == 'x')
	{
		if (!ft_strcmp(e->mod, "h"))
			ft_puthex_ull(e->param->ush, "min");
		else if (!ft_strcmp(e->mod, "hh"))
			ft_puthex_ull(e->param->uc, "min");
		else
			ft_puthex_ull(e->param->ull, "min");
	}
	else if (e->conversion == 'X')
	{
		if (!ft_strcmp(e->mod, "h"))
			ft_puthex_ull(e->param->ush, "maj");
		else if (!ft_strcmp(e->mod, "hh"))
			ft_puthex_ull(e->param->uc, "maj");
		else
			ft_puthex_ull(e->param->ull, "maj");
	}
	else if (e->conversion == 's')
	{
		if (e->mod[0] == 'l')
			e->outputlen += ft_putwstr(e->param->ws);
		else
		{
			ft_putstr(e->param->s);
			e->outputlen += ft_strlen(e->param->s);
		}
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
