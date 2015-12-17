/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:09:13 by amulin            #+#    #+#             */
/*   Updated: 2015/12/17 17:07:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		manage_field_width(t_env *e)
{
	int	i;

	i = e->field_width;
	if (e->zero && e->param->i < 0 && ft_strchr("di", e->conversion) && !e->neg)
	{
		ft_putchar('-');
		e->param->i = -e->param->i;
	}
	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer == '0'
			&& e->param->i)
		ft_putstr(e->xX_prefix);
	else if (e->p_conv && !e->param->i && e->zero)
		print_null_ptr(e);
//	printf("\noutputlen = %d, precision = %d\n", e->outputlen, e->precision);
	while (i && i - get_max(e->outputlen, e->precision) > 0)
	{
		ft_putchar(e->spacer);
		i--;
	}
	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer != '0'
			&& e->param->i)
		ft_putstr(e->xX_prefix);
	return (0);
}

int		manage_precision(void *value, int isneg, t_env *e)
{
	int	i;

	if (!e->precisflag)
		return (0);
	i = e->precision;
	while (i)
	{
		if (isneg)
		{
			ft_putchar('-');
			isneg = 0;
			*(long long int*)value  = -*(long long int*)value;
		}
		else
		{
			if (!ft_strcmp(e->os, "linux") && e->param->i)
				ft_putchar(' ');
			else
				ft_putchar('|');
			i--;
		}
	}
	return (0);
}

char	*manage_precision_s(char *str, t_env *e)
{
	char	*out;
	int		strlen;

	strlen = ft_strlen(str);
	out = ft_strnew(strlen);
	if (strlen > e->precision)
	{
		ft_strncpy(out, str, e->precision);
		return (out);
	}
	return (str);
}
