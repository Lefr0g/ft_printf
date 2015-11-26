/* ************************************************************************** */
 *
 *
 *
 *
 *
 *
 *
 *
 *
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

void	visu_compare(char *str, void *arg)
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

	printf(pf_str, *(int*)arg);
	ft_printf(ftpf_str, *(int*)arg);
	ft_putchar('\n');
}

int	main(void)
{
	int	i = 42;

	visu_compare("%d", &i);
	visu_compare("%5d", &i);
	visu_compare("%0d", &i);
	visu_compare("%05d", &i);
	visu_compare("%+d", &i);
	visu_compare("%+5d", &i);

	ft_putstr("=================================================\n");
	
//	printf("%+s", "check\n");
//	visu_compare("%+s", &i);
//	visu_compare("%+S", &i);
	visu_compare("%+p", &i);
	visu_compare("%+d", &i);
	visu_compare("%+D", &i);
	visu_compare("%+i", &i);
	visu_compare("%+o", &i);
	visu_compare("%+O", &i);
	visu_compare("%+u", &i);
	visu_compare("%+U", &i);
	visu_compare("%+x", &i);
	visu_compare("%+X", &i);
	visu_compare("%+c", &i);
	visu_compare("%+C", &i);

//	visu_compare("%#5x", &i);

	return (0);
}
