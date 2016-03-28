/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:53:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/28 20:40:56 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ftpf_get_flags(const char *restrict format, t_env *e)
{
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
		ftpf_process_flag_alt(e);
	if (e->zero && !e->neg && ((ft_strchr("dDiouxXp", e->conversion)
					&& !e->precisflag) || !e->conversion
				|| ft_strchr("cCsS", e->conversion)))
		e->spacer = FLAG_0_SPACER;
	if (e->zero && e->isneg && e->precisflag)
		e->zero = 0;
	if (e->space && e->conversion && ft_strchr("dDi", e->conversion)
			&& !e->isneg && !e->plus)
	{
		e->outputlen++;
		if (!e->isneg)
			e->precision++;
	}
	if (e->plus && ft_strchr("dDi", e->conversion))
		ftpf_process_flag_plus(e);
	return (0);
}

void	ftpf_process_flag_alt(t_env *e)
{
	if (ft_strchr("oO", e->conversion))
	{
		if (e->param->ul && !e->precision)
			e->precision = e->outputlen + 1;
		else if (!e->precision)
			e->precision++;
		e->precisflag = 1;
	}
	if (ft_strchr("xX", e->conversion))
	{
		if (e->conversion == 'x')
			ft_strcpy(e->x_prefix, "0x");
		else if (e->conversion == 'X')
			ft_strcpy(e->x_prefix, "0X");
		if (!e->isnull)
			e->outputlen += 2;
	}
	else if (e->conversion == 'p')
	{
		ft_strcpy(e->x_prefix, "0x");
		e->outputlen += 2;
	}
}

void	ftpf_process_flag_plus(t_env *e)
{
	if (!e->isneg)
	{
		e->outputlen++;
		if (e->precisflag)
			e->precision++;
	}
	else
		e->plus = 0;
}
