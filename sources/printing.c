/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:34:39 by amulin            #+#    #+#             */
/*   Updated: 2015/12/02 19:39:04 by amulin           ###   ########.fr       */
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
//			ft_putchar_wchar_t(e->param->wc);
			ft_putchar(e->param->wc);
		else
			ft_putchar(e->param->c);
	}
	else if (e->conversion == 'u')
		ft_putnbr_ull(e->param->u);
	else if (e->conversion == 'd' || e->conversion == 'i')
	{
		ft_putnbr_ll(e->param->ll);
	}
	else if (e->conversion == 'o')
		ft_putoctal(e->param->u);
	else if (e->conversion == 'x')
	{
		if (e->alt && e->param->i)
			ft_putstr("0x");
		ft_puthex_ull(e->param->ull, "min");
	}
	else if (e->conversion == 'X')
	{
		if (e->alt && e->param->i)
			ft_putstr("0X");
		ft_puthex_ull(e->param->ull, "maj");
	}
}
