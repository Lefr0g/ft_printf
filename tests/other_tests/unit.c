/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:16:31 by amulin            #+#    #+#             */
/*   Updated: 2016/03/26 17:47:13 by amulin           ###   ########.fr       */
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
	else if (!ft_strcmp(type, "float"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(float*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(float*)arg);
	}
	else if (!ft_strcmp(type, "double"))
	{
		ft_putstr("printf\t\t>>>\t'\033[32m");
		pf_out = printf(str, *(double*)arg);
		fflush(stdout);
		ft_putstr("\033[0m'\nft_printf\t>>>\t'\033[36m");
		ftpf_out = ft_printf(str, *(double*)arg);
	}
	ft_putendl("\033[0m'");
	if (pf_out == ftpf_out)
		printf("[ \033[32mOK\033[0m ] Both functions return %d\n", pf_out);
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

void	dDi_tests(void)
{
	char		c;
	short		s;
	int			i;
	long		l;
	long long	ll;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING dDi CONVERSION TESTS ========\n");
	ft_putstr("=================================================\033[0m\n\n");
	
	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("------------------------------ no lenght modifier\033[0m\n");	

	i = 42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%d", &i, "int");
	visu_compare("%0d", &i, "int");
	visu_compare("%09d", &i, "int");
	visu_compare("%+d", &i, "int");
	visu_compare("%+9d", &i, "int");
	visu_compare("%+ 9d", &i, "int");
	visu_compare("% +9d", &i, "int");
	visu_compare("% 9d", &i, "int");
	visu_compare("%3.7d", &i, "int");
	visu_compare("%7.3d", &i, "int");
	visu_compare("%03.2d", &i, "int");
	visu_compare("%3.2d", &i, "int");
	visu_compare("%-3.2d", &i, "int");
	visu_compare("%-03.7d", &i, "int");
	visu_compare("%-07.3d", &i, "int");
	visu_compare("%.4d", &i, "int");
	visu_compare("%+05d", &i, "int");
	visu_compare("%+06.3d", &i, "int");

	i = 0;
	printf("**************************** Value = %d\n", i);
	visu_compare("%d", &i, "int");
	visu_compare("%+d", &i, "int");
	visu_compare("% d", &i, "int");
	visu_compare("%7.3d", &i, "int");
	visu_compare("%03.2d", &i, "int");
	visu_compare("%3.2d", &i, "int");
	visu_compare("%-3.2d", &i, "int");
//	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%0-3d", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%+03d", &i, "int");
	visu_compare("%+03.d", &i, "int");
	visu_compare("%06.3d", &i, "int");
	visu_compare("%+06.3d", &i, "int");
	visu_compare("%+0d", &i, "int");

	i = -1;
	printf("**************************** Value = %d\n", i);
	visu_compare("%7.3d", &i, "int");
	visu_compare("%03.2d", &i, "int");
	visu_compare("%3.2d", &i, "int");
	visu_compare("%-3.2d", &i, "int");
	visu_compare("%+03d", &i, "int");
	visu_compare("%03d", &i, "int");
	visu_compare("%3d", &i, "int");
	visu_compare("%+06.3d", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%+05.d", &i, "int");
	
	i = -42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%7.3d", &i, "int");
	visu_compare("%03.2d", &i, "int");
	visu_compare("%3.2d", &i, "int");
	visu_compare("%-3.2d", &i, "int");
	
	visu_compare("%7.3i", &i, "int");
	visu_compare("%03.2i", &i, "int");
	visu_compare("%3.2i", &i, "int");
	visu_compare("%-3.2i", &i, "int");
	visu_compare("%+06.3d", &i, "int");
	visu_compare("%+05d", &i, "int");
	visu_compare("%05d", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%+05.d", &i, "int");
	
	i = INT_MAX;
	printf("**************************** Value = %d\n", i);
	visu_compare("%d", &i, "int");
	visu_compare("%18.14d", &i, "int");
	visu_compare("%-18.14d", &i, "int");
	visu_compare("%+06.3d", &i, "int");
	visu_compare("%+05.d", &i, "int");
	
	i = INT_MIN;
	printf("**************************** Value = %d\n", i);
	visu_compare("%d", &i, "int");
	visu_compare("%18.14d", &i, "int");
	visu_compare("%-18.14d", &i, "int");
	visu_compare("%0.15d",&i, "int");

	i = INT_MIN + 1;
	printf("**************************** Value = %d\n", i);
	visu_compare("%d", &i, "int");
	visu_compare("%18.14d", &i, "int");
	visu_compare("%-18.14d", &i, "int");

	i = -42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%10d", &i, "int");
	visu_compare("%15.4d", &i, "int");
	visu_compare("%18.14d", &i, "int");
	visu_compare("%018.14d", &i, "int");
	
	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("---------------------------------------- long (l)\033[0m\n");	

	l = 42L;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%ld", &l, "long");
	visu_compare("%D", &l, "long");
	visu_compare("%0ld", &l, "long");
	visu_compare("%0D", &l, "long");
	
	visu_compare("%09ld", &l, "long");
	visu_compare("%09D", &l, "long");

	visu_compare("%+ld", &l, "long");
	visu_compare("%+D", &l, "long");

	visu_compare("%+9ld", &l, "long");
	visu_compare("%+9D", &l, "long");

	visu_compare("%+ 9ld", &l, "long");
	visu_compare("%+ 9D", &l, "long");

	visu_compare("% +9ld", &l, "long");
	visu_compare("% +9D", &l, "long");

	visu_compare("% 9ld", &l, "long");
	visu_compare("% +9D", &l, "long");

	l = -42L;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%D", &l, "long");
	
	l = 0;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%ld", &l, "long");
	visu_compare("%D", &l, "long");
	visu_compare("%+ld", &l, "long");
	visu_compare("%+D", &l, "long");

	visu_compare("% ld", &l, "long");
	visu_compare("% D", &l, "long");
	
	l = LONG_MAX;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%ld", &l, "long");
	visu_compare("%D", &l, "long");
	
	
	l = LONG_MIN;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%ld", &l, "long");
	visu_compare("%D", &l, "long");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("---------------------------------- long long (ll)\033[0m\n");	

	ll = LLONG_MAX;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%lld",&ll, "long long");
	visu_compare("%30.24lld",&ll, "long long");
	visu_compare("%-30.24lld",&ll, "long long");
	visu_compare("%0-30.24lld",&ll, "long long");
	
	ll = LLONG_MIN;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%30.24lld",&ll, "long long");
	visu_compare("%0.23lld",&ll, "long long");

	ll = LLONG_MIN + 2;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%lld",&ll, "long long");
	visu_compare("%30.24lld",&ll, "long long");
	visu_compare("%0.23lld",&ll, "long long");

	ll = 0;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%30.24lld",&ll, "long long");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("--------------------------------------- short (h)\033[0m\n");

	s = 0;
	printf("**************************** Value = %hd\n", s);
	visu_compare("%3.2hd", &s, "short");
	visu_compare("% -3.2hd", &s, "short");
	visu_compare("%07.3hd", &s, "short");

	s = -42;
	printf("**************************** Value = %hd\n", s);
	visu_compare("%3.2hd", &s, "short");
	visu_compare("% -3.2hd", &s, "short");
	visu_compare("%07.3hd", &s, "short");
	
	s = SHRT_MIN;
	printf("**************************** Value = %hd\n", s);
	visu_compare("%3.2hd", &s, "short");
	visu_compare("% -3.2hd", &s, "short");
	visu_compare("%07.3hd", &s, "short");

	s = SHRT_MAX;
	printf("**************************** Value = %hd\n", s);
	visu_compare("%3.2hd", &s, "short");
	visu_compare("% -3.2hd", &s, "short");
	visu_compare("%07.3hd", &s, "short");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("--------------------------------------- char (hh)\033[0m\n");

	c = 0;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%5.2hhd", &c, "char");
	visu_compare("% -5.2hhd", &c, "char");
	visu_compare("%07.3hhd", &c, "char");
	visu_compare("% -7.4hhd", &c, "char");
	visu_compare("%-7.4hhd", &c, "char");
	visu_compare("%7.0hhd", &c, "char");

	c = 42;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%5.3hhd", &c, "char");
	visu_compare("% -5.3hhd", &c, "char");
	visu_compare("%07.3hhd", &c, "char");
	visu_compare("%+07.3hhd", &c, "char");
	
	c = CHAR_MIN;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%3.2hhd", &c, "char");
	visu_compare("% -3.2hhd", &c, "char");
	visu_compare("%07.3hhd", &c, "char");
	visu_compare("%+07.5hhd", &c, "char");
	visu_compare("% -7.5hhd", &c, "char");

	c = CHAR_MAX;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%3.2hhd", &c, "char");
	visu_compare("% -3.2hhd", &c, "char");
	visu_compare("%07.3hhd", &c, "char");
	visu_compare("%+07.3hhd", &c, "char");

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF dDi CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");
}

void	oO_tests(void)
{
	unsigned char	uc;
	int				i;
	long			l;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING oO CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");
	
	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("------------------------------ no lenght modifier\033[0m\n");	
	
	i = 42;
	printf("**************************** Value = %u\n", i);
	visu_compare("%o", &i, "int");
	visu_compare("%#o", &i, "int");
	visu_compare("%#.o", &i, "int");
	visu_compare("%0o", &i, "int");
	visu_compare("%09o", &i, "int");
	visu_compare("%+o", &i, "int");
	visu_compare("%+ o", &i, "int");
	visu_compare("%+9o", &i, "int");
	visu_compare("%+ 9o", &i, "int");
	visu_compare("% 9o", &i, "int");
	visu_compare("%3.7o", &i, "int");
	visu_compare("%7.3o", &i, "int");
	visu_compare("%-03.7o", &i, "int");
	visu_compare("%-07.3o", &i, "int");
	
	i = 0;
	printf("**************************** Value = %u\n", i);
	visu_compare("%o", &i, "int");
	visu_compare("%#o", &i, "int");
	visu_compare("%#.o", &i, "int");
	visu_compare("%#1.o", &i, "int");
	visu_compare("%#.0o", &i, "int");
	visu_compare("%#2.0o", &i, "int");
	
	i = 1;
	printf("**************************** Value = %u\n", i);
	visu_compare("%#.3o", &i, "int");
	
	i = INT_MAX;
	printf("**************************** Value = %u\n", i);
	visu_compare("%o", &i, "int");
	visu_compare("%#o", &i, "int");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("---------------------------------------- long (l)\033[0m\n");	

	l = LONG_MAX;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%lo", &l, "long");
	visu_compare("%O", &l, "long");
	visu_compare("%30.24lo",&l, "long");
	visu_compare("%-30.24lo",&l, "long");
	visu_compare("%0-30.24lo",&l, "long");

	l = LONG_MIN;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%lo", &l, "long");
	visu_compare("%O", &l, "long");
	visu_compare("%30.24lo",&l, "long");
	visu_compare("%-30.24lo",&l, "long");
	visu_compare("%0-30.24lo",&l, "long");

	l = 0;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%lo", &l, "long");
	visu_compare("%O", &l, "long");
	visu_compare("%#.O", &l, "long");
	visu_compare("%30.24lo",&l, "long");
	visu_compare("%-30.24lo",&l, "long");
	visu_compare("%0-30.24lo",&l, "long");

	l = 42;
	printf("**************************** Value = %ld\n", l);
	visu_compare("%lo", &l, "long");
	visu_compare("%O", &l, "long");
	visu_compare("%30.24lo",&l, "long");
	visu_compare("%-30.24lo",&l, "long");
	visu_compare("%0-30.24lo",&l, "long");

	visu_compare("%0lo", &l, "long");
	visu_compare("%0O", &l, "long");
	
	visu_compare("%09lo", &l, "long");
	visu_compare("%0O", &l, "long");

	visu_compare("%+lo", &l, "long");
	visu_compare("%+O", &l, "long");

	visu_compare("%+9lo", &l, "long");
	visu_compare("%+9O", &l, "long");

	visu_compare("%+ 9lo", &l, "long");
	visu_compare("%+ 9O", &l, "long");

	visu_compare("% +9lo", &l, "long");
	visu_compare("% +9O", &l, "long");

	visu_compare("% 9lo", &l, "long");
	visu_compare("% +9O", &l, "long");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("-------------------------------------- uchar (hh)\033[0m\n");

	uc = 0;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%5.2hho", &uc, "uchar");
	visu_compare("% -5.2hho", &uc, "uchar");
	visu_compare("%07.3hho", &uc, "uchar");
	visu_compare("% -7.4hho", &uc, "uchar");
	visu_compare("%-7.4hho", &uc, "uchar");
	visu_compare("%7.0hho", &uc, "uchar");

	uc = -42;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%5.3hho", &uc, "uchar");
	visu_compare("% -5.3hho", &uc, "uchar");
	visu_compare("%07.3hho", &uc, "uchar");
	
	uc = CHAR_MIN;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%3.2hho", &uc, "uchar");
	visu_compare("% -3.2hho", &uc, "uchar");
	visu_compare("%07.3hho", &uc, "uchar");	

	uc = CHAR_MAX;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%3.2hho", &uc, "uchar");
	visu_compare("% -3.2hho", &uc, "uchar");
	visu_compare("%07.3hho", &uc, "uchar");

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF oO CONVERSION TESTS ==========\n");
	ft_putstr("=================================================\033[0m\n");
}

void	uU_tests(void)
{
	unsigned char	uc;
	int				i;
	unsigned int	ui;
	unsigned long	ul;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING uU CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");
	
	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("------------------------------ no lenght modifier\033[0m\n");	
	
	ui = 42;
	printf("**************************** Value = %u\n", ui);
	visu_compare("%u", &ui, "uint");
	visu_compare("%0u", &ui, "uint");
	visu_compare("%09u", &ui, "uint");
	visu_compare("%+u", &ui, "uint");
	visu_compare("%+ u", &ui, "uint");
	visu_compare("%+9u", &ui, "uint");
	visu_compare("%+ 9u", &ui, "uint");
	visu_compare("% 9u", &ui, "uint");
	visu_compare("%3.7u", &ui, "uint");
	visu_compare("%7.3u", &ui, "uint");
	visu_compare("%-03.7u", &ui, "uint");
	visu_compare("%-07.3u", &ui, "uint");
	
	ui = 0;
	printf("**************************** Value = %u\n", ui);
	visu_compare("%u", &ui, "uint");
	
	ui = UINT_MAX;
	printf("**************************** Value = %u\n", ui);
	visu_compare("%u", &ui, "uint");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("---------------------------------------- long (l)\033[0m\n");	

	ul = ULONG_MAX;
	printf("**************************** Value = %lu\n", ul);
	visu_compare("%lu", &ul, "u long");
	visu_compare("%lU", &ul, "u long");
	visu_compare("%30.24lu",&ul, "u long");
	visu_compare("%-30.24lu",&ul, "u long");
	visu_compare("%0-30.24lu",&ul, "u long");

	ul = 0;
	printf("**************************** Value = %ld\n", ul);
	visu_compare("%lu", &ul, "u long");
	visu_compare("%U", &ul, "u long");
	visu_compare("%30.24lu",&ul, "u long");
	visu_compare("%-30.24lu",&ul, "u long");
	visu_compare("%0-30.24lu",&ul, "u long");

	ul = 42;
	printf("**************************** Value = %ld\n", ul);
	visu_compare("%lu", &ul, "u long");
	visu_compare("%U", &ul, "u long");
	visu_compare("%30.24lu",&ul, "u long");
	visu_compare("%-30.24lu",&ul, "u long");
	visu_compare("%0-30.24lu",&ul, "u long");

	visu_compare("%0lu", &ul, "u long");
	visu_compare("%0U", &ul, "u long");
	
	visu_compare("%09lu", &ul, "u long");
	visu_compare("%0U", &ul, "u long");

	visu_compare("%+lu", &ul, "u long");
	visu_compare("%+U", &ul, "u long");

	visu_compare("%+9lu", &ul, "u long");
	visu_compare("%+9U", &ul, "u long");

	visu_compare("%+ 9lu", &ul, "u long");
	visu_compare("%+ 9U", &ul, "u long");

	visu_compare("% +9lu", &ul, "u long");
	visu_compare("% +9U", &ul, "u long");

	visu_compare("% 9lu", &ul, "u long");
	visu_compare("% +9U", &ul, "u long");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("-------------------------------------- uchar (hh)\033[0m\n");

	uc = 0;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%5.2hhu", &uc, "uchar");
	visu_compare("% -5.2hhu", &uc, "uchar");
	visu_compare("%07.3hhu", &uc, "uchar");
	visu_compare("% -7.4hhu", &uc, "uchar");
	visu_compare("%-7.4hhu", &uc, "uchar");
	visu_compare("%7.0hhu", &uc, "uchar");

	uc = -42;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%5.3hhu", &uc, "uchar");
	visu_compare("% -5.3hhu", &uc, "uchar");
	visu_compare("%07.3hhu", &uc, "uchar");
	
	uc = UCHAR_MAX;
	printf("**************************** Value = %hhd\n", uc);
	visu_compare("%3.2hhu", &uc, "uchar");
	visu_compare("% -3.2hhu", &uc, "uchar");
	visu_compare("%07.3hhu", &uc, "uchar");

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF uU CONVERSION TESTS ==========\n");
	ft_putstr("=================================================\033[0m\n");
}

void	xXp_tests(void)
{
	char			c;
	int				i;
	long			l;
	long long		ll;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING xXp CONVERSION TESTS ========\n");
	ft_putstr("=================================================\033[0m\n");

	i = 42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%x", &i, "int");
	visu_compare("%#x", &i, "int");
	visu_compare("%#lx", &i, "int");
	visu_compare("%p", &i, "int");
	visu_compare("%#16x", &i, "int");
	visu_compare("%#16.10x", &i, "int");
	visu_compare("%-#x", &i, "int");
	visu_compare("%0#x", &i, "int");
	visu_compare("%-0#x", &i, "int");
	printf("****************************\n");
	visu_compare("%p", &i, "int");
	visu_compare("%20p", &i, "int");
	visu_compare("%020p", &i, "int");
	visu_compare("%#p", &i, "int");
	visu_compare("%#16p", &i, "int");
	visu_compare("%#16.10p", &i, "int");
	visu_compare("%-#p", &i, "int");
	visu_compare("%0#p", &i, "int");
	visu_compare("%-0#p", &i, "int");
	visu_compare("%7.0p", &i, "int");
//	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("% pl", &i, "int");
	visu_compare("%+p", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%-13p", &i, "int*");

	i = 0;
	printf("**************************** Value = %d\n", i);
	visu_compare("%x", &i, "int");
	visu_compare("%#x", &i, "int");
	visu_compare("%#16x", &i, "int");
	visu_compare("%#16.10x", &i, "int");
	visu_compare("%-#x", &i, "int");
	visu_compare("%0#x", &i, "int");
	visu_compare("%-0#x", &i, "int");
	visu_compare("%7.0p", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%#.0x", &i, "int");
	visu_compare("%.0p", &i, "int");
	visu_compare("%.p", &i, "int");

	i = -42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%x", &i, "int");
	visu_compare("%#16x", &i, "int");
	visu_compare("%#16.10x", &i, "int");
	visu_compare("%-#x", &i, "int");
	visu_compare("%0#x", &i, "int");
	visu_compare("%-0#x", &i, "int");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%.0p", &i, "int");
	visu_compare("%.p", &i, "int");
	
	i = INT_MIN;
	printf("**************************** Value = %d\n", i);
	visu_compare("%x", &i, "int");
	visu_compare("%#x", &i, "int");
	visu_compare("%#lx", &i, "int");
	visu_compare("%#p", &i, "int");
	visu_compare("%#hhx", &i, "int");
	visu_compare("%#hhp", &i, "int");
	visu_compare("%#16x", &i, "int");
	visu_compare("%#16.10x", &i, "int");
	visu_compare("%-#x", &i, "int");
	visu_compare("%0#x", &i, "int");
	visu_compare("%-0#x", &i, "int");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("--------------------------------------- char (hh)\033[0m\n");

	c = 0;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%5.2hhp", &c, "char");
	visu_compare("%5.2p", &c, "char");
	visu_compare("% -5.2hhp", &c, "char");
	printf("\033[31m********************************************* CHECK\033[0m\n");
	visu_compare("%0p", &c, "char");
	visu_compare("%5p", &c, "char");
	visu_compare("%05p", &c, "char");
	visu_compare("%05.p", &c, "char");
	visu_compare("%05.2p", &c, "char");


	visu_compare("%07.3hhp", &c, "char");
	visu_compare("% -7.4hhp", &c, "char");
	visu_compare("%-7.4hhp", &c, "char");
	visu_compare("%7.1hhp", &c, "char");
	visu_compare("%7.0hhp", &c, "char");
	visu_compare("%-7hhp", &c, "char");

	c = -42;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%5.3hhp", &c, "char");
	visu_compare("%5.2p", &c, "char");
	visu_compare("% -5.3hhp", &c, "char");
	visu_compare("%07.3hhp", &c, "char");
	
	c = CHAR_MIN;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%3.2hhp", &c, "char");
	visu_compare("%3.2p", &c, "char");
	visu_compare("% -3.2hhp", &c, "char");
	visu_compare("%07.3hhp", &c, "char");	

	c = CHAR_MAX;
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%3.2hhp", &c, "char");
	visu_compare("%3.2p", &c, "char");
	visu_compare("% -3.2hhp", &c, "char");
	visu_compare("%07.3hhp", &c, "char");

	ft_putendl("\033[33m-------------------------------------------------");	
	ft_putendl("---------------------------------- long long (ll)\033[0m\n");

	ll = LLONG_MIN;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%llx", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llp", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llp", &ll, "long long");
	visu_compare("%#16llx", &ll, "long long");
	visu_compare("%#16.10llx", &ll, "long long");
	visu_compare("%-#llx", &ll, "long long");
	visu_compare("%0#llx", &ll, "long long");
	visu_compare("%-0#llx", &ll, "long long");

	ll = LLONG_MAX;
	printf("**************************** Value = %lld\n", ll);
	visu_compare("%llx", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llp", &ll, "long long");
	visu_compare("%#llx", &ll, "long long");
	visu_compare("%#llp", &ll, "long long");
	visu_compare("%#16llx", &ll, "long long");
	visu_compare("%#16.10llx", &ll, "long long");
	visu_compare("%-#llx", &ll, "long long");
	visu_compare("%0#llx", &ll, "long long");
	visu_compare("%-0#llx", &ll, "long long");
	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF xXp CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");

}

void	cC_tests(void)
{
	char			c;
	wint_t			wi;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING cC CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");

	c = 'A';
	printf("**************************** Value = %c\n", c);
	visu_compare("%c", &c, "char");
	visu_compare("%10c", &c, "char");
	visu_compare("%.10c", &c, "char");
	visu_compare("%10.5c", &c, "char");
	visu_compare("% 10.5c", &c, "char");
	visu_compare("%-10.5c", &c, "char");
	visu_compare("%010.5c", &c, "char");
	visu_compare("%#10.5c", &c, "char");
	visu_compare("%hhc", &c, "char");
	visu_compare("%lc", &c, "char");




	wi = L'\xe9';
	ft_putbin((wint_t)wi, sizeof(wint_t));
	ft_putchar('\n');
	printf("**************************** Value = %d (%C)\n", wi, wi);
	visu_compare("%C", &wi, "wint_t");
	visu_compare("%lc", &wi, "wint_t");
	visu_compare("%llc", &wi, "wint_t");
	visu_compare("%hhc", &wi, "wint_t");




	wi = 0xD7FF;
	ft_putbin((wint_t)wi, sizeof(wint_t));
	ft_putchar('\n');
	printf("**************************** Value = %d\n", wi);
	visu_compare("%C", &wi, "wint_t");
	visu_compare("%lc", &wi, "wint_t");
	visu_compare("%llc", &wi, "wint_t");
	visu_compare("%hhc", &wi, "wint_t");


	c = 0;
	ft_putbin((char)c, sizeof(char));
	ft_putchar('\n');
	printf("**************************** Value = %hhd\n", c);
	visu_compare("%c", &c, "char");
	visu_compare("%.c", &c, "char");
	
	c = CHAR_MIN;
	ft_putbin((char)c, sizeof(char));
	ft_putchar('\n');
	printf("**************************** Value = %hd\n", c);
	visu_compare("%c", &c, "char");
	visu_compare("%.c", &c, "char");
	visu_compare("%llc", &c, "char");
	visu_compare("%hhc", &c, "char");

	c = -1;
	c = INT_MIN;
	ft_putbin((char)c, sizeof(char));
	ft_putchar('\n');
	printf("**************************** Value = %hd\n", c);
	visu_compare("%c", &c, "char");
	visu_compare("%.c", &c, "char");
	visu_compare("%llc", &c, "char");
	visu_compare("%hhc", &c, "char");
/*
	wi = -1;
	ft_putbin((wint_t)wi, sizeof(wint_t));
	ft_putchar('\n');
	printf("**************************** Value = %d\n", wi);
	visu_compare("%llc", &wi, "wint_t");
	visu_compare("%hhc", &wi, "wint_t");
	visu_compare("%C", &wi, "wint_t");
	visu_compare("%lc", &wi, "wint_t");
*/


	wi = 0xD800;
	ft_putbin((wint_t)wi, sizeof(wint_t));
	ft_putchar('\n');
	printf("**************************** Value = %d\n", wi);
	visu_compare("%llc", &wi, "wint_t");
	visu_compare("%hhc", &wi, "wint_t");
	visu_compare("%lc", &wi, "wint_t");
	visu_compare("%C", &wi, "wint_t");


/*
	wi = -1;
	ft_putbin((wint_t)wi, sizeof(wint_t));
	ft_putchar('\n');
	printf("**************************** Value = %d\n", wi);
	visu_compare("%C", &wi, "wint_t");
	visu_compare("%lc", &wi, "wint_t");
	visu_compare("%llc", &wi, "wint_t");
	visu_compare("%hhc", &wi, "wint_t");
*/

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF cC CONVERSION TESTS ==========\n");
	ft_putstr("=================================================\033[0m\n");

}

void	sS_tests(void)
{
	int		*ptrj;
	char	*str3 = "Hello yop!";
	wchar_t	*wstr = L"er我是ty一只猫。er5";
	wchar_t	*wstr2 = L"er我是ty一只猫。er5d";
	wchar_t	*wstr3 = L"er我是ty一只猫。er5是";
//	wchar_t	*wstr4;

//	wstr4 = ft_memalloc(50);

/*
	ft_print_memory(wstr, ft_wstr_memsize(wstr));
	ft_putchar('\n');
	ft_print_memory(&wstr[1], ft_wstr_memsize(wstr));
	ft_putchar('\n');
	ft_print_memory(wstr, ft_wstr_utf8len(wstr));
	ft_putchar('\n');
	printf("wstr width = %d,\tstring = %S\n", ft_wstr_utf8len(wstr), wstr);
	printf("wstr2 width = %d,\tstring = %S\n", ft_wstr_utf8len(wstr2), wstr2);
	printf("wstr3 width = %d,\tstring = %S\n", ft_wstr_utf8len(wstr3), wstr3);
	printf("wstr3 wcslen = %d,\tstring = %S\n", ft_wcslen(wstr3), wstr3);
	printf("wstr3 wstr_memsize = %d,\tstring = %S\n", ft_wstr_memsize(wstr3), wstr3);
	printf("wstr3 utf8len = %d,\tstring = %S\n", ft_wstr_utf8len(wstr3), wstr3);


	ft_putchar('\n');
	ft_print_memory(wstr4, 30);
	ft_putchar('\n');

	ft_utf8ncpy(wstr4, wstr2, 4);

	printf("\nwstring = %S\n", wstr4);
	ft_print_memory(wstr4, 30);
	ft_putchar('\n');
*/
	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING sS CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");

	printf("**************************** Value = %s\n", str3);
	visu_compare("{%s}", str3, "char*");
	visu_compare("{%05.s}", str3, "char*");
	visu_compare("{%015s}", str3, "char*");
	visu_compare("{%015.8s}", str3, "char*");
	visu_compare("{%015s}", str3, "char*");
	visu_compare("{%015.s}", str3, "char*");
	visu_compare("{%015.1s}", str3, "char*");
	visu_compare("{%15.s}", str3, "char*");
	visu_compare("{%15s}", str3, "char*");

	printf("**************************** Value = %s\n", NULL);
	visu_compare("{% s}", NULL, "char*");
	visu_compare("{%0s}", NULL, "char*");
	visu_compare("{%0.s}", NULL, "char*");
	visu_compare("{%05.s}", NULL, "char*");	
	visu_compare("{%04.s}", NULL, "char*");	
	visu_compare("{%04.2s}", NULL, "char*");	
	visu_compare("{% S}", NULL, "wchar_t*");

	printf("**************************** Value = %S\n", wstr);
	visu_compare("{%S}", wstr, "wchar_t*");
	visu_compare("{%30s}", str3, "char*");
	visu_compare("{%-30s}", str3, "char*");
	visu_compare("{%30S}", wstr, "wchar_t*");
	visu_compare("{%-30S}", wstr, "wchar_t*");
	visu_compare("{%0.1S}", wstr, "wchar_t*");
	visu_compare("{%0.2S}", wstr, "wchar_t*");
	visu_compare("{%0.3S}", wstr, "wchar_t*");
	visu_compare("{%0.4S}", wstr, "wchar_t*");
	visu_compare("{%0.5S}", wstr, "wchar_t*");
	visu_compare("{%0.6S}", wstr, "wchar_t*");
	visu_compare("{%0.7S}", wstr, "wchar_t*");
	visu_compare("{%0.8S}", wstr, "wchar_t*");
	visu_compare("{%0.25S}", wstr3, "wchar_t*");
	visu_compare("{%0.28S}", wstr3, "wchar_t*");

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF sS CONVERSION TESTS ==========\n");
	ft_putstr("=================================================\033[0m\n");
}

void	fF_tests(void)
{
	float	flt;
	double	dbl;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("========== STARTING fF CONVERSION TESTS =========\n");
	ft_putstr("=================================================\033[0m\n");

	ft_putchar('\n');
	flt = 42.6543;
	ft_print_memory(&flt, sizeof(float));
	ft_putbin(flt, sizeof(float));
	ft_putchar('\n');
	printf("******************** Value (float) = %f\n", flt);
	visu_compare("%f", &flt, "float");
	visu_compare("%f", &flt, "double");
	visu_compare("%F", &flt, "float");
	visu_compare("%F", &flt, "double");

	dbl = 42.6543;
	ft_print_memory(&flt, sizeof(double));
	ft_putbin(dbl, sizeof(double));
	ft_putchar('\n');
	printf("******************** Value (double) = %f\n", flt);
	visu_compare("%f", &dbl, "float");
	visu_compare("%f", &dbl, "double");
	visu_compare("%F", &dbl, "float");
	visu_compare("%F", &dbl, "double");

	ft_putstr("\033[33m=================================================\n");
	ft_putstr("=========== END OF fF CONVERSION TESTS ==========\n");
	ft_putstr("=================================================\033[0m\n");
}

void	wild_tests(void)
{
	int				precision;
	int				field_width;
	int				i;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("=========== STARTING * WILDCARD TESTS ===========\n");
	ft_putstr("=================================================\033[0m\n");

	i = 42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%:d", &i, "int");
	visu_compare("%*d", &i, "int");
	visu_compare("%.*d", &i, "int");

	printf("i = '%*.*d'\n", 6, 3, i);
	ft_putchar('\n');

	printf("{%.*s}\n", -5, "42");
	ft_printf("{%.*s}\n", -5, "42");

	ft_putchar('\n');

	printf("*3d (5, 0) : {%*3d}\n", 5, 0);
	ft_printf("*3d (5, 0) : {%*3d}\n", 5, 0);

	printf("3*d (5, 0) : {%3*d}\n", 0, 0);
	ft_printf("3*d (5, 0) : {%3*d}\n", 0, 0);

	printf("*d (0, 0) : {%*d}\n", 0, 0);
	ft_printf("*d (0, 0) : {%*d}\n", 0, 0);

	printf("3d (0) : {%3d}\n", 0);
	ft_printf("3d (0) : {%3d}\n", 0);

	printf("*5d (5, 0) : {%*5d}\n", 5, 0);
	ft_printf("*5d (5, 0) : {%*5d}\n", 5, 0);

	ft_putchar('\n');
	ft_printf("{%*3d}\n", 0, 0);
	
	ft_putstr("\033[33m=================================================\n");
	ft_putstr("============ END OF * WIDLCARD TESTS ============\n");
	ft_putstr("=================================================\033[0m\n");

}

void	escape_tests(void)
{
	int				i;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("============= STARTING ESCAPE TESTS =============\n");
	ft_putstr("=================================================\033[0m\n");

	i = 0;
	printf("**************************** Value = %d\n", i);
	visu_compare("% Zoooo", &i, "int");
	visu_compare("% Zoooo", NULL, "none");
	visu_compare("%Zoooo", NULL, "none");
	visu_compare("%0.Zoooo", NULL, "none");
	visu_compare("%020.10Zoooo", NULL, "none");
	visu_compare("%-020.10Zoooo", NULL, "none");
	visu_compare("%0-20.10Zoooo", NULL, "none");
	visu_compare("%#0-20.10Zoooo", NULL, "none");
	visu_compare("% 20.10Zoooo", NULL, "none");
	visu_compare("%-20.10Zoooo", NULL, "none");
	visu_compare("%-20.Zoooo", NULL, "none");
	visu_compare("{%10R}", NULL, "none");
	visu_compare("%", NULL, "none");


	ft_putstr("\033[33m=================================================\n");
	ft_putstr("============== END OF ESCAPE TESTS ==============\n");
	ft_putstr("=================================================\033[0m\n");

}

void	bin_tests(void)
{
	short			sh;
	int				i;
	long long		ll;
	unsigned int	ui;

	ft_putstr("\n\033[33m=================================================\n");
	ft_putstr("============= STARTING BINARY TESTS =============\n");
	ft_putstr("=================================================\033[0m\n");

	i = 0;
	printf("**************************** Value = %d\n", i);
	visu_compare("%b", &i, "int");

	ll = LLONG_MAX;
	printf("**************************** Value = %d\n", i);
	visu_compare("%llb", &ll, "long long");
	
	i = INT_MAX;
	printf("**************************** Value = %d\n", i);
	visu_compare("%b", &i, "int");
	visu_compare("%b", &i, "int");

	i = INT_MIN;
	printf("**************************** Value = %d\n", i);
	visu_compare("%b", &i, "int");

	i = 42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%b", &i, "int");
	
	i = -42;
	printf("**************************** Value = %d\n", i);
	visu_compare("%b", &i, "int");

	ui = UINT_MAX;
	printf("**************************** Value = %u\n", ui);
	visu_compare("%b", &ui, "uint");

	sh = SHRT_MAX;
	printf("**************************** Value = %u\n", ui);
	visu_compare("%hb", &sh, "short");


	ft_putstr("\033[33m=================================================\n");
	ft_putstr("============== END OF BINARY TESTS ==============\n");
	ft_putstr("=================================================\033[0m\n");

}

int	main(void)
{
	ft_putstr("\033[34m=================================================\n");
	ft_putstr("============ STARTING ALL UNIT TESTS  ===========\n");
	ft_putstr("=================================================\033[0m\n\n");


//	printf("\033[31m********************************************* CHECK\033[0m\n");

	setlocale(LC_ALL, "");


//	dDi_tests();
//	uU_tests();
//	oO_tests();
//	xXp_tests();
//	sS_tests();
	cC_tests();
//	fF_tests();
//	wild_tests();
//	escape_tests();
//	bin_tests();

/*
	int		ret;
	char	c;

	c = -128;
	ret = printf("%lc\n", c);
	ft_printf("ret = %d\n", ret);
	
	ret = printf("blabla\n");
	ft_printf("ret = %d\n", ret);
*/
/*
	int		ret;
	char	   c;

	c = -128;
	ret = printf("%lc\n", c);
	ft_putstr("ret = ");
	ft_putnbr(ret);
	ft_putchar('\n');

	ret = printf("blabla\n");
	ft_putstr("ret = ");
	ft_putnbr(ret);
	ft_putchar('\n');
*/
//	printf("%s", 1);
//	ft_printf("%s", 1);

//	ft_printf("%c%c%c%c", NULL);
}




//	OLD STUFF
//
/*
	i = 4294967296;
	ui = 4294967296;

	i = INT_MAX;
	ui = UINT_MAX;

	printf("int = %d, uint = %d\n", sizeof(int), sizeof(unsigned int));

	ft_print_memory(&i, sizeof(int));
	ft_putchar('\n');
	ft_print_memory(&ui, sizeof(unsigned int));
	ft_putchar('\n');

	ft_printf("%x\n", 4294967296);
	ft_putchar('\n');
	printf("%x\n", 4294967296);
	ft_putchar('\n');
*/




/*
	i = 42;
	i = INT_MAX;
	ft_putbin(i, sizeof(int));
	ft_putchar('\n');
	ft_print_memory(&i, sizeof(int));
	ft_putchar('\n');
*/

//	ft_putstr("=================================================\n");

	
//	compare_flags_on_int("p");
	


//	visu_compare("4567 |%-10]5d| plip\n", ptrj, "int");

//	printf("4567 |%-10]5d| plip\n", 12);
//	printf("4567 |%10]5d| plip\n", 12);

//	compare_flags_on_int("p");

//	str2 = ft_strdup("printf\t\t>>>\t'\033[32mThis is a simple string test.\033[0m'\n");

/*	
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
*/
/*
	ft_putendl("=======================================");
	
	


	ulong = ULONG_MAX / 2;
	visu_compare("%u", &ulong, "u long");
	visu_compare("%U", &ulong, "u long");
	
	c = 'f';

	
	c = 'f';
	wc = L'\xe9';

	ft_print_memory(&c, sizeof(char));
	ft_print_memory(&wc, sizeof(char));
	ft_print_memory(&wc, sizeof(wchar_t));
	ft_print_memory(&wc, sizeof(wint_t));

	printf("wchar_t = %d\n", (int)wc);

	ft_putendl("=======================================\n");
*/
/*
	visu_compare("%ll# +++-+-- h00012.3.5.28d", ptrj, "int");
	j = 0;
	visu_compare("{%3c}", &j, "char");
	c = 'a';
	visu_compare("%c", &c, "char");
	visu_compare("%3c", &c, "char");
	visu_compare("{%10R}", NULL, "none");
	visu_compare("% Zoooo", NULL, "none");
	ft_putendl("=======================================\n");
	
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
*/

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
/*
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
	
	visu_compare("{%03.2d}", &i, "int");
	i = -1;
	visu_compare("{%03.2d}", &i, "int");
	visu_compare("{%3.2d}", &i, "int");
	visu_compare("{%-3.2d}", &i, "int");
	i = INT_MIN;
	visu_compare("{%d}", &i, "int");
	i = -42;
	visu_compare("{%10d}", &i, "int");
	
	visu_compare("{%15.4d}", &i, "int");
*/
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
//	i = 42;
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
