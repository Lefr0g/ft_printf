/* ************************************************************************** **
 *
 *
 *
 *
 *
 *
 *
 *
 *
** ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>
# include <limits.h>

void	visu_compare(char *str, void *arg, char *type)
{
	char	*pf_str;
	char	*ftpf_str;

	pf_str = ft_strjoin("printf\t\t>>>\t'\033[32m", str);
	pf_str = ft_strjoin(pf_str, "\033[0m'\n");
	ftpf_str = ft_strjoin("ft_printf\t>>>\t'\033[36m", str);
	ftpf_str = ft_strjoin(ftpf_str, "\033[0m'\n");
	
	ft_putstr("Tested string : '");
	ft_putstr("\033[35m");
	ft_putstr(str);
	ft_putstr("\033[0m");
	ft_putendl("'");
//	ft_putchar('\n');

	if (!ft_strcmp(type, "int"))
	{
		printf(pf_str, *(int*)arg);
		ft_printf(ftpf_str, *(int*)arg);
	}
	else if (!ft_strcmp(type, "char"))
	{
		printf(pf_str, *(char*)arg);
		ft_printf(ftpf_str, *(char*)arg);
	}
	else if (!ft_strcmp(type, "char*"))
	{
		printf(pf_str, (char*)arg);
		ft_printf(ftpf_str, (char*)arg);
	}
	else if (!ft_strcmp(type, "long"))
	{
		printf(pf_str, *(long*)arg);
		ft_printf(ftpf_str, *(long*)arg);
	}
	else if (!ft_strcmp(type, "long long"))
	{
		printf(pf_str, *(long long*)arg);
		ft_printf(ftpf_str, *(long long*)arg);
	}

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
void	compare_flags_on_int(char *str)
{
	int	i;

	ft_putstr("=================================================\n");
	i = 42;
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = 0;
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = -42;
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = INT_MIN;
	compare_flags(str, &i, "int");
	ft_putstr("=================================================\n");
	i = INT_MAX;
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
	int	*ptrj;

	j = -42;
	ptrj = &j;

	ft_printf("%d\n", j);
	compare_lenmods("d", &j, "long long");
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
