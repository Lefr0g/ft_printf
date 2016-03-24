/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_directives.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 18:57:05 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 16:16:20 by amulin           ###   ########.fr       */
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
		e->index++;
	ftpf_get_field_width(format, ap, e);
	if (format[e->index] == '.')
		ftpf_get_precision(format, ap, e);
	if (ft_strchr(e->lenmods, format[e->index]))
	{
		e->mod[0] = format[e->index];
		if (format[e->index] == format[e->index + 1])
		{
			e->mod[1] = format[e->index + 1];
			e->index++;
		}
		e->index++;
	}
	ftpf_directives_action(format, ap, e);
	return (e->index);
}

void	ftpf_get_field_width(const char *restrict format, va_list *ap, t_env *e)
{
	char	*itoa_ret;

	if (ft_isdigit(format[e->index]) && format[e->index] != '0')
	{
		e->field_width = ft_atoi(&format[e->index]);
		itoa_ret = ft_itoa(e->field_width);
		e->index += ft_strlen(itoa_ret);
		ft_strdel(&itoa_ret);
	}
	else if (format[e->index] == '*')
	{
		e->field_width = (int)va_arg(*ap, int);
		if (e->field_width < 0)
		{
			e->neg = 1;
			e->field_width = -e->field_width;
		}
		e->index++;
	}
}

void	ftpf_directives_action(const char *restrict f, va_list *ap, t_env *e)
{
	if (ft_strchr(e->conversions, f[e->index]))
	{
		e->conversion = f[e->index];
		e->conversion_function = e->conv_funct_table[e->conversion];
		(*e->conversion_function)(ap, e);
	}
	else if (!ft_isdigit(f[e->index]) && f[e->index] != '*'
			&& !ft_strchr(e->flags, f[e->index])
			&& !ft_strchr(e->conversions, f[e->index])
			&& !ft_strchr(e->lenmods, f[e->index]))
		ftpf_wrongchar_handler(f, e);
	else
		ftpf_directives(f, ap, e);
}

void	ftpf_get_precision(const char *restrict format, va_list *ap, t_env *e)
{
	char	*itoa_ret;

	e->precisflag = 1;
	if (ft_isdigit(format[e->index + 1]))
	{
		e->precision = ft_atoi(&format[e->index + 1]);
		itoa_ret = ft_itoa(e->precision);
		e->index += ft_strlen(itoa_ret);
		ft_strdel(&itoa_ret);
	}
	else if (format[e->index + 1] == '*')
	{
		e->precision = (int)va_arg(*ap, int);
		if (e->precision < 0)
		{
			e->precision = 0;
			e->precisflag = 0;
		}
		e->index++;
	}
	else
		e->precision = 0;
	e->index++;
}

void	ftpf_wrongchar_handler(const char *restrict format, t_env *e)
{
	ftpf_process_flags(e);
	e->precision = 0;
	e->outputlen = 1;
	ftpf_process_output_rules(e);
	if (!e->neg)
		ftpf_manage_field_width(e);
	ftpf_manage_precision(NULL, e);
	ft_putwchar(format[e->index]);
	if (e->neg)
		ftpf_manage_field_width(e);
}
