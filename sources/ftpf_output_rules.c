/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_output_rules.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:09:13 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 21:26:35 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function modifies the 'raw' values of precision and outputlen
**	to make them consistant with each other.
**	These raw values must be processed in order to obtain the desired
**	effect.
*/

void	ftpf_process_output_rules(t_env *e)
{
	int	buf;

	if ((ft_strchr("xX", e->conversion) && e->alt && !e->isnull))
		e->precision += 2;
	if (e->conversion == 'p')
		e->precision += 2;
	if (e->conversion && e->precision >= e->outputlen)
	{
		buf = e->outputlen;
		e->outputlen = e->precision;
		if (e->isneg)
			e->outputlen++;
		e->precision = e->outputlen - buf;
	}
	else if (e->precisflag && !e->param->ll && !ft_strchr("cC", e->conversion))
		e->outputlen = 0;
	else
		e->precision = 0;
}

int		ftpf_manage_field_width(t_env *e)
{
	int	i;

	i = e->field_width;
	if (e->zero && e->isneg && !e->precision)
	{
		ft_putchar(FW_MINUS);
		e->isneg = !e->isneg;
	}
	while (i && i - ft_getmax(e->outputlen, e->precision) > 0)
	{
		if (DEBUG_MODE)
			ft_putchar('w');
		else
			ft_putchar(e->spacer);
		i--;
	}
	return (0);
}

int		ftpf_manage_precision(void *value, t_env *e)
{
	int	i;

	if (ft_strchr("dDi", e->conversion) && e->plus && !e->isneg)
	{
		ft_putchar(PRECIS_PLUS);
		e->plus = 0;
	}
	if (!e->precisflag || e->noconv)
		return (0);
	i = e->precision;
	while (i)
	{
		if (e->isneg && !(e->isneg = 0))
			ft_putchar(PRECIS_MINUS);
		else
		{
			if (!ft_strcmp("linux", e->os) && !value)
				ft_putchar(' ');
			else
				ft_putchar(PRECIS_ZERO);
			i--;
		}
	}
	return (0);
}
