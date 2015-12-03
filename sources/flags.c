/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:53:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/02 15:03:14 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	{
		e->zero = 0;
		e->neg = 1;
	}
	else if (format[e->index] == ' ')
		e->space = 1;
	else if (format[e->index] == '+')
	{
		if (e->space)
			e->space = 0;
		e->plus = 1;
	}
	else
		return (1);
	e->index++;
	return (0);
}

/*
**	manage_flags() implements the effect of the flag by setting s_env
**	variables affecting the ouput accoringly.
**	Called from the convert_--() functions.
*/
int		manage_flags(int ispos, t_env *e)
{
	if (e->zero)
	{
		if (!e->neg && ft_strchr("diouxX", e->conversion))
			e->spacer = '0';
	}
	if (e->alt)
	{
		if (e->conversion == 'x' || e->conversion == 'X')
			e->outputlen += 2;
		else if (e->conversion == 'o')
		{
			e->precisflag = 1;
			e->precision = ft_strlen(ft_itoa_ll(e->param->ull, 8)) + 1;
		}
	}
	if (e->plus && (e->conversion == 'd' || e->conversion == 'i' 
			|| e->conversion == 'p'))
	{
		if (ispos)
			e->outputlen++;
	}
	return (0);
}