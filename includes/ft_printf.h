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

# ifdef __APPLE__
#  define SYS_OS "darwin"
# elif __linux__
#  define SYS_OS "linux"
# else
#  define SYS_OS "unknown"
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "linkto_libft.h"
# include <wchar.h>

typedef union	u_param
{
	size_t				st;
	int					i;
	short				sh;
	unsigned short		ush;
	unsigned int		u;
	long				l;
	unsigned long		ul;
	long long			ll;
	unsigned long long	ll;
	char				c;
	signed char			sc;
	unsigned char		uc;
	wchar_t				wc;
	wint_t				wi;
	intmax_t			imax;
	uintmax_t			uimax;
	char				*s;
}				t_param;

typedef struct	s_env
{
	char		*os;
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
void			convert_di(va_list *ap, t_env *e);
void			convert_uU(va_list *ap, t_env *e);


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

//	NEW
void			*manage_lenmod(va_list *ap, t_env *e);

//	NEW
void			manage_print(t_env e);


char			*manage_precision_s(char *str, t_env *e);

int				get_max(int a, int b);
// int				ft_charinstr(const char *str, char c);

#endif
