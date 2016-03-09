/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 12:56:31 by amulin            #+#    #+#             */
/*   Updated: 2016/03/08 19:40:55 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ftpf_reinit_env(t_env *e)
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
	return (0);
}

/*
**	Detect system OS in order to avoid accepting OSX-only
**	conversion in Linux
*/
int	ftpf_init_env(t_env *e)
{
	ftpf_init_convfunctions_pointers(e);
	e->conversion_function = NULL;
	e->param = (t_param*)malloc(sizeof(t_param));
	ft_bzero(e->param, sizeof(unsigned long long));
	e->index = 0;
	e->lenmods = ft_strdup("hljz");
	e->flags = ft_strdup("#0- +");
	
	e->os = ft_strdup(SYS_OS);
	if (!ft_strcmp(e->os, "darwin"))
		e->conversions = ft_strdup("sSpdDioOuUxXcC");
	else
		e->conversions = ft_strdup("sSpdiouxXcC");
	
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	e->mod = ft_strnew(3);
	e->conversion = '\0';
	e->spacer = ' ';
	e->outputlen = 0;
	e->xX_prefix = ft_strnew(3);
	e->p_conv = 0;
	e->null_printed = 0;
	if (!e->param || !e->lenmods || !e->os || !e->conversions 
			|| !e->mod || !e->xX_prefix)
		return (1);
	return (0);
}

/*
**	This functions associates each conversion function to its ASCII value,
**	for an easy callback.
*/

void	ftpf_init_convfunctions_pointers(t_env *e)
{
	e->conv_funct_table['d'] = &(convert_dDi);
	e->conv_funct_table['D'] = &(convert_dDi);
	e->conv_funct_table['i'] = &(convert_dDi);
	e->conv_funct_table['u'] = &(convert_uU);
	e->conv_funct_table['U'] = &(convert_uU);
	e->conv_funct_table['c'] = &(convert_cC);
	e->conv_funct_table['C'] = &(convert_cC);
	e->conv_funct_table['s'] = &(convert_sS);
	e->conv_funct_table['S'] = &(convert_sS);
	e->conv_funct_table['o'] = &(convert_oO);
	e->conv_funct_table['O'] = &(convert_oO);
	e->conv_funct_table['x'] = &(convert_xX);
	e->conv_funct_table['X'] = &(convert_xX);
	e->conv_funct_table['p'] = &(convert_xX);
}
