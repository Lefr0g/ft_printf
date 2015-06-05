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
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 19;
	(void)argc;
	(void)argv;
	ft_putendl("Hello World!");
	printf("%x\n", i);
	printf("%d\n", i);
	return (0);
}
