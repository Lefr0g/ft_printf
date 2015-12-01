/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:30 by amulin            #+#    #+#             */
/*   Updated: 2015/06/05 16:06:14 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//#include <stdio.h>

/*
**	Compares 2 ints, returns the biggest
*/
int	get_max(int a, int b)
{
	if (a <= b)
		return (b);
	return (a);
}

int		manage_precision(void *value, int isneg, t_env *e)
{
	int	i;

//	printf("Isneg = %d\n", isneg);

	if (!e->precisflag)
		return (0);
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
	return (0);
}

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
	if (e->conversion == 'd' || e->conversion == 'i')
	{
		convert_di(ap, e);
	}
	else if (e->conversion == 'u' || e->conversion == 'U')
	{
		convert_uU(ap, e);
	}
	else if (e->conversion == 'c' || e->conversion == 'C')
	{
		convert_cC(ap, e);
	}
	else if (e->conversion == 's')
	{
//		if (e->plus)
//			ft_putendl_fd("\nError : '+' flag used with s conversion", 2);
		e->param->s = ft_strdup((char*)va_arg(*ap, char*));
		if (!e->param->s)
			ft_putendl_fd("\nError : string copy failed", 2);
		e->outputlen = ft_strlen(e->param->s);
		if (e->outputlen < e->field_width)
			manage_field_width(e);
		if (e->precisflag)
			e->param->s = manage_precision_s(e->param->s, e);
		ft_putstr(e->param->s);
	}
	else if (e->conversion == 'o')
	{
		/*
		e->param->u = (unsigned int)va_arg(*ap, int);
		e->outputlen = ft_strlen(ft_itoa_ll(e->param->u, 8));
		manage_flags(e->param->u > 0, e);
		manage_field_width(e);
		manage_precision(&(e->param->i), 0, e);
		if (e->alt && e->param->u)
			ft_putchar('0');
		ft_putoctal(e->param->u);
		*/
		convert_oO(ap, e);
	}
	else if (e->conversion == 'x' || e->conversion == 'X')
	{
		convert_xX(ap, e);
/*
		e->param->i = va_arg(*ap, int);
		e->outputlen = 8;
		manage_field_width(e);
		manage_precision(&(e->param->i), 0, e);
		if (e->alt && e->param->i)
			ft_putstr("0x");
		ft_puthex(e->param->i, "min");

	}
	else if (e->conversion == 'X')
	{

		e->param->i = (int)va_arg(*ap, int);
		e->outputlen = 8;
		manage_field_width(e);
		manage_precision(&(e->param->i), 0, e);
		if (e->alt && e->param->i)
			ft_putstr("0X");
		ft_puthex(e->param->i, "maj");
*/
	}
	else if (e->conversion == 'p')
	{
		e->param->l = (unsigned long long int)va_arg(*ap, void*);
		if (!e->param->l)
			ft_putstr(NULL_PTR);
		else
		{
			if (e->plus && e->param->l > 0)
				ft_putchar('+');
			ft_putstr("0x");
			ft_puthex_ull(e->param->l, "min");
		}
	}
	else if (e->conversion == '%')
		ft_putchar('%');
	else
		return (-1);
	return (0);
}

/*
**	Sets the env parameters according to the given flags, and increments the
**	format[] index upon success.
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
	get_flags(format, e);
	if (ft_isdigit(format[e->index]) && format[e->index])
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
			e->index += ft_strlen(ft_itoa(e->precision));
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
	else if (!ft_strchr(e->conversions, format[e->index]))
	{
		if (!ft_strcmp(e->os, "linux"))
			ft_putstr(&format[e->index - 1]);
		else
			ft_putendl_fd("\nError : invalid conversion identifier", 2);
		exit(1);
	}

	if (ft_strchr(e->conversions, format[e->index]))
	{
		e->conversion = format[e->index];
		convert(ap, e);
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

	if(ft_printf_init(&e))
	{
		ft_putendl_fd("\nError : invalid conversion identifier", 2);
		return (1);
	}
	va_start(ap, format);

	while (format[e.index])
	{
		if (format[e.index] != '%')
			ft_putchar(format[e.index]);
		else
		{
			e.index++;
			directives(format, &ap, &e);
			ft_printf_reinit(&e);
		}
		e.index++;
	}
	va_end(ap);
	return (0);
}
