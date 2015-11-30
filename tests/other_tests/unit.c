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

void	visu_compare(char *str, void *arg, char* type)
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
	ft_putchar('\n');
}

int	main(void)
{
	int		i = -6324;
	char	c;
	char	*str;

	c = 'D';
	str = ft_strdup("String test OK");

	(void)str;
//	printf("%i\n", i);
//	ft_printf("%i\n", i);
	
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
/*
	visu_compare("%i", &i, "int");
	visu_compare("%5i", &i, "int");
	visu_compare("%.5i", &i, "int");
	visu_compare("%0i", &i, "int");
	visu_compare("%05i", &i, "int");
	visu_compare("%+i", &i, "int");
	visu_compare("%+5i", &i, "int");
	*/
	visu_compare("%o", &i, "int");
	visu_compare("%llo", &i, "int");
	visu_compare("%#o", &i, "int");
	visu_compare("%0o", &i, "int");

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
