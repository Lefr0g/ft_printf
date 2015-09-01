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
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	ft_strcpy(e->mod, "\0\0\0");
	e->conversion = '\0';
	e->spacer = ' ';
	return (0);
}

int	ft_printf_init(t_env *e)
{
	e->index = 0;
	e->lenmods = ft_strdup("hljz");
	e->conversions = ft_strdup("sSpdDioOuUxXcC%");
	e->alt = 0;
	e->zero = 0;
	e->neg = 0;
	e->space = 0;
	e->plus = 0;
	e->field_width = 0;
	e->precisflag = 0;
	e->precision = 0;
	e->mod = ft_strnew(3);
	ft_strcpy(e->mod, "\0\0\0");
	e->conversion = '\0';
	e->spacer = ' ';
	return (0);
}
