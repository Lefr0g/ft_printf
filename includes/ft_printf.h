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
	short			sh;
	unsigned int	u;
	long			l;
	long long		ll;
	char			c;
	char			*s;
}				t_param;

typedef struct	s_env
{
	t_param		*param;
	int			index;
	char		*lenmods;
	char		*conversions;
	int			alt;
	int			zero;
	int			neg;
	int			space;
	int			plus;
	int			field_width;
	int			precisflag;
	int			precision;
	int			outputlen;
	char		*mod;
	char		conversion;
	char		spacer;
}				t_env;

int				ft_printf(const char *restrict format, ...);

int				ft_printf_init(t_env *e);
int				ft_printf_reinit(t_env *e);
int				directives(const char *restrict format, va_list *ap, t_env *e);
int				convert(va_list *ap, t_env *e);

int				get_flags(const char *restrict format, t_env *e);

void			ft_puthex(unsigned int n, char *mode);
void			ft_puthex_ull(unsigned long long int n, char *mode);
void			ft_putoctal(unsigned int n);

void			ft_putnbr_ull(unsigned long long int n);
char			*ft_itoa_ll(long long int n, unsigned int base);

int				manage_field_width(t_env *e);
int				manage_precision(void *value, int isneg, t_env *e);
//	NEW
int				manage_flags(int ispos, t_env *e);


char			*manage_precision_s(char *str, t_env *e);

int				get_max(int a, int b);
// int				ft_charinstr(const char *str, char c);

#endif
