/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:16:31 by amulin            #+#    #+#             */
/*   Updated: 2016/03/03 16:55:55 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>


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
	else if (!ft_strcmp(type, "short"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(short*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(short*)arg);
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
	else if (!ft_strcmp(type, "wint_t"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(wint_t*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(wint_t*)arg);
	}
	else if (!ft_strcmp(type, "wint_t*"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, (wint_t*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, (wint_t*)arg);
	}
	else if (!ft_strcmp(type, "wchar_t*"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, (wchar_t*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, (wchar_t*)arg);
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
	else if (!ft_strcmp(type, "intmax_t"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(intmax_t*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(intmax_t*)arg);
	}
	else if (!ft_strcmp(type, "uintmax_t"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(uintmax_t*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(uintmax_t*)arg);
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
//	WIP : pour mettre le flag avant le field width et precision (si present)
	int		i;
	char	**testid;\
	char	*flag;
	char	*remain;

	testid = (char**)malloc(sizeof(char*) * 7);
	testid[0] = ft_strdup("10.5");
	testid[1] = ft_strdup("010.5");
	testid[2] = ft_strdup("10");
	testid[3] = ft_strdup("-10");
	testid[4] = ft_strdup("010");
	testid[5] = ft_strdup("-10.5");
	testid[6] = ft_strdup("-010.5");
	if (ft_strchr("#0- +", str[0]))
	{
		flag = ft_strnew(2);
		flag[0] = str[0];
		flag[1] = '\0';
		i = 0;
		while (i < 7)
		{
			testid[i] = ft_strjoin(flag, testid[i]);
			testid[i] = ft_strjoin("%", testid[i]);
			i++;
		}
		remain = &str[1];
	}
	else
		remain = str;

	i = 0;
	while (i < 7)
	{
		visu_compare(ft_strjoin(testid[i], remain), arg, type);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		ft_strdel(&testid[i]);
		i++;
	}
	free(testid);
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
	wint_t	wc;
	char	*str;

	setlocale(LC_ALL, "");
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

	int				j;
	long 			k;
	unsigned long	ulong;
	int				*ptrj;
	char			*str2;

	j = 12;
	ptrj = &j;
	(void)ptrj;
	(void)str2;


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

	visu_compare("%p", NULL, "int*");
	visu_compare("%.p", NULL, "int*");
	visu_compare("%.0p", NULL, "int*");

	j = 1234;
	visu_compare("%2.9p", &j, "int");
	
	j = 0;
	visu_compare("%10.5p", &j, "int");
	compare_fieldw_precision("#p", &j, "int");
	visu_compare("%p", &(ft_printf), "int");
//	visu_compare("%#10.5p", &j, "int");
//	visu_compare("%10.5#p", &j, "int");

//	visu_compare("%%", NULL, "none");
//	visu_compare("%-10p", &j, "int");
//	visu_compare("%p", &j, "int");
//	visu_compare("%10p", &j, "int");
//	visu_compare("%010p", &j, "int");
/*
	ft_putendl("=======================================");
	
	visu_compare("% Zoooo", NULL, "none");
	
	k = LONG_MAX;
	visu_compare("%o", &k, "long");
	visu_compare("%O", &k, "long");

	ulong = ULONG_MAX / 2;
	visu_compare("%u", &ulong, "u long");
	visu_compare("%U", &ulong, "u long");
	
	c = 'f';
	wc = L'\xe9';
	ft_putendl("%c with c as char :");
	visu_compare("%c", &c, "char");
	
	ft_putendl("%C with wc as wint_t :");
	visu_compare("%C", &wc, "wint_t");
	
	ft_putendl("%C with wc as char :");
	visu_compare("%C", &wc, "char");
	
	c = 'f';
	wc = L'\xe9';

	ft_print_memory(&c, sizeof(char));
	ft_print_memory(&wc, sizeof(char));
	ft_print_memory(&wc, sizeof(wchar_t));
	ft_print_memory(&wc, sizeof(wint_t));

	printf("wchar_t = %d\n", (int)wc);

	ft_putendl("=======================================\n");
*/
	visu_compare("%ll# +++-+-- h00012.3.5.28d", ptrj, "int");
	j = 0;
	visu_compare("{%3c}", &j, "char");
	c = 'a';
	visu_compare("%c", &c, "char");
	visu_compare("%3c", &c, "char");
	visu_compare("{%10R}", NULL, "none");
	visu_compare("% Zoooo", NULL, "none");
	
	wchar_t	wchar;

	wchar = 0x53ea;
	visu_compare("%lc", &wchar, "wint_t");
	
	visu_compare("% Zoooo", NULL, "none");
	
	wchar_t	*wstr = L"我是一只猫。";

	visu_compare("{%-30S}", wstr, "wchar_t*");
	visu_compare("{%40S}", wstr, "wchar_t*");
	visu_compare("{%40S}", NULL, "wchar_t*");
	
	k = (long)INT_MAX + 1;
	visu_compare("%li", &k, "long");

	short	sh;
	sh = SHRT_MIN;
	visu_compare("%hd", &sh, "short");


	c = CHAR_MIN;
	visu_compare("%hhd", &c, "char");
	

/*
	unsigned char	uc;
	uc = 0;
	visu_compare("%hhx", &uc, "uchar");
	uc = UCHAR_MAX + 42;
	visu_compare("%hhx", &uc, "uchar");
	uc = UCHAR_MAX;
	visu_compare("%hhx", &uc, "uchar");

	printf("\n\n");
	printf("%hhx, %hhx", 0, UCHAR_MAX + 42);
	printf("\n\n");
	ft_printf("%hhx, %hhx", 0, UCHAR_MAX + 42);
	printf("\n\n");
*/

	unsigned short	uc;

	uc = 0;
	visu_compare("%hhO", &uc, "uchar");
	uc = UCHAR_MAX + 42;
	visu_compare("%hhO", &uc, "uchar");
	uc = UCHAR_MAX;
	visu_compare("%hhO", &uc, "uchar");
	uc = USHRT_MAX;
	visu_compare("%hhO", &uc, "uchar");

	printf("\n\n");
	printf("%hhO, %hhO", 0, USHRT_MAX);
	printf("\n\n");
	ft_printf("%hhO, %hhO", 0, USHRT_MAX);
	printf("\n\n");


	printf("\n\n");
	printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
	printf("\n\n");
	ft_printf("%hhu, %hhu", 0, UCHAR_MAX + 42);
	printf("\n\n");


	printf("\n\n");
	printf("%hhU, %hhU", 0, USHRT_MAX);
	printf("\n\n");
	ft_printf("%hhU, %hhU", 0, USHRT_MAX);
	printf("\n\n");


	ulong = 0L;
	visu_compare("%D", &ulong, "u long");

	intmax_t	imax;

	imax = LLONG_MAX;
	visu_compare("%jd", &imax, "intmax_t");
	
	j = 0;
	visu_compare("%.d", &j, "int");
	visu_compare("%.0d", &j, "int");
	
	unsigned int	ui;
	ui = 0;
	visu_compare("%.u", &ui, "uint");
	visu_compare("%.0u", &ui, "uint");
	
	j = 9999;
	visu_compare("%. d", &j, "int");

	long long	ll;

	ll = LLONG_MIN;
	visu_compare("%zi", &ll, "long long");

	j = 42;
	visu_compare("%+d", &j, "int");
	
	ui = 42;
	visu_compare("%o", &ui, "uint");
	visu_compare("%#o", &ui, "uint");
	ui = 0;
	visu_compare("%#o", &ui, "uint");
	visu_compare("%#.7o", &ui, "uint");
	visu_compare("%o", &ui, "uint");
	
	ui = 42;
	visu_compare("%O", &ui, "uint");
	visu_compare("%#O", &ui, "uint");
	ui = 0;
	visu_compare("%#O", &ui, "uint");
	visu_compare("%#.7O", &ui, "uint");
	visu_compare("%O", &ui, "uint");

	ui = 0;
	visu_compare("%#x", &ui, "uint");
	visu_compare("%p", &ui, "uint");

	ui = 42;
	visu_compare("%#x", &ui, "uint");
	visu_compare("%p", &ui, "uint");

	c = 0;
	visu_compare("{%05.c}", &c, "char");
	
	i = 42;
	visu_compare("{%05.d}", &i, "int");
	
	i = 424242;
	visu_compare("{%.4d}", &i, "int");
	
	char	*str3 = "Hello yop!";
	visu_compare("{%s}", str3, "char*");
	visu_compare("{%05.s}", str3, "char*");
	visu_compare("{%015s}", str3, "char*");
	visu_compare("{%015.8s}", str3, "char*");
	visu_compare("{%015s}", str3, "char*");
	visu_compare("{%015.s}", str3, "char*");
	visu_compare("{%015.1s}", str3, "char*");
	visu_compare("{%15.s}", str3, "char*");
	visu_compare("{%15s}", str3, "char*");

	visu_compare("{%30S}", wstr, "wchar_t*");
	visu_compare("{%-30S}", wstr, "wchar_t*");
	visu_compare("{%30s}", str3, "char*");
	visu_compare("{%-30s}", str3, "char*");
	
	ui = 0;
	visu_compare("{%.o}", &ui, "uint");
	visu_compare("{%.0o}", &ui, "uint");
	visu_compare("{%-.2o}", &ui, "uint");
	visu_compare("{%#o}", &ui, "uint");
	visu_compare("{%#.o}", &ui, "uint");
	visu_compare("{%#.0o}", &ui, "uint");
	
	ui= 424242;
	visu_compare("{%.4o}", &ui, "uint");

	unsigned long long	ull;

	ull = 0;
	visu_compare("{%.jo}", &ull, "u long long");
	ull = ULLONG_MAX;
	visu_compare("{%.jo}", &ull, "u long long");

	visu_compare("{%05.%}", &ui, "uint");
	visu_compare("{%.3%}", &ui, "uint");
	
	j = 0;
	visu_compare("{%3*d}", &j, "int");
	visu_compare("{%3d*}", &j, "int");
	visu_compare("{%*d}", &j, "int");
	ui = 1;
	visu_compare("{%#.3o}", &ui, "uint");
	ui = 42;
	visu_compare("{%#.o}", &ui, "uint");
	
	i = 42;
	visu_compare("{%05.d}", &i, "int");
	i = 0;
	visu_compare("{%05.%}", &i, "int");
	
	visu_compare("{% 03d}", &i, "int");

/*
	printf("\n\n");
	printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("\n\n");
	ft_printf("%hhD, %hhD", 0, USHRT_MAX);
	printf("\n\n");
	
	
	printf("\n\n");
	printf("%hD, %hD", 0, USHRT_MAX);
	printf("\n\n");
	ft_printf("%hD, %hD", 0, USHRT_MAX);
	printf("\n\n");
*/

/*
	k = UINT_MAX + UINT_MAX;
	k = -1L;
	k = LONG_MAX;
	visu_compare("%D", &k, "long");
	k = LONG_MIN;
	visu_compare("%D", &k, "long");
	k = -34346544;
	visu_compare("%D", &k, "long");
*/
//
/*	
	long long ll = 1;
	long long tmp = 10000000000000;
	while ((tmp /= 10) > 1000000)
	{
		k = LONG_MIN / tmp;
		printf("\t\t\t(long long)tmp = %lld\n", tmp);
		printf("\t\t\t(int)tmp = %d\n", tmp);
		printf("\t\t\tll_temoin = %lld\n", ll);
		visu_compare("%D", &k, "long");
		ll *= 10;
	}
*/
	i = 42;
//	visu_compare("{% +d}", &i, "int");
/*
	printf("\noutside : wstr is at %p\n", &wstr);
	visu_compare("{%S}", wstr, "wchar_t*");
	ft_putchar('\n');
	ft_print_memory(wstr, 4 * 6);
	ft_putstr("\nThe first wchar is : ");
	ft_puthex(wstr[0], "min");
	ft_putchar('\n');
*/

/*
	ft_memcpy(ptrj, L"我是一只猫。", 7);
	visu_compare("{%30S}", ptrj, "string");
*/

//	ptrj = ft_strdup("Check hello");
//	visu_compare("{%30s}", ptrj, "char*");

	ft_putendl("============= END OF TESTS =================");
/*
//	setlocale(LC_CTYPE, "");
	ft_putchar('\n');

	printf("sizeof(char) = %d\n", sizeof(char));
	printf("sizeof(wchar_t) = %d\n", sizeof(wchar_t));
	
	wchar = 0x20AC;
	wchar = 'c';
	wchar = 0x53ea;

	ft_printf("ft_printf test with wchar_t : %lc\n", wchar);
	printf("printf test with wchar_t : %lc\n", wchar);
	ft_putstr("Output direct from ft_putwchar() : ");
	ft_putwchar(wchar);
	ft_putchar('\n');
*/
/*
	printf("\nWorking with wchar_t, 20AC\n");
	ft_putstr("put_wchar_t test : ");
	ft_putwchar(wchar);
	ft_putchar('\n');
	ft_print_memory(&wchar, 4);
	printf("printf : wchar = %lc\n", wchar);
	ft_putchar('\n');


	wchar_t	text1[50] = L"G\xe9rard !";
	printf("wchar_t* printf test : ");
	i = printf("%ls\n", text1);
	printf("printf returned %d\n", i);
	ft_print_memory(text1, 50);

	ft_putchar('\n');
	wint_t	text2[50] = L"G\xe9rard !";
	printf("wint_t* printf test : ");
	i = printf("%ls\n", text2);
	printf("printf returned %d\n", i);
	ft_print_memory(text2, 50);

	printf("\nG%lcrard !\n", L'\xe9');
*/
	ft_putendl("================== END =====================");
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
	   p
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
