/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:52 by amulin            #+#    #+#             */
/*   Updated: 2015/06/05 15:51:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	my_center_str(char *str, int width, char spacer)
{
	int	offset;
	int i;
	
	offset = (width - ft_strlen(str)) / 2;
	i = 0;
	while (i < offset)
	{
		ft_putchar(spacer);
		i++;
	}
	ft_putstr("- ");
	ft_putstr(str);
	ft_putstr(" -");
	i = 0;
	while (i < offset)
	{
		ft_putchar(spacer);
		i++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int		i;
	char	c;
	char	*str;

	i = 1425364723;
	c = 'a';
	str = ft_strdup("Hello world!");
	(void)argc;
	(void)argv;
//	ft_putendl("Hello World!");
//	printf("%x\n", i);
//	printf("%d\n", i);
	
	ft_putchar('\n');
	my_center_str("Starting Conversion Tests", 80, '-');
	ft_putendl("\n");
	
	ft_printf("ft_printf\t| \"c\" conversion (char -> char)\t\t>\t%c\n", c);
	printf("\tprintf\t| \"c\" conversion (char -> char)\t\t>\t%c\n", c);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"s\" conversion (string -> string)\t>\t%s\n", str);
	printf("\tprintf\t| \"s\" conversion (string -> string)\t>\t%s\n", str);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"d\" conversion (int -> int)\t\t>\t%d\n", i);
	printf("\tprintf\t| \"d\" conversion (int -> int)\t\t>\t%d\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"x\" conversion (int -> hexa)\t\t>\t%x\n", i);
	printf("\tprintf\t| \"x\" conversion (int -> hexa)\t\t>\t%x\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"X\" conversion (int -> hexa)\t\t>\t%X\n", i);
	printf("\tprintf\t| \"X\" conversion (int -> hexa)\t\t>\t%X\n", i);
	ft_putchar('\n');
	ft_printf("ft_printf\t| \"p\" conversion (int -> hexa)\t\t>\t%p\n", &i);
	printf("\tprintf\t| \"p\" conversion (int -> hexa)\t\t>\t%p\n", &i);
		
	ft_putchar('\n');
	my_center_str("Starting Escape Tests", 80, '-');
	ft_putendl("\n");
	
	ft_printf("\n");
	ft_printf("ft_printf\t| Escape test\t\t>\t%%\n");
	printf("\tprintf\t| Escape test\t\t>\t%%\n");
	ft_putchar('\n');

	ft_putendl("\n");
	my_center_str("End of Tests", 80, '-');
	ft_putchar('\n');
	return (0);
}
