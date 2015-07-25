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

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	/*
	int	i;

	i = 42;
	printf("00 - printf\t|\tNo argument\n");
	ft_printf("00 - ft_printf\t|\tNo argument\n");
	printf("01 - printf\t|\tint argument %%d = %d\n", i);
	ft_printf("01 - ft_printf\t|\tint argument %%d = %d\n", i);
	*/

	printf("Sizeof char = %lu bytes\n", sizeof(char));
	printf("Sizeof short = %lu bytes\n", sizeof(short));
	printf("Sizeof wchar_t = %lu bytes\n", sizeof(wchar_t));
	printf("Sizeof int = %lu bytes\n", sizeof(int));
	ft_putchar('\n');
	printf("Sizeof unsigned int = %lu bytes\n", sizeof(unsigned int));
	printf("Sizeof long = %lu bytes\n", sizeof(long));
	printf("Sizeof long long = %lu bytes\n", sizeof(long long));
	printf("Sizeof double = %lu bytes\n", sizeof(double));
	printf("Sizeof long double = %lu bytes\n", sizeof(long double));
	printf("Sizeof float = %lu bytes\n", sizeof(float));
	printf("Sizeof size_t = %lu bytes\n", sizeof(size_t));

	return (0);
}
