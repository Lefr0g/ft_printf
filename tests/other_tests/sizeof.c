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
//#include <wchar.h>
#include "../../includes/ft_printf.h"

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

	printf("Sizeof char = \t\t%lu bytes\n", sizeof(char));
	printf("Sizeof short = \t\t%lu bytes\n", sizeof(short));
	printf("Sizeof wchar_t = \t%lu bytes\n", sizeof(wchar_t));
	printf("Sizeof int = \t\t%lu bytes\n", sizeof(int));
	printf("Sizeof wint_t = \t%lu bytes\n", sizeof(wint_t));
	printf("Sizeof intmax_t = \t%lu bytes\n", sizeof(intmax_t));
	printf("Sizeof uintmax_t = \t%lu bytes\n", sizeof(uintmax_t));
	printf("\n");
	printf("Sizeof unsigned int = \t%lu bytes\n", sizeof(unsigned int));
	printf("Sizeof long = \t\t%lu bytes\n", sizeof(long));
	printf("Sizeof long long = \t%lu bytes\n", sizeof(long long));
	printf("Sizeof double = \t%lu bytes\n", sizeof(double));
	printf("Sizeof long double = \t%lu bytes\n", sizeof(long double));
	printf("Sizeof float = \t\t%lu bytes\n", sizeof(float));
	printf("Sizeof size_t = \t%lu bytes\n", sizeof(size_t));

	return (0);
}
