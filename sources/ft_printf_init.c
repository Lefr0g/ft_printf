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
	e->precision = 0;
	e->lenght = '\0';
	e->conversion = '\0';
	return (0);
}
