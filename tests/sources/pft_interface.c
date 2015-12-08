/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "ft_printf_test.h"

int	center_ui_str(char *str, char separator)
{
	int	i;
	int	fillable;

	i = 0;
	fillable = TERM_WIDTH - ft_strlen(str);

	ft_putchar('\n');
	while (i < fillable / 2)
	{
		ft_putchar(separator);
		i++;
	}
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar(' ');
	while (i < fillable)
	{
		ft_putchar(separator);
		i++;
	}
	ft_putchar('\n');
	return (0);
}

void	check_ptr_null(void *ptr, char *function, char *message)
{
	if (!ptr)
	{
		ft_putstr("ERROR : in function ");
		ft_putstr(function);
		ft_putstr(" : ");
		ft_putendl(message);
		exit(1);
	}
}

char	*ansi_transform(char *str, char *ansi_code)
{
	char	*buf;

	buf = ft_strdup(str);
	buf = ft_strjoin(ansi_code, str);
	check_ptr_null(buf, "set_color()", "ft_strjoin() failed");
	buf = ft_strjoin(buf, ANSI_RESET);
	check_ptr_null(buf, "set_color()", "ft_strjoin() failed");

	return (buf);
}
