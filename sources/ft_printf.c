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

#include <stdio.h>

/*
**	Compares 2 ints, returns the biggest
*/
int	get_max(int a, int b)
{
	if (a <= b)
		return (b);
	return (a);
}


void	apply_lenmod(t_env *e, void *arg)
{
	void	*dst;

//	if (!e->mod)
//		return (*(int*)arg);
	dst = ft_memalloc(16);
/*	Ne semble pas fonctionner sans casting en int
 *
	if (sizeof(*arg) != sizeof(int))
	{
		ft_putstr("\nError > argument is not an int\n");
		ft_putstr("sizeof(*arg) = ");
		ft_putnbr(sizeof(*arg));
		ft_putstr(" bytes\n");
		exit(1);
	}
*/

//	printf("Address arg = %p\n", arg);
	
	if (!ft_strcmp(e->mod, "hh"))
	{
		ft_memmove(dst, arg, sizeof(char));
		ft_memcpy(arg, dst, sizeof(int));
	}
	else if (!ft_strcmp(e->mod, "h"))
	{
		ft_memmove(dst, arg, sizeof(short));
		ft_memcpy(arg, dst, sizeof(int));
	}
	else if (!ft_strcmp(e->mod, "l"))
	{
		ft_memmove(dst, arg, sizeof(long));
		ft_memcpy(arg, dst, sizeof(long));
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		ft_memmove(dst, arg, sizeof(long long));
		ft_memcpy(arg, dst, sizeof(long long));
	}

//	printf("\narg = %d, dst = %d\n", *(int*)arg, *(int*)dst);
//	printf("Address arg = %p\n", arg);
}

int		manage_precision(void *value, int outputlen, int isneg, t_env *e)
{
	int	i;

	if (!e->precisflag)
		return (0);
	i = e->precision;
	while (i && i - outputlen > 0)
	{
		if (isneg)
		{
			i++;
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

int		manage_field_width(int outputlen, t_env *e)
{
	int	i;

	i = e->field_width;
	while (i && i - get_max(outputlen, e->precision) > 0)
	{
		ft_putchar(e->spacer);
		i--;
	}
	return (0);
}

/*
**	This function, called from the directive() function, implements the conversion
**	according to the env parameters, taking into account the rules and exceptions
**	specified in the printf(3) manual.
**	A call to va_arg() fetches the value of the next printf() argument into the
**	relevant variable in the param structure according to its type.
**	Then the field width and precision management functions are called, before
**	printing the value on the standard output.
*/
int		convert(va_list *ap, t_env *e)
{
	t_param	param;

	if (e->conversion == 'd' || e->conversion == 'i')
	{
		param.d = (int)va_arg(*ap, int);

//		printf("\nAddress param.d = %p\n", &(param.d));
//		Experimental
		apply_lenmod(e, &(param.d));
		
//		printf("param.d = %d\n", param.d);
//		printf("Address param.d = %p\n", &(param.d));

//

		manage_field_width(ft_strlen(ft_itoa(param.d)), e);
		manage_precision(&(param.d), ft_strlen(ft_itoa(param.d)), (param.d < 0), e);
		ft_putnbr(param.d);
	}
	else if (e->conversion == 'u')
	{
		param.u = (unsigned int)va_arg(*ap, int);
		manage_field_width(ft_strlen(ft_itoa_ll(param.u, 10)), e);
		manage_precision(&(param.u), ft_strlen(ft_itoa_ll(param.u, 10)), 0, e);
		ft_putnbr_ull(param.u);
	}
	else if (e->conversion == 'c')
	{
		param.c = (unsigned char)va_arg(*ap, int);
		ft_putchar(param.c);
	}
	else if (e->conversion == 's')
	{
		param.s = (char*)va_arg(*ap, char*);
		if (ft_strlen(param.s) < (size_t)e->field_width)
			manage_field_width(ft_strlen(param.s), e);
		if (e->precisflag)
			param.s = manage_precision_s(param.s, e);
		ft_putstr(param.s);
	}
	else if (e->conversion == 'o')
	{
		param.u = (unsigned int)va_arg(*ap, int);
		manage_field_width(ft_strlen(ft_itoa_ll(param.u, 8)), e);
		manage_precision(&(param.d), ft_strlen(ft_itoa_ll(param.u, 8)), 0, e);
		ft_putoctal(param.u);
	}
	else if (e->conversion == 'x')
	{
		param.d = (int)va_arg(*ap, int);
		manage_field_width(8, e);
		manage_precision(&(param.d), 8, 0, e);
		ft_puthex(param.d, "min");
	}
	else if (e->conversion == 'X')
	{
		param.d = (int)va_arg(*ap, int);
		manage_field_width(8, e);
		manage_precision(&(param.d), 8, 0, e);
		ft_puthex(param.d, "maj");
	}
	else if (e->conversion == 'p')
	{
		param.l = (unsigned long long int)va_arg(*ap, void*);
		if (!param.l)
			ft_putstr("(nil)");
		else
		{
			ft_putstr("0x");
			ft_puthex_ull(param.l, "min");
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
int	check_flags(const char *restrict format, t_env *e)
{
	int	i;

	i = 0;
	(void)i;
	if (format[e->index] == '#')
		e->alt = 1;
	else if (format[e->index] == '0')
		e->zero = 1;
	else if (format[e->index] == '-')
		e->neg = 1;
	else if (format[e->index] == ' ')
		e->space = 1;
	else if (format[e->index] == '+')
		e->plus = 1;
	else
		return (1);
	e->index++;
	return (0);
}

/*
**	This function sets the env variables according to the relevant flags,
**	field width, precision, lenght modifiers and conversion specifications.
**	It also checks for invalid directive character, and writes a message on
**	stderr in this case.
**	If the next directive is NOT a conversion specifier, the function calls
**	itself on the next format char and adds the relevant env parameters.
**	Othervise, the flow continues by calling the convert() function.
**	The function returns its current position on the format string.
*/
int	directives(const char *restrict format, va_list *ap, t_env *e)
{
	check_flags(format, e);
	if (ft_isdigit(format[e->index]))
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
		if (ft_strchr(e->lenmods, format[e->index + 1]))
		{
			e->mod[1] = format[e->index + 1];
			e->index++;
		}
		e->index++;
	}
	else if (!ft_strchr(e->conversions, format[e->index]))
	{
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
//	if format[i + 1] != e->conversions => recursion
//	else call conversion and print function
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

	ft_printf_init(&e);
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
