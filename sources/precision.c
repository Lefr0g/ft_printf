/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:09:13 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:58:47 by amulin           ###   ########.fr       */
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
	{
		e->precision += 2;
	}

/*	if (ft_strchr("oO", e->conversion) && e->alt && e->param->ull)
	{
//		ft_putstr("CHECK");
		e->precisflag = 1;
		e->precision++;
	}
*/

//	printf("precision = %d, outputlen = %d\n", e->precision, e->outputlen);
//	printf("isneg = %d\n", e->isneg);
	if (e->conversion && e->precision >= e->outputlen)
	{
		buf = e->outputlen;
		e->outputlen = e->precision;
		if (e->isneg)
			e->outputlen++;
		e->precision = e->outputlen - buf;
//		printf("precision = %d\n", e->precision);
	}
	else if (e->precisflag && !e->param->ll && !ft_strchr("cC", e->conversion))
		e->outputlen = 0;
	else
		e->precision = 0;
//	if (e->space && e->precisflag && e->param->ll)
//	{
//		e->precision++;
//		e->field_width--;
//	}

}

int		manage_field_width(t_env *e)
{
	int	i;


	i = e->field_width;

	if (e->zero && e->isneg && !e->precision)
	{
		ft_putchar(FW_MINUS);
		e->isneg = !e->isneg;
	}

//	if (e->param->i < 0 && e->outputlen <= e->precision && ft_strchr("dDi", e->conversion))
/*
	if (e->zero && e->param->i < 0 && ft_strchr("dDi", e->conversion) && !e->neg
			&& e->outputlen <= e->precision)
	{
		ft_putchar('_');
		e->param->i = -e->param->i;
	}
*/

//	if (ft_strchr("xX", e->conversion) && e->alt && !e->neg && e->spacer == ' '
//			&& i >= 2)
//		i -= ft_strlen(e->xX_prefix);

//	if (ft_strchr("cC", e->conversion) && i)
//		e->outputlen = 1;

//	printf("'\noutputlen = %d, precision = %d, fw = %d, i = %d\n'",
//			e->outputlen, e->precision, e->field_width, i);
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

int		manage_precision(void *value, t_env *e)
{
	int	i;
	
//	printf("plus = %d, isneg = %d\n", e->plus, e->isneg);
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
		if (e->isneg)
		{
			ft_putchar(PRECIS_MINUS);
			e->isneg = 0;
		}
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

/*
char	*manage_precision_s(char *str, t_env *e)
{
	char	*out;
	int		strlen;

	strlen = ft_strlen(str);
	out = ft_strnew(strlen);
	if (strlen > e->precision)
	{
		ft_strncpy(out, str, e->precision);
		ft_strdel(&str);
		return (out);
	}
	return (str);
}
*/
