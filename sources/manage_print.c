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
// TO DO : FINIR CETTE VERSION !
//
// Rappel : le lenmod est gere automatiquement par l'union param
//
void	manage_print_all(t_env *e)
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
	else if (e->conversion == 'o')
		ft_putoctal(e->param->u);
}
