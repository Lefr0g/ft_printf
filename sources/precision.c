/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:09:13 by amulin            #+#    #+#             */
/*   Updated: 2016/03/02 18:18:39 by amulin           ###   ########.fr       */
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
	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer == '0')
	{
		ft_putstr(e->xX_prefix);
		e->outputlen += ft_strlen(e->xX_prefix);
	}
	else if (e->p_conv && !e->param->i && e->zero && !ft_strcmp("linux", e->os))
		print_null_ptr(e);

	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer == ' '
			&& i >= 2)
		i -= ft_strlen(e->xX_prefix);

	if (ft_strchr("cC", e->conversion) && i)
		e->outputlen = 1;

	if (e->conversion == 's' && !e->neg)
	{
		if (e->mod[0] == 'l')
			i -= ft_wstr_utf8len(e->param->ws);
		else
			i -= ft_strlen(e->param->s);
	}

//	printf("'\noutputlen = %d, precision = %d\n'", e->outputlen, e->precision);
	while (i && i - get_max(e->outputlen, e->precision) > 0)
	{
		ft_putchar(e->spacer);
//		ft_putchar('|');
		i--;
	}
	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer != '0')
	{
//		if (!(!ft_strcmp("linux", e->os) && !e->param->u))
		if (e->param->u || e->p_conv)
		{
			ft_putstr(e->xX_prefix);
			e->outputlen += ft_strlen(e->xX_prefix);
		}
	}

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
			if (!ft_strcmp("linux", e->os) && !e->param->i)
				ft_putchar(' ');
			else
				ft_putchar('0');
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
