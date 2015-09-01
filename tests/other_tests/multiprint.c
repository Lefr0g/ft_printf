/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:52 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 17:36:17 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
/*
int		check_diff(void	elem_a, void elem_b)
{

}
*/
void	my_center_str(char *str, int width, char spacer)
{
	int	offset;
	int i;
	int	j;
	
	offset = (width - ft_strlen(str)) / 2;
	i = 0;
	j = 0;
	while (i < offset)
	{
		ft_putchar(spacer);
		i++;
		j++;
	}
	ft_putstr("- ");
	ft_putstr(str);
	ft_putstr(" -");
	i = 0;
	j += ft_strlen(str) + 4;
	while (i < offset && j < width)
	{
		ft_putchar(spacer);
		i++;
		j++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	char				termlen;
	int					i;
	unsigned int		u;
	int					smallpos;
	int					smallneg;
	int					zero;
	long int			l;
	unsigned long int	ul;
	char				c;
	char				*str;
	wchar_t				str_w[20] = L"Hello Wide h\xe9h\xe9 ! \x03bb";
	void				*null;

	null = NULL;
	zero = 0;
	setlocale(LC_ALL, "");
	termlen = 90;
	i = -1425364793;
	u = 65452654;
	l = 9821234569876545;
	ul = 3462346442;
	smallpos = 42;
	smallneg = -21;
	c = 'a';
	str = ft_strdup("Hello world!");
	(void)argc;
	(void)argv;
//	printf("%x\n", i);
//	printf("%d\n", i);
	
	ft_putchar('\n');
	my_center_str("Starting Conversion Tests", termlen, '-');
	ft_putendl("\n");
	
	ft_printf("ft_printf\t| \"c\" conversion (char -> unsigned char)\t>\t%c\n", c);
	printf("\tprintf\t| \"c\" conversion (char -> unsigned char)\t>\t%c\n", c);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"s\" conversion (string -> string)\t\t>\t%s\n", str);
	printf("\tprintf\t| \"s\" conversion (string -> string)\t\t>\t%s\n", str);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"S\" conversion (string -> string)\t\t>\t%s\n", str);
	printf("\tprintf\t| \"S\" conversion (string -> string)\t\t>\t%S\n", str_w);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"d\" conversion (int -> int)\t\t\t>\t%d\n", i);
	printf("\tprintf\t| \"d\" conversion (int -> int)\t\t\t>\t%d\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"u\" conversion (int -> unsigned int)\t\t>\t%u\n", i);
	printf("\tprintf\t| \"u\" conversion (int -> unsigned int)\t\t>\t%u\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"x\" conversion (int -> unsigned hexa)\t\t>\t%x\n", i);
	printf("\tprintf\t| \"x\" conversion (int -> unsigned hexa)\t\t>\t%x\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"X\" conversion (int -> unsigned hexa)\t\t>\t%X\n", i);
	printf("\tprintf\t| \"X\" conversion (int -> unsigned hexa)\t\t>\t%X\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"o\" conversion (int -> unsigned octal)\t>\t%o\n", i);
	printf("\tprintf\t| \"o\" conversion (int -> unsigned octal)\t>\t%o\n", i);	
//	ft_putchar('\n');
//	ft_printf("ft_printf\t| \"O\" conversion (long int -> unsigned octal)\t>\t%o\n", i);
//	printf("\tprintf\t| \"O\" conversion (long int -> unsigned octal)\t>\t%O\n", l);	
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"p\" conversion (int -> 0x long hexa)\t\t>\t%p\n", &i);
	printf("\tprintf\t| \"p\" conversion (int -> 0x long hexa)\t\t>\t%p\n", &i);
		
	ft_putchar('\n');
	my_center_str("Starting Escape Tests", termlen, '-');
	ft_putendl("\n");
	
	ft_printf("ft_printf\t| Escape test\t\t>\t%%\n");
	printf("\tprintf\t| Escape test\t\t>\t%%\n");
	ft_putchar('\n');

	ft_putchar('\n');
	my_center_str("Multiple Directives Tests", termlen, '-');
	ft_putendl("\n");

	ft_printf("ft_printf\t| \tMultiple directives a = %d, b = %d.\n", 42, 21);	
	ft_putendl("\n");

	ft_putchar('\n');
	my_center_str("Precision Tests", termlen, '-');
	ft_putendl("\n");
	printf("printf\t| \tPrecision %%.5d\t i = %d \t\t=>\t i = %.5d.\n", smallpos, smallpos);
	printf("printf\t| \tPrecision %%.5s\t str = %s \t=>\t str = %.5s.\n", str, str);
	ft_putchar('\n');

	my_center_str("Flags Tests", termlen, '-');
	ft_putendl("\n");
	printf("printf\t| \tFlags %%d\t a = %d,\t b = %d.\n", smallpos, smallneg);	
	printf("printf\t| \tFlags %%x\t a = %x,\t b = %x.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%#x\t a = %#x,\t b = %#x.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%#x\t 0 = %#x\n", zero);
	printf("printf\t| \tFlags %%o\t a = %o,\t b = %o.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%#o\t a = %#o,\t b = %#o.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%#o\t 0 = %#o\n", zero);

	ft_putchar('\n');
	printf("printf\t| \tFlags %%0d\t a = %0d,\t b = %0d.\n", smallpos, smallneg);	
	printf("printf\t| \tFlags %%5d\t a = %5d,\t b = %5d.\n", smallpos, smallneg);	
	printf("printf\t| \tFlags %%-5d\t a = %-5d,\t b = %-5d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%05d\t a = %05d,\t b = %05d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%' '5d\t a = % 5d,\t b = % 5d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%+5d\t a = %+5d,\t b = %+5d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%+05d\t a = %+05d,\t b = %+05d.\n", smallpos, smallneg);
	ft_putchar('\n');
	printf("printf\t| \tFlags %%d\t a = %d,\t b = %d.\n", smallpos, smallneg);	
	printf("printf\t| \tFlags %%' 'd\t a = % d,\t b = % d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%+d\t a = %+d,\t b = %+d.\n", smallpos, smallneg);
	ft_putchar('\n');
	printf("printf\t| \tFlags %%1d\t a = %1d,\t b = %1d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%.1d\t a = %.1d,\t b = %.1d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%.5d\t a = %.5d,\t b = %.5d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%' '.5d\t a = % .5d,\t b = % .5d.\n", smallpos, smallneg);
	printf("printf\t| \tFlags %%+.5d\t a = %+.5d,\t b = %+.5d.\n", smallpos, smallneg);
	ft_putchar('\n');
	printf("printf\t| \tFlags %%#x\t NULL = %#x\n", (unsigned int)null);
	printf("printf\t| \tFlags %%#lx\t NULL = %#lx\n", (unsigned long)null);
	printf("printf\t| \tFlags %%p\t NULL = %p\n", null);

	ft_putendl("\n");

	my_center_str("Color Tests", termlen, '-');
	ft_putendl("\n");
	ft_putstr("\033[31m""ft_putstr\t| \x1b[32m\033[1mthis is green\033[0m\n");
	printf("printf\t| \033[32mthis is green\033[0m\n");
	printf("printf\t| \033[34mthis is blue\033[0m\n");
	ft_putstr("Chaine 1" "Chaine 2"   "Chaine 3" "Chaine 4" "\n");
	ft_putstr("1""2");

	ft_putendl("\n");
	my_center_str("End of Tests", termlen, '-');
	ft_putchar('\n');
	return (0);
}
