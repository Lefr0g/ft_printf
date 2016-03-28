/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:30 by amulin            #+#    #+#             */
/*   Updated: 2016/03/28 20:40:47 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	ft_printf() entry point
**	Uses stdarg library for variable arguments list
**	Calls to va_arg() are made within the convert() function, which is itself
**	called from the directives() function.
**	The main loop works as follow :
**		1/ The env structure and the ap va_list are initialized
**		2/ The loop runs for each char in the format string
**			2.1/ Any character except the conversion specifier % are printed
**				 as is
**			2.2/ If % is encountered, the directive() function is called on the
**				 next character.
**			2.3/ If the directive() function has been called, then env is
**				 reinitialized.
**		3/ Once the entire format string has been parsed, va_end() is called,
**		   and the function ends.
*/

int		ft_printf(const char *restrict format, ...)
{
	t_env	e;
	va_list	ap;
	int		convlen;
	int		step;

	convlen = 0;
	step = 0;
	if (ftpf_init_env(&e))
		return (-1);
	va_start(ap, format);
	while (format[e.index])
	{
		if (format[e.index] != '%')
		{
			ft_putchar(format[e.index]);
			step++;
		}
		else
			ftpf_conversion_call(&e, format, &ap, &convlen);
		e.index++;
	}
	va_end(ap);
	ftpf_free_all(&e);
	return (step + convlen);
}

void	ftpf_conversion_call(t_env *e, const char *restrict format,
		va_list *ap, int *convlen)
{
	e->index++;
	if (format[e->index])
	{
		ftpf_directives(format, ap, e);
		*convlen += ft_getmax(e->outputlen, e->field_width);
		ftpf_reinit_env(e);
	}
	else
	{
		while (format[e->index + 1])
			e->index++;
	}
}
