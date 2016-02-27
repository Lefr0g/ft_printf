/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:16:31 by amulin            #+#    #+#             */
/*   Updated: 2016/02/26 16:53:48 by amulin           ###   ########.fr       */
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

	k = UINT_MAX + UINT_MAX;
	k = -1L;
	k = LONG_MAX;
	visu_compare("%D", &k, "long");
	k = LONG_MIN;
	visu_compare("%D", &k, "long");
	k = -34346544;
	visu_compare("%D", &k, "long");
	k = LONG_MIN + 2;
	visu_compare("%D", &k, "long");

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

	ptrj = ft_strdup("Check hello");
	visu_compare("{%30s}", ptrj, "char*");

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
