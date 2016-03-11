/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:30 by amulin            #+#    #+#             */
/*   Updated: 2016/03/11 16:33:28 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	ft_printf() entry point
**	Uses stdarg library for variable arguments list
**	Calls to va_arg() are made within the convert() function, which is itself
**	called from the directives() function.
**	The main loop works as follow :
**		1/ The env structure and the ap va_list are initialized
**		2/ The loop runs for each char in the format string
**			2.1/ Any character except the conversion specifier % are printed as is
**			2.2/ If % is encountered, the directive() function is called on the
**				 next character.
**			2.3/ If the directive() function has been called, then env is
**				 reinitialized.
**		3/ Once the entire format string has been parsed, va_end() is called,
**		   and the function ends.
*/
int	ft_printf(const char *restrict format, ...)
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
		{
			e.index++;
			if (format[e.index])
			{
				ftpf_directives(format, &ap, &e);
				convlen += get_max(e.outputlen, e.field_width);

//				printf("'\noutputlen = %d, field width = %d\n",
//						e.outputlen, e.field_width);

				ftpf_reinit_env(&e);
			}
			else
				return (step + convlen);
		}
		e.index++;
	}
	va_end(ap);
//	ft_putstr(format);
//	ft_putendl("|");
//	printf("'\nstep = %d, convlen = %d\n", step, convlen);
	return (step + convlen);
}
