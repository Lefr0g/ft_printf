/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:53:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/17 18:38:37 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

/*
**	Flags are managed in a 3-steps process :
**		0/	The flags are parsed from format, and the corresponding env
**			variables are set. This is the ftpf_get_flags() function.
**		1/	Once all directives for the current conversion are known,
**			the ftpf_process_flags() function updates the env according
**			to the side effects of these parameters on the flags.
**			The outpulen is also updated during this phase.
**		2/	Finally, the ftpf_apply_flafs() applies the effect of the
**			flags on the output string.
*/

/*
**	get_flags() sets the env parameters according to the given flags, and 
**	increments the format[] index upon success.
**	Called from the directive() function.
*/

int	ftpf_get_flags(const char *restrict format, t_env *e)
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
**	This intermediary step requires all directives to be known
**	at this point.
**	It will check for conflicting flags, and apply the effect of other
**	directives on the output (see man).
*/

int		ftpf_process_flags(t_env *e)
{
	if (e->alt || e->conversion == 'p')
	{
		if (ft_strchr("oO", e->conversion) && e->param->u && !e->precision)
		{
			e->precisflag = 1;
			e->precision = 1;
			e->outputlen++;
		}
		if (ft_strchr("xX", e->conversion))
		{
			if (e->conversion == 'x')
				ft_strcpy(e->xX_prefix, "0x");
			else if (e->conversion == 'X')
				ft_strcpy(e->xX_prefix, "0X");
			if (!e->isnull)
				e->outputlen += 2;
		}
		else if (e->conversion == 'p')
		{
			ft_strcpy(e->xX_prefix, "0x");
			e->outputlen += 2;
		}
	}
//	printf("PROCESS FLAG : zero = %d, conversion = %c, precisflag = %d\n",
//			e->zero, e->conversion, e->precisflag);


//	if (e->zero && !e->neg &&
//			!(ft_strchr("dDiouxX", e->conversion) && e->precisflag))
	if (e->zero && !e->neg && ((ft_strchr("dDiouxXp", e->conversion)
					&& !e->precisflag) || !e->conversion
				|| ft_strchr("cC", e->conversion)))
	{
//		printf("CHECK\n");
		e->spacer = FLAG_0_SPACER;
	}
	if (e->zero && e->isneg && e->precisflag)
		e->zero = 0;

	if (e->space && e->conversion && ft_strchr("dDi", e->conversion) && !e->isneg
			&& !e->plus)
	{
		e->outputlen++;
//		printf("precision = %d, fw = %d\n", e->precision, e->field_width);

//		if (!e->param->ll)
		if (!e->isneg)
			e->precision++;
	}
	if (e->plus && ft_strchr("dDi", e->conversion))
	{
		if (!e->isneg)
		{
			e->outputlen++;
//			if (e->precisflag && !e->noconv)
			if (e->precisflag)
				e->precision++;
		}
		else
			e->plus = 0;
	}
	return (0);
}



/*
**	ftpf_apply_flags() writes the effect of the flags on stdout.
**	TODO : Remove this function as each condition is conversion-specific
*/

int		ftpf_apply_flags(t_env *e)
{
//	printf("precisflag = %d\n", e->precisflag);
	if (e->alt)
	{
		if (ft_strchr("oO", e->conversion) && e->param->u && !e->precision)
			(void)e;
		if (((ft_strchr("xX", e->conversion) && e->alt) || e->conversion == 'p')
				&& e->param->u)
			ft_putstr(e->xX_prefix);
	}
//	if (e->space && ft_strchr("dDi", e->conversion) && e->param->i >= 0
//			&& !e->plus)
//		ft_putchar(' ');
//	if (e->plus && ft_strchr("dDi", e->conversion) && e->param->i >= 0)
//		ft_putchar('+');
	return (0);
}
