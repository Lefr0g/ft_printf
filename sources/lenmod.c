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

// TO DO : FINIR CETTE VERSION !
//
// Rappel : le lenmod est gere automatiquement par l'union param
//
void	manage_print(t_env *e)
{
	if (e->conversion == 'c')
	{
		if (e->mod[0] == 'l' )
//			ft_putchar_wchar_t(e->param->wc);
			ft_putchar(e->param->wc);
		else
			ft_putchar(e->param->c);
	}
	else if (e->conversion == 'u')
		ft_putnbr_ull(e->param->u);
	else if (e->conversion == 'd' || e->conversion == 'i')
		ft_putnbr(e->param->i);
}
