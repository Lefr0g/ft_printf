/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:30 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 15:43:57 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	This function, called from the directive() function, implements the
**	conversion according to the env parameters, taking into account the rules and
**	exceptions specified in the printf(3) manual.
**	A call to va_arg() fetches the value of the next printf() argument into the
**	relevant variable in the e->param->structure according to its type.
**	Then the field width and precision management functions are called, before
**	printing the value on the standard output.
*/
int		convert(va_list *ap, t_env *e)
{
	if (e->conversion == 'd' || e->conversion == 'D' || e->conversion == 'i')
	{
		convert_dDi(ap, e);
	}
	else if (e->conversion == 'u' || e->conversion == 'U')
	{
		convert_uU(ap, e);
	}
	else if (e->conversion == 'c' || e->conversion == 'C')
	{
		convert_cC(ap, e);
	}
	else if (e->conversion == 's' || e->conversion == 'S')
	{
		convert_sS(ap, e);
	}
	else if (e->conversion == 'o' || e->conversion == 'O')
	{
		convert_oO(ap, e);
	}
	else if (e->conversion == 'x' || e->conversion == 'X')
	{
		convert_xX(ap, e);
	}
	else if (e->conversion == 'p')
	{
		e->p_conv = 1;
		e->alt = 1;
		ft_strcpy(e->mod, "l");
		e->conversion = 'x';
		convert_xX(ap, e);
	}
	else if (e->conversion == '%')
	{
		ft_putchar('%');
		e->outputlen++;
	}
	else
		return (-1);
	return (0);
}

/*
**	This function sets the env variables by parsing the current conversion 
**	parameters : flags, field width, precision, lenght modifiers and 
**	conversion specifications.
**	
**	It also checks for invalid directive character, and writes a message on
**	stderr in this case.
**	If the next directive is NOT a conversion specifier, the function calls
**	itself on the next format char and adds the relevant env parameters.
**	Othervise, the flow continues by calling the convert() function.
**	The function returns its current position on the format string.
*/
int	directives(const char *restrict format, va_list *ap, t_env *e)
{
	if (!get_flags(format, e))
		e->index++;
	else if (ft_isdigit(format[e->index]) && format[e->index])
	{
		e->field_width = ft_atoi(&format[e->index]);
		e->index += ft_strlen(ft_itoa(e->field_width));
	}
	else if (format[e->index] == '.')
	{
		e->precisflag = 1;
		if (ft_isdigit(format[e->index + 1]))
		{
			e->precision = ft_atoi(&format[e->index + 1]);
			e->index += ft_strlen(ft_itoa(e->precision)) + 1;
		}
		else
		{
			e->precision = 0;
			e->index++;
		}
	}
	else if (ft_strchr(e->lenmods, format[e->index]))
	{	
		e->mod[0] = format[e->index];
		if (format[e->index] == format[e->index + 1])
		{
			e->mod[1] = format[e->index + 1];
			e->index++;
		}
		e->index++;
	}
//	Mais bordel qu'es-ce que cette evaluation est censee faire avec Linux ?
//	A checker sur Nina
//	VVV
	else if (!ft_strchr(e->conversions, format[e->index]))
	{
//		if (!ft_strcmp(e->os, "linux"))
//			ft_putstr(&format[e->index - 1]);
//		else

//			ft_putendl_fd("\nError : invalid conversion identifier", 2);
//		exit(1);
		{
			ft_putchar(format[e->index]);
			e->outputlen++;
			return (e->index);
		}
	}

	if (ft_strchr(e->conversions, format[e->index]))
	{
		e->conversion = format[e->index];
		convert(ap, e);
	}
	else if (ft_isalpha(format[e->index]) 
			&& !ft_strchr(e->conversions, format[e->index]) 
			&& !ft_strchr(e->lenmods, format[e->index]))
	{
		manage_field_width(e);
		ft_putchar(format[e->index]);
		e->outputlen++;
	}
	else
		directives(format, ap, e);
	return (e->index);
}

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
	if (ft_printf_init(&e))
	{
		ft_putendl_fd("\nError : initialization failed", 2);
		return (1);
	}
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
				directives(format, &ap, &e);
				convlen = convlen + get_max(e.outputlen, e.field_width);

//				printf("'\noutputlen = %d, field width = %d\n",
//						e.outputlen, e.field_width);

				ft_printf_reinit(&e);
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
