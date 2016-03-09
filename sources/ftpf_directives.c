/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_directives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:57:05 by amulin            #+#    #+#             */
/*   Updated: 2016/03/08 19:52:31 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function sets the env variables by parsing the current conversion
**	parameters : flags, field width, precision, lenght modifiers and
**	conversion specifications.
**	---
**	If the next directive is NOT a conversion specifier, the function calls
**	itself on the next format char and adds the relevant env parameters.
**	Othervise, the flow continues by calling the convert() function.
**	The function returns its current position on the format string.
*/

int		ftpf_directives(const char *restrict format, va_list *ap, t_env *e)
{
	if (!ftpf_get_flags(format, e))
	{
		e->index++;
//		printf("Got flags !, index = %d\n", e->index);
	}
	if (ft_isdigit(format[e->index]) && format[e->index] != '0')
	{
		e->field_width = ft_atoi(&format[e->index]);
		e->index += ft_strlen(ft_itoa(e->field_width));
	}
	if (format[e->index] == '.')
		ftpf_get_precision(format, e);
	if (ft_strchr(e->lenmods, format[e->index]))
		ftpf_get_lenmod(format, e);
	if (ft_strchr(e->conversions, format[e->index]))
	{
		e->conversion = format[e->index];
//		convert(ap, e);
		e->conversion_function = e->conv_funct_table[e->conversion];
		(*e->conversion_function)(ap, e);
	}
	else if (ft_isalpha(format[e->index])
			&& !ft_strchr(e->conversions, format[e->index])
			&& !ft_strchr(e->lenmods, format[e->index]))
		ftpf_directive_wrongchar_handler(format, e);
	else
		ftpf_directives(format, ap, e);
	return (e->index);
}

void	ftpf_get_precision(const char *restrict format, t_env *e)
{
	e->precisflag = 1;
	if (ft_isdigit(format[e->index + 1]))
	{
		e->precision = ft_atoi(&format[e->index + 1]);
		e->index += ft_strlen(ft_itoa(e->precision));
	}
	else
		e->precision = 0;
	e->index++;
}

void	ftpf_get_lenmod(const char *restrict format, t_env *e)
{
	e->mod[0] = format[e->index];
	if (format[e->index] == format[e->index + 1])
	{
		e->mod[1] = format[e->index + 1];
		e->index++;
	}
	e->index++;
}

void	ftpf_directive_wrongchar_handler(const char *restrict format, t_env *e)
{
	ftpf_process_flags(e);
	manage_precision((void*)&format[e->index], e->neg, e);
	manage_field_width(e);
	ft_putchar(format[e->index]);
	e->outputlen++;
}

/*
void	(*ftpf_get_conv_func(t_env *e, char conv))(va_list *ap, t_env *e)
{
	e->conversion_function = e->conv_funct_table[conv];
}
*/
