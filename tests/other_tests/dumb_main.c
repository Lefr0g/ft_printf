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

# include "ft_printf.h"
# include <stdio.h>

int	main(void)
{
	int	i = 42;

	printf("Hello A, i = %d, &i = %p\n", i, &i);
	ft_printf("Hello B, i = %d, &i = %p\n", i, &i);
	ft_putstr("Hello C\n");
	return (0);
}
