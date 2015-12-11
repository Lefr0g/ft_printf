/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:16:31 by amulin            #+#    #+#             */
/*   Updated: 2015/12/11 15:53:08 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>

void	visu_compare(char *str, void *arg, char *type)
{
	int		pf_out;
	int		ftpf_out;


	ft_putstr("Tested string : '");
	ft_putstr("\033[35m");
	ft_putstr(str);
	ft_putstr("\033[0m");
	ft_putendl("'");
//	ft_putchar('\n');

	if (!ft_strcmp(type, "none"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str);
	}
	else if (!ft_strcmp(type, "int"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(int*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(int*)arg);
	}
	else if (!ft_strcmp(type, "int*"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, (int*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, (int*)arg);
	}
	else if (!ft_strcmp(type, "uint"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(unsigned int*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(unsigned int*)arg);
	}
	else if (!ft_strcmp(type, "char"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(char*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(char*)arg);
	}
	else if (!ft_strcmp(type, "uchar"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(unsigned char*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(unsigned char*)arg);
	}
	else if (!ft_strcmp(type, "char*"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, (char*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, (char*)arg);
	}
	else if (!ft_strcmp(type, "long"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(long*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(long*)arg);
	}
	else if (!ft_strcmp(type, "u long"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(unsigned long*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(unsigned long*)arg);
	}
	else if (!ft_strcmp(type, "long long"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(long long*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(long long*)arg);
	}
	else if (!ft_strcmp(type, "u long long"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(unsigned long long*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(unsigned long long*)arg);
	}
	ft_putendl("\033[0m'");
	if (pf_out == ftpf_out)
		printf("Both functions return %d\n", pf_out);
	else
		printf("[ \033[33mWARNING\033[0m ] ft_printf() returns \033[33m%d\033[0m instead of \033[33m%d\033[0m.\n", ftpf_out, pf_out);
	ft_putchar('\n');
}

void	compare_flags(char *str, void *arg, char *type)
{
	visu_compare(ft_strjoin("%", str), arg, type);
	visu_compare(ft_strjoin("%#", str), arg, type);
	visu_compare(ft_strjoin("%0", str), arg, type);
	visu_compare(ft_strjoin("%-", str), arg, type);
	visu_compare(ft_strjoin("% ", str), arg, type);
	visu_compare(ft_strjoin("%+", str), arg, type);
}	

void	compare_lenmods(char *str, void *arg, char *type)
{
	visu_compare(ft_strjoin("%", str), arg, type);
	visu_compare(ft_strjoin("%hh", str), arg, type);
	visu_compare(ft_strjoin("%h", str), arg, type);
	visu_compare(ft_strjoin("%l", str), arg, type);
	visu_compare(ft_strjoin("%ll", str), arg, type);
	visu_compare(ft_strjoin("%j", str), arg, type);
	visu_compare(ft_strjoin("%z", str), arg, type);
}

void	compare_fieldw_precision(char *str, void *arg, char *type)
{
	visu_compare(ft_strjoin("%10.5", str), arg, type);
	visu_compare(ft_strjoin("%010.5", str), arg, type);
	visu_compare(ft_strjoin("%10", str), arg, type);
	visu_compare(ft_strjoin("%-10", str), arg, type);
	visu_compare(ft_strjoin("%010", str), arg, type); 
	visu_compare(ft_strjoin("%-10.5", str), arg, type);
	visu_compare(ft_strjoin("%-010.5", str), arg, type);
}

void	compare_flags_on_int(char *str)
{
	int	i;

	ft_putstr("=================================================\n");
	ft_putstr("=================================================\n");
	i = 42;
	ft_putstr("Value = ");
	ft_putnbr(i);
	ft_putendl("\n");
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = 0;
	ft_putstr("Value = ");
	ft_putnbr(i);
	ft_putendl("\n");
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = -42;
	ft_putstr("Value = ");
	ft_putnbr(i);
	ft_putendl("\n");
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = INT_MIN;
	ft_putstr("Value = ");
	ft_putnbr(i);
	ft_putendl("\n");
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = INT_MAX;
	ft_putstr("Value = ");
	ft_putnbr(i);
	ft_putendl("\n");
	compare_flags(str, &i, "int");
}

int	main(void)
{
	int		i = -6324;
	char	c;
	char	*str;

	c = 'D';
	str = ft_strdup("String test OK");

	(void)str;
	(void)i;
//	printf("%i\n", i);
//	ft_printf("%i\n", i);
/*	
	visu_compare("%d", &i, "int");
	visu_compare("%5d", &i, "int");
	visu_compare("%.5d", &i, "int");
	visu_compare("%0d", &i, "int");
	visu_compare("%05d", &i, "int");
	visu_compare("%+d", &i, "int");
	visu_compare("%+5d", &i, "int");

	ft_putstr("=================================================\n");
	(void)str;
	(void)c;

	visu_compare("%i", &i, "int");
	visu_compare("%5i", &i, "int");
	visu_compare("%.5i", &i, "int");
	visu_compare("%0i", &i, "int");
	visu_compare("%05i", &i, "int");
	visu_compare("%+i", &i, "int");
	visu_compare("%+5i", &i, "int");
	
	visu_compare("%x", &i, "int");
	visu_compare("%llx", &i, "int");
	visu_compare("%#x", &i, "int");
	visu_compare("%0x", &i, "int");
	i = 0;
	visu_compare("%x", &i, "int");
	visu_compare("%#x", &i, "int");
	visu_compare("%0x", &i, "int");
	*/
	ft_putstr("=================================================\n");
//	compare_flags_on_int("p");
	
	ft_putstr("=================================================\n");

	int	j;
	long 	k;
	unsigned long	ulong;
	int	*ptrj;
	char	*str2;

	j = 12;
	ptrj = &j;


//	visu_compare("4567 |%-10]5d| plip\n", ptrj, "int");

//	printf("4567 |%-10]5d| plip\n", 12);
//	printf("4567 |%10]5d| plip\n", 12);
	k = -12;

//	compare_flags_on_int("p");

	str2 = ft_strdup("printf\t\t>>>\t'\033[32mThis is a simple string test.\033[0m'\n");

	j = 0;
	visu_compare("This is a simple string test.", NULL, "none");
//	visu_compare("", NULL, "none");
//	visu_compare("%s", NULL, "char*");
	visu_compare("%p", &k, "int");
	visu_compare("%p", &j, "int*");
	compare_fieldw_precision("#p", &j, "int");
	visu_compare("%%", NULL, "none");
	visu_compare("% Zoooo", NULL, "none");
	
	k = LONG_MAX;
	visu_compare("%o", &k, "long");
	visu_compare("%O", &k, "long");

	ulong = ULONG_MAX / 2;
	visu_compare("%u", &ulong, "u long");
	visu_compare("%U", &ulong, "u long");

	c = 'f';
	visu_compare("%c", &c, "char");
	visu_compare("%C", &c, "char");


//	visu_compare("|%10d|", ptrj, "int");
//	visu_compare("|%-10d|", ptrj, "int");

//	Hardcore, out-of-scope (bonus) test :
//	visu_compare("%ll# +++-+-- h00012.3.5.28d", ptrj, "int");

/*
	visu_compare("|%10.5p|", ptrj, "int");
	visu_compare("|%010.5p|", ptrj, "int");
	visu_compare("|%10p|", ptrj, "int");
	visu_compare("|%-10p|", ptrj, "int");
	visu_compare("|%010p|", ptrj, "int"); 
	visu_compare("|%-10.5p|", ptrj, "int");
	visu_compare("|%-010.5p|", ptrj, "int");
*/
//	ft_printf("%d\n", j);


//	compare_lenmods("d", &j, "long long");

	
	/*
	visu_compare("%p", &ptrj, "long");
	visu_compare("%hhx", &ptrj, "long");
	visu_compare("%hx", &ptrj, "long");
	visu_compare("%x", &ptrj, "int");
	visu_compare("%lx", &ptrj, "long");
	visu_compare("%llx", &ptrj, "long");
	visu_compare("%jx", &ptrj, "long");
	visu_compare("%zx", &ptrj, "long");
*/
/*	
	i = 42;
	visu_compare("%d", &i, "int");
	visu_compare("%#d", &i, "int");
	visu_compare("%0d", &i, "int");
	visu_compare("%-d", &i, "int");
	visu_compare("% d", &i, "int");
	visu_compare("%+d", &i, "int");
	i = -42;
	visu_compare("%+0x", &i, "int");
	visu_compare("%0x", &i, "int");
	visu_compare("%-x", &i, "int");

*/

/*	
	ft_putstr("=================================================\n");
	visu_compare("%-0x", &i, "int");
	visu_compare("%-0#x", &i, "int");
	visu_compare("%-0##x", &i, "int");
*/
/*
------------------------------------------
*/	
	
/*
//	printf("%s", "check\n");
	visu_compare("%s", str, "char*");
	visu_compare("%+s", str, "char*");
//	visu_compare("%+S", &i, "int");
	visu_compare("%+p", &i, "int");
	visu_compare("%+d", &i, "int");
	visu_compare("%+D", &i, "int");
	visu_compare("%+i", &i, "int");
	visu_compare("%+o", &i, "int");
	visu_compare("%+O", &i, "int");
	visu_compare("%+u", &i, "int");
	visu_compare("%+U", &i, "int");
	visu_compare("%+x", &i, "int");
	visu_compare("%+X", &i, "int");
	visu_compare("%+c", &i, "int");
	visu_compare("%+C", &i, "int");

//	visu_compare("%#5x", &i, "int");
*/
	return (0);
}
