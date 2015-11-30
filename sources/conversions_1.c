/* ************************************************************************** **
 *
 *
 *
 *
 *
 *
 *
 *
 *
 ** ************************************************************************** */

#include "ft_printf.h"

void	convert_di(va_list *ap, t_env *e)
{
	if (!e->mod[0])
		e->param->i = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "hh"))
		e->param->sc = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "h"))
		e->param->sh = (int)va_arg(*ap, int);
	else if (!ft_strcmp(e->mod, "l"))
		e->param->l = (long)va_arg(*ap, long);
	else if (!ft_strcmp(e->mod, "ll"))
		e->param->ll = (long long)va_arg(*ap, long long);
	else if (!ft_strcmp(e->mod, "j"))
		e->param->imax = (intmax_t)va_arg(*ap, intmax_t);
	else if (!ft_strcmp(e->mod, "z"))
		e->param->l = (long)va_arg(*ap, long);
	
	e->outputlen = ft_strlen(ft_itoa(e->param->i));

	manage_flags((e->param->i > 0), e);

	manage_field_width(e);
	
	manage_precision(&(e->param->i), (e->param->i < 0), e);
	
	if (e->plus && e->param->i > 0)
		ft_putchar('+');
	
	manage_print_all(e);
}

void	convert_uU(va_list *ap, t_env *e)
{
	if (e->conversion == 'U')
	{
		e->conversion = 'u';
		e->mod[0] = 'l';
		convert_uU(ap, e);
	}
	else
	{
		if (!e->mod[0])
			e->param->u = (unsigned int)va_arg(*ap, unsigned int);
		else if (!ft_strcmp(e->mod, "hh"))
			e->param->uc = (unsigned int)va_arg(*ap, unsigned int);
		else if (!ft_strcmp(e->mod, "h"))
			e->param->ush = (unsigned int)va_arg(*ap, unsigned int);
		else if (!ft_strcmp(e->mod, "l"))
			e->param->ul = (unsigned long)va_arg(*ap, unsigned long);
		else if (!ft_strcmp(e->mod, "ll"))
			e->param->ull = (unsigned long long)va_arg(*ap, unsigned long long);
		else if (!ft_strcmp(e->mod, "j"))
			e->param->uimax = (uintmax_t)va_arg(*ap, uintmax_t);
		else if (!ft_strcmp(e->mod, "z"))
			e->param->st = (size_t)va_arg(*ap, size_t);

		e->outputlen = ft_strlen(ft_itoa_ll(e->param->u, 10));
		
		manage_field_width(e);
		
		manage_precision(&(e->param->u), 0, e);
		
		manage_print_all(e);
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
		if (e->mod[0] == 'l')
			e->param->wi = (wint_t)va_arg(*ap, wint_t);
		e->param->i = (int)va_arg(*ap, int);
	}
	manage_print_all(e);
}
/*
void	convert_U()
{
	e->param->l = va_arg(*ap, long int);
	e->outputlen = ft_strlen(ft_itoa_ll(e->param->l, 10));
	manage_field_width(e);
	manage_precision(&(e->param->u), 0, e);
	ft_putnbr_ull(e->param->u);
	ft_putstr((char*)e->param->l);
}
*/
