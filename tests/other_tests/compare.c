
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		i;
//	unsigned int j;
//	int		k;

//	char	*str = "Hello!";
//	wchar_t	wstr[20] = L"Check";
	
	i = INT_MAX + 3456;
//	i = 12345678;
//	k = 42;

	printf("int conversion WITH casting :\n\n");
	printf("printf |\t%%hhd |\ti = %hhd\n", (char)i);
	ft_printf(" ft_printf |\t%%hhd |\ti = %hhd\n\n", (char)i);
	printf("printf |\t%%hd |\ti = %hd\n", (short)i);
	ft_printf(" ft_printf |\t%%hd |\ti = %hd\n\n", (short)i);
	printf("printf |\t%%d |\ti = %d\n", i);
	ft_printf(" ft_printf |\t%%d |\ti = %d\n\n", i);
	printf("printf |\t%%ld |\ti = %ld\n", (long)i);
	ft_printf(" ft_printf |\t%%ld |\ti = %ld\n\n", (long)i);
	printf("printf |\t%%lld |\ti = %lld\n", (long long)i);
	ft_printf(" ft_printf |\t%%lld |\ti = %lld\n\n", (long long)i);

	printf("\nint conversion WITHOUT casting :\n\n");
	printf("printf |\t%%hhd |\ti = %hhd\n", i);
	ft_printf(" ft_printf |\t%%hhd |\ti = %hhd\n\n", i);
	printf("printf |\t%%hd |\ti = %hd\n", i);
	ft_printf(" ft_printf |\t%%hd |\ti = %hd\n\n", i);
	printf("printf |\t%%d |\ti = %d\n", i);
	ft_printf(" ft_printf |\t%%d |\ti = %d\n\n", i);
	printf("printf |\t%%ld |\ti = %ld\n", i);
	ft_printf(" ft_printf |\t%%ld |\ti = %ld\n\n", i);
	printf("printf |\t%%lld |\ti = %lld\n", i);
	ft_printf(" ft_printf |\t%%lld |\ti = %lld\n\n", i);
/*
	printf("printf | %%d \t\t i = %d\n", i);
	printf("printf | %%.2d \t\t i = %.2d\n", i);
	printf("printf | %%hhd \t\t i = %hhd\n", i);
	printf("printf | %%hhd \t\t (char)i = %hhd\n", (char)i);
*/



/*

	printf("4567 |%-10]5d| plip\n", 12);
	printf("4567 |%10]5d| plip\n", 12);
	printf("|%10.5d|\n", -12);
	printf("|%10d|\n", -12);
	printf("|%010d|\n", -12); 
	printf("|%-10.5d|\n", -12);
	printf("|%-010.5d|\n", -12);
*/
	
/*
	printf("\n");
	printf("printf | %%.s\ts = |%.s|\n", str);
	ft_printf("ft_printf | %%.s\ts = |%.s|\n", str);
*/
/*
	printf("printf | %%5u\ti = |%5u|\n", i);
	ft_printf("ft_printf | %%5u\ti = |%5u|\n", i);
	ft_printf("\n");
	printf("printf | %%.5u\t\ti = |%.5u|\n", i);
	ft_printf("ft_printf | %%.5u\ti = |%.5u|\n", i);
*/
/*
	printf("printf | %%d\t\tk = %d\n", i);
	printf("printf | %%d\t\tk = %d\n", j);
	printf("printf | %%d\t\tk = %d\n", k);
	printf("\n");
	ft_printf("ft_printf | %%d\t\tk = %d\n", i);
	ft_printf("ft_printf | %%d\t\tk = %d\n", j);
	ft_printf("ft_printf | %%d\t\tk = %d\n", k);	
	printf("\n");
*/
/*
	printf("printf | %%.6d\t\tk = |%.6d|\n", i);
	printf("printf | %%.6d\t\tk = |%.6d|\n", j);
	printf("printf | %%.6d\t\tk = |%.6d|\n", k);
	printf("\n");
	ft_printf("ft_printf | %%.6d\tk = |%.6d|\n", i);
	ft_printf("ft_printf | %%.6d\tk = |%.6d|\n", j);
	ft_printf("ft_printf | %%.6d\tk = |%.6d|\n", k);	
	printf("\n");
	printf("printf | %%6d\t\tk = |%6d|\n", i);
	printf("printf | %%6d\t\tk = |%6d|\n", j);
	printf("printf | %%6d\t\tk = |%6d|\n", k);
	printf("\n");
	ft_printf("ft_printf | %%6d\t\tk = |%6d|\n", i);
	ft_printf("ft_printf | %%6d\t\tk = |%6d|\n", j);
	ft_printf("ft_printf | %%6d\t\tk = |%6d|\n", k);	
	printf("\n");
*/




/*

	printf("printf | %%15hho\t\tk = |%15hho|\n", (unsigned char)i);
	ft_printf("ft_printf | %%15hho\tk = |%15hho|\n", (unsigned char)i);
	printf("printf | %%.15hho\t\tk = |%.15hho|\n", (unsigned char)i);
	ft_printf("ft_printf | %%.15hho\tk = |%.15hho|\n", (unsigned char)i);
	//printf("itoa = %s\n", ft_itoa_base(i, 16));
	ft_puthex(i, "maj");
	ft_putchar('\n');
*/
	
	
	
	
	
/*
	ft_printf("\n");
	printf("printf | %%7.5d\t\ti = |%7.5d|\n", i);
	ft_printf("ft_printf | %%7.5d\ti = |%7.5d|\n", i);
*/
/*
	ft_printf("\n");
	printf("printf | %%.5o\t\ti = |%.5o|\n", i);
	ft_printf("ft_printf | %%.5o\ti = |%.5o|\n", i);

	ft_printf("\n");
	printf("printf | %%5o\t\ti = |%5o|\n", i);
	ft_printf("ft_printf | %%5o\t\ti = |%5o|\n", i);
	ft_printf("\n");
	printf("printf | %%7.5o\t\ti = |%7.5o|\n", i);
	ft_printf("ft_printf | %%7.5o\ti = |%7.5o|\n", i);
*/

//	ft_printf("Coucou i = %d\n", i);	
/*
	printf("printf | %%.5d |\t\ti = |%.5d|\n", i);
	printf("printf | %%0.5d |\ti = |%0.5d|\n", i);
	printf("\n");
	printf("printf | %%5d |\t\ti = |%5d|\n", i);
	printf("printf | %%05d |\t\ti = |%05d|\n", i);
	printf("\n");
	printf("printf | %%7.5d |\ti = |%7.5d|\n", i);
	printf("printf | %%07.5d |\ti = |%07.5d|\n", i);
	printf("\n");
	printf("printf | %%5.7d |\ti = |%5.7d|\n", i);
	printf("printf | %%05.7d |\ti = |%05.7d|\n", i);
	printf("\n");
*/
/*
	printf("printf | %%10s |\t\ts = |%10s|\n", str);
	ft_printf("ft_printf | %%10s |\ts = |%10s|\n", str);	
	printf("\n");
	printf("printf | %%.10s |\ts = |%.10s|\n", str);
	ft_printf("ft_printf | %%.10s |\ts = |%.10s|\n", str);
	printf("\n");
	str = ft_strdup("Hello everybody!");
	printf("printf | %%10s |\t\ts = |%10s|\n", str);
	ft_printf("ft_printf | %%10s |\ts = |%10s|\n", str);
	printf("\n");
	printf("printf | %%.10s |\ts = |%.10s|\n", str);
	ft_printf("ft_printf | %%.10s |\ts = |%.10s|\n", str);
*/


/*
 *	Tests with ls and S conversions
 *
	printf("printf | %%10ls |\ts = |%10ls|\n", wstr);
	printf("printf | %%10S |\t\ts = |%10S|\n", wstr);
//	ft_printf("ft_printf | %%10ls |\ts = |%10ls|\n", wstr);	
	printf("\n");
	printf("printf | %%.2ls |\t = |%.2ls|\n", wstr);
//	printf("printf | %%.10S |\t = |%.10S|\n", wstr);
//	ft_printf("ft_printf | %%.10ls |\ts = |%.10ls|\n", wstr);
	printf("\n");
*/


//	ft_printf("ft_printf |\ti = |%.5d|\n", i);
	
	return (0);
}
