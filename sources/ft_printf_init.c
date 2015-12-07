/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "ft_printf.h"

int	ft_printf_reinit(t_env *e)
{
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
int	ft_printf_init(t_env *e)
{
	e->param = (t_param*)malloc(sizeof(t_param));
	ft_bzero(e->param, sizeof(unsigned long long));
	e->index = 0;
	e->lenmods = ft_strdup("hljz");
	
	e->os = ft_strdup(SYS_OS);
	if (!ft_strcmp(e->os, "darwin"))
		e->conversions = ft_strdup("sSpdDioOuUxXcC%");
	else
		e->conversions = ft_strdup("sSpdiouxXcC%");
	
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	e->mod = ft_strnew(3);
	ft_bzero(e->mod, 3);
	e->conversion = '\0';
	e->spacer = ' ';
	e->outputlen = 0;
	e->xX_prefix = ft_strnew(3);
	ft_bzero(e->xX_prefix, 3);
	e->p_conv = 0;
	e->null_printed = 0;
	return (0);
}
