/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:53:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/08 18:17:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	get_flags() sets the env parameters according to the given flags, and 
**	increments the format[] index upon success.
**	Called from the directive() function.
*/
int	get_flags(const char *restrict format, t_env *e)
{
	if (format[e->index] == '#')
		e->alt = 1;
	else if (format[e->index] == '0')
		e->zero = 1;
	else if (format[e->index] == '-')
//	{
//		e->zero = 0;
		e->neg = 1;
//	}
	else if (format[e->index] == ' ')
//	{
//		if (!e->plus)
			e->space = 1;
//		else
//			e->space = 0;
//	}
	else if (format[e->index] == '+')
//	{
//		if (e->space)
//			e->space = 0;
		e->plus = 1;
//	}
	else
		return (1);
	return (0);
}

/*
**	manage_flags() implements the effect of the flag by setting s_env
**	variables affecting the ouput accoringly.
**	Called from the convert_--() functions.
*/
int		manage_flags(int ispos, t_env *e)
{
//	printf("precisflag = %d\n", e->precisflag);
	if (e->alt)
	{
		if (ft_strchr("oO", e->conversion) && e->param->u && !e->precision)
		{
			e->precisflag = 1;
			e->precision = 1;
			e->outputlen++;
		}
		if (ft_strchr("xX", e->conversion) && e->param->u)
		{
			ft_putstr(e->xX_prefix);
			e->outpulen += 2;
		}
	}
	if (e->zero && e->conversion != 'n' && !e->neg && !e->precisflag)
	{
//		if (!ft_strcmp("linux", e->os) && !e->param->i)
//			e->zero = 0;
//		else
			e->spacer = '0';
	}
	if (e->space && ft_strchr("dDi", e->conversion) && e->param->i > 0
			&& !e->plus)
	{
		ft_putchar(' ');
		e->outputlen++;
	}
	if (e->plus && ft_strchr("dDi", e->conversion) && e->param->i > 0)
	{
		ft_putchar('+');
		e->outputlen++;
	}
	return (0);
}
