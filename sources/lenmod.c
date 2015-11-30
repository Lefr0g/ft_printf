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

#include "ft_printf.h"

/*
void	*manage_lenmod(va_list *ap, t_env *e)
{
	void	*dst;

//	if (!e->mod)
//		return (*(int*)arg);
	dst = ft_memalloc(16);
	if (!dst)
		return (NULL);

*	Ne semble pas fonctionner sans casting en int
*
	if (sizeof(*arg) != sizeof(int))
	{
		ft_putstr("\nError > argument is not an int\n");
		ft_putstr("sizeof(*arg) = ");
		ft_putnbr(sizeof(*arg));
		ft_putstr(" bytes\n");
		exit(1);
	}
*

//	printf("Address arg = %p\n", arg);
	
	if (!ft_strcmp(e->mod, "hh"))
	{
		if (ft_strchr("ouxX", e->conversion))

		ft_memmove(dst, arg, sizeof(char));
		ft_memcpy(arg, dst, sizeof(int));
	}
	else if (!ft_strcmp(e->mod, "h"))
	{
		ft_memmove(dst, arg, sizeof(short));
		ft_memcpy(arg, dst, sizeof(int));
	}
	else if (!ft_strcmp(e->mod, "l"))
	{
		ft_memmove(dst, arg, sizeof(long));
		ft_memcpy(arg, dst, sizeof(long));
	}
	else if (!ft_strcmp(e->mod, "ll"))
	{
		ft_memmove(dst, arg, sizeof(long long));
		ft_memcpy(arg, dst, sizeof(long long));
	}
	free(dst);
//	printf("\narg = %d, dst = %d\n", *(int*)arg, *(int*)dst);
//	printf("Address arg = %p\n", arg);

	return();
}
*/
