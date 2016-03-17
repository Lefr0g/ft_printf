/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:34:39 by amulin            #+#    #+#             */
/*   Updated: 2016/03/17 19:06:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// TO DO : FINIR CETTE VERSION !
//
// Rappel : le lenmod est gere automatiquement par l'union param
//

void	manage_print_all(t_env *e)
{
	if (e->conversion == 'u' || e->conversion == 'U')
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
}

void	print_null_ptr(t_env *e)
{
	if (!e->null_printed)
	{
		ft_putstr(NULL_PTR);
		e->null_printed = 1;
	}
}
