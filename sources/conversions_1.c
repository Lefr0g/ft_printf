/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:49:12 by amulin            #+#    #+#             */
/*   Updated: 2016/03/10 16:42:28 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	convert_dDi(va_list *ap, t_env *e)
{
	int	buf;

	(void)ap;
//	if (e->conversion == 'D' && !e->mod[0])
//	{
//		e->conversion = 'd';
//		e->mod[0] = 'l';
//		convert_dDi(ap, e);
//	}
//	else
	{
		manage_modifiers_dDi(ap, e);
	
//		printf("\nft_itoa_ll = %s\n", ft_itoa_ll(e->param->l, 10));

//		printf("Spacer = %c, precisflag = %d\n", e->spacer, e->precisflag);
		ftpf_process_flags(e);
//		printf("Spacer = %c, precisflag = %d\n", e->spacer, e->precisflag);

//		printf("Precisflag = %d, precision = %d\n", e->precisflag, e->precision);
//		printf("Outpulen = %d\n", e->outputlen);

		if (e->precision >= e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			if (e->param->i < 0)
				e->outputlen++;
			e->precision = e->outputlen - buf;
		}
		else if (e->precisflag && !e->param->i)
			e->outputlen = 0;
		else
			e->precision = 0;
/*
		printf("Field Width = %d\n", e->field_width);
		printf("\ne->neg = %d\n", e->neg);
		printf("\ne->zero = %d\n", e->zero);
		printf("Precision = %d\n", e->precision);
		printf("Outpulen = %d\n", e->outputlen);
*/	
		
//		ftpf_apply_flags(e);	
		
		if (e->space && ft_strchr("dDi", e->conversion) && e->param->i >= 0
				&& !e->plus)
			ft_putchar(' ');

//		printf("Precisflag = %d, precision = %d\n", e->precisflag, e->precision);
//		printf("Outpulen = %d\n", e->outputlen);

		if (!e->neg)
			manage_field_width(e);

		if (e->plus && ft_strchr("dDi", e->conversion) && e->param->i >= 0)
			ft_putchar('+');

//		printf("Precisflag = %d, precision = %d\n", e->precisflag, e->precision);

		manage_precision(&(e->param->i), (e->param->i < 0), e);

		
		if (!(e->precisflag && !e->precision && !e->param->i))
			manage_print_all(e);

		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_uU(va_list *ap, t_env *e)
{
	int	buf;
	if (e->conversion == 'U' && !e->mod[0])
	{
//		e->conversion = 'u';
		e->mod[0] = 'l';
		convert_uU(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 10));
		if (e->precision > e->outputlen && e->param->u)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else if (e->precisflag && !e->param->u)
			e->outputlen = 0;
		else
			e->precision = 0;

//		printf("Precision = %d\n", e->precision);
//		printf("Outpulen = %d\n", e->outputlen);

		ftpf_process_flags(e);
		
		if (!e->neg)
			manage_field_width(e);

		manage_precision(&(e->param->u), 0, e);

		if (!(e->precisflag && !e->precision && !e->param->i))
			manage_print_all(e);
		
		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_cC(va_list *ap, t_env *e)
{
	if (e->conversion == 'C')
	{
		e->conversion = 'c';
		e->mod[0] = 'l';
		convert_cC(ap, e);
	}
	else
	{
//		e->outputlen = 1;
		if (e->mod[0] == 'l')
			e->param->wi = (wint_t)va_arg(*ap, wint_t);
		else
			e->param->i = (int)va_arg(*ap, int);
//		
		ftpf_process_flags(e);
//		
		if (!e->neg)
			manage_field_width(e);
		manage_print_all(e);
		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_oO(va_list *ap, t_env *e)
{
	int	buf;
	
	if (e->conversion == 'O' && !e->mod[0])
	{
//		e->conversion = 'o';
		if (!e->mod[0])
			e->mod[0] = 'l';
		convert_oO(ap, e);
	}
	else
	{
		manage_modifiers_ouxX(ap, e);

		if (e->param->u || !(e->precisflag && !e->precision) || e->alt)
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 8));

//		printf("Precision = %d, Outputlen = %d\n", e->precision, e->outputlen);

		if (e->precision > e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else
			e->precision = 0;

		ftpf_process_flags(e);
	
		if (!e->neg)
			manage_field_width(e);


//		if (e->alt && e->precision)
//		{
//			e->outputlen = e->precision;
//		}


//		printf("Precision = %d\n", e->precision);

		manage_precision(&(e->param->u), 0, e);
		
//		if (e->param->ull || e->precisflag)
		if (e->param->u || !(e->precisflag && !e->precision) || e->alt)
			manage_print_all(e);
			
		if (e->neg)
			manage_field_width(e);
	}
}

void	convert_xX(va_list *ap, t_env *e)
{
	int	buf;

	manage_modifiers_ouxX(ap, e);

	if (e->conversion == 'x')
		ft_strcpy(e->xX_prefix, "0x");
	else
		ft_strcpy(e->xX_prefix, "0X");
	if (!(!ft_strcmp("linux", e->os) && !e->param->i))
	{
		if (!ft_strcmp(e->mod, "h"))
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->ush, 16));
		else if (!ft_strcmp(e->mod, "hh"))
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->uc, 16));
		else
			e->outputlen = ft_strlen(ft_itoa_ull(e->param->ul, 16));
		if (e->precision > e->outputlen)
		{
			buf = e->outputlen;
			e->outputlen = e->precision;
			e->precision = e->outputlen - buf;
		}
		else if (e->precisflag && !e->precision)
			e->outputlen--;
		else
			e->precisflag = 0;

		ftpf_process_flags(e);

		if (!e->neg)
			manage_field_width(e);

		if (e->neg && e->alt && ft_strchr("xX", e->conversion) && !e->zero)
		{
			ft_putstr(e->xX_prefix);
			e->outputlen += ft_strlen(e->xX_prefix);
		}
		manage_precision(&(e->param->u), 0, e);

//		printf("Precision = %d\n", e->precision);
//		printf("Outpulen = %d\n", e->outputlen);
		
		if (!(e->precisflag && !e->precision))
			manage_print_all(e);
	
		if (e->neg)
			manage_field_width(e);
	}
//	else if (!ft_strcmp("linux", e->os) && !e->param->i)
//	{
//	}
	else
	{
//		ft_putstr("||check||");
		e->conversion = 's';
		e->mod[0] = '\0';
		e->param->s = ft_strdup(NULL_PTR);
		if (e->precisflag && !e->precision)
			ft_putstr(NULL_PTR);
		convert_sS(NULL, e);
	}
}

void	convert_sS(va_list *ap, t_env *e)
{
	char	*str;
	wchar_t	*wstr;
	int		tmp;

	if (e->conversion == 'S')
	{
		e->conversion = 's';
		e->mod[0] = 'l';
		convert_sS(ap, e);
	}
	else
	{
//		if (e->plus)
//			ft_putendl_fd("\nError : '+' flag used with s conversion", 2);
		if (ap)
		{
			if (e->mod[0] == 'l')
			{
				wstr = (wchar_t*)va_arg(*ap, wchar_t*);
				if (wstr)
					e->param->ws = (wchar_t*)ft_memalloc(ft_wstr_memsize(wstr) + 4);
				else
				{
					e->mod[0] = 0;
					e->param->s = ft_strdup("(null)");
				}
				if (wstr && e->param->ws)
					ft_memcpy(e->param->ws, wstr, ft_wstr_memsize(wstr));
//				ft_putchar('\n');
//				ft_print_memory(e->param->ws, 4 * 6);
//				ft_putchar('\n');
			}
			else
			{
				str = (char*)va_arg(*ap, char*);
				if (str)
					e->param->s = ft_strdup(str);
				else
					e->param->s = ft_strdup("(null)");
			}
		}
		if (!e->param->s)
			ft_putendl_fd("\nError : no string to be printed", 2);


		ftpf_process_flags(e);

//		if (e->outputlen < e->field_width)

		if (e->precisflag)
			e->param->s = manage_precision_s(e->param->s, e);
		e->precision = 0;
		if (!e->neg)
			manage_field_width(e);

		manage_print_all(e);

		tmp = e->outputlen;
		e->outputlen = 0;
		if (e->neg)
			manage_field_width(e);
		e->outputlen = tmp;
	}
}
