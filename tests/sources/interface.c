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

#include "ft_printf_test.h"

int	center_ui_str(char *str, char separator)
{
	int	i;
	int	fillable;

	i = 0;
	fillable = TERM_WIDTH - ft_strlen(str);

	ft_putchar('\n');
	while (i < fillable / 2)
	{
		ft_putchar(separator);
		i++;
	}
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar(' ');
	while (i < fillable)
	{
		ft_putchar(separator);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
