/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:15 by amulin            #+#    #+#             */
/*   Updated: 2015/06/10 19:43:37 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "linkto_libft.h"

typedef union	u_param
{
	int				d;
	unsigned int	u;
	long			l;
	char			c;
	char			*s;
}				t_param;

typedef struct	s_env
{
	int			index;
	char		*lenmods;
	char		*conversions;
	int			alt;
	int			zero;
	int			neg;
	int			space;
	int			plus;
	int			field_width;
	int			precision;
	char		lenght;
	char		conversion;
}				t_env;

int				ft_printf(const char *restrict format, ...);

int				ft_printf_init(t_env *e);
int				directives(const char *restrict format, va_list *ap, t_env *e);
int				convert(va_list *ap, t_env *e);

void			ft_puthex(unsigned int n, char *mode);
void			ft_puthex_ull(unsigned long long int n, char *mode);
void			ft_putoctal(unsigned int n);

void			ft_putnbr_ull(unsigned long long int n);

int				ft_charinstr(const char *str, char c);

#endif
