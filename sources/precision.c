/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:09:13 by amulin            #+#    #+#             */
/*   Updated: 2015/12/03 20:32:31 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_field_width(t_env *e)
{
	int	i;

	i = e->field_width;
	while (i && i - get_max(e->outputlen, e->precision) > 0)
	{
		ft_putchar(e->spacer);
		i--;
	}
	return (0);
}

int		manage_precision(void *value, int isneg, t_env *e)
{
	int	i;

	if (!e->precisflag)
		return (0);
	if (!e->neg)
		manage_field_width(e);
	i = e->precision;
	if (isneg)
		i++;
	while (i && i - e->outputlen > 0)
	{
		if (isneg)
		{
			ft_putchar('-');
			isneg = 0;
			*(long long int*)value  = -*(long long int*)value;
		}
		else
		{
			ft_putchar('0');
			i--;
		}
	}
	if (e->neg)
		manage_field_width(e);
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
