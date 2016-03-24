/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 12:56:31 by amulin            #+#    #+#             */
/*   Updated: 2016/03/24 19:30:32 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftpf_reinit_env(t_env *e)
{
	e->conversion_function = NULL;
	ft_bzero(e->param, sizeof(unsigned long long));
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	ft_bzero(e->mod, 3);
	e->conversion = '\0';
	e->spacer = ' ';
	e->outputlen = 0;
	e->p_conv = 0;
	e->null_printed = 0;
	e->isneg = 0;
	e->isnull = 0;
	e->noconv = 0;
	e->error = 0;
	return (0);
}

/*
**	Detect system OS in order to avoid accepting OSX-only
**	conversion in Linux
**	THIS IS LEGACY CODE AND THERE IS ABSOLUTELY NO GUARANTEE THAT FT_PRINTF
**	WILL STILL BEHAVE (OR EVEN COMPILE) ON LINUX AT THIS POINT
*/

int		ftpf_init_env(t_env *e)
{
	ftpf_init_convfunctions_pointers(e);
	ftpf_init_mallocs(e);
	e->conversion_function = NULL;
	e->index = 0;
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	e->conversion = '\0';
	e->spacer = ' ';
	e->outputlen = 0;
	e->p_conv = 0;
	e->null_printed = 0;
	e->isneg = 0;
	e->isnull = 0;
	e->noconv = 0;
	e->error = 0;
	return (!e->param || !e->lenmods || !e->os || !e->conversions
			|| !e->mod || !e->x_prefix);
}

void	ftpf_init_mallocs(t_env *e)
{
	e->lenmods = ft_strdup("hljz");
	e->flags = ft_strdup("#0- +");
	e->os = ft_strdup(SYS_OS);
	if (!ft_strcmp(e->os, "darwin"))
		e->conversions = ft_strdup("sSpdDioOuUxXcCb");
	else
		e->conversions = ft_strdup("sSpdiouxXcCb");
	e->param = (t_param*)malloc(sizeof(t_param));
	ft_bzero(e->param, sizeof(unsigned long long));
	e->mod = ft_strnew(3);
	e->x_prefix = ft_strnew(3);
}

/*
**	This functions associates each conversion function to its ASCII value,
**	for an easy callback.
*/

void	ftpf_init_convfunctions_pointers(t_env *e)
{
	e->conv_funct_table['d'] = &(ftpf_convert_di);
	e->conv_funct_table['D'] = &(ftpf_convert_di);
	e->conv_funct_table['i'] = &(ftpf_convert_di);
	e->conv_funct_table['u'] = &(ftpf_convert_u);
	e->conv_funct_table['U'] = &(ftpf_convert_u);
	e->conv_funct_table['c'] = &(ftpf_convert_c);
	e->conv_funct_table['C'] = &(ftpf_convert_c);
	e->conv_funct_table['s'] = &(ftpf_convert_s);
	e->conv_funct_table['S'] = &(ftpf_convert_s);
	e->conv_funct_table['o'] = &(ftpf_convert_o);
	e->conv_funct_table['O'] = &(ftpf_convert_o);
	e->conv_funct_table['x'] = &(ftpf_convert_xp);
	e->conv_funct_table['X'] = &(ftpf_convert_xp);
	e->conv_funct_table['p'] = &(ftpf_convert_xp);
	e->conv_funct_table['b'] = &(ftpf_convert_b);
}

void	ftpf_free_all(t_env *e)
{
	ft_memdel((void**)&e->conversions);
	ft_memdel((void**)&e->lenmods);
	ft_memdel((void**)&e->flags);
	ft_memdel((void**)&e->os);
	ft_memdel((void**)&e->param);
	ft_memdel((void**)&e->mod);
	ft_memdel((void**)&e->x_prefix);
}
