/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:15 by amulin            #+#    #+#             */
/*   Updated: 2016/03/17 13:33:51 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef __APPLE__
#  define SYS_OS "darwin"
#  define NULL_PTR "0x0"
# elif __linux__
#  define SYS_OS "linux"
#  define NULL_PTR "(nil)"
# else
#  define SYS_OS "unknown"
#  define NULL_PTR "0x0"
# endif

# define DEBUG_MODE	0

# if DEBUG_MODE == 1
#  define PRECIS_ZERO 'p'
#  define PRECIS_PLUS '.'
#  define PRECIS_MINUS '='
#  define CONV_MINUS '|'
#  define FW_PLUS '*'
#  define FW_MINUS '_'
#  define FLAG_0_SPACER 'o'
# else
#  define PRECIS_ZERO '0'
#  define PRECIS_PLUS '+'
#  define PRECIS_MINUS '-'
#  define CONV_MINUS '-'
#  define FW_PLUS '+'
#  define FW_MINUS '-'
#  define FLAG_0_SPACER '0'
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "linkto_libft.h"
# include <wchar.h>
# include <inttypes.h>

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
	unsigned long long	ull;
	char				c;
	signed char			sc;
	unsigned char		uc;
	wchar_t				wc;
	wint_t				wi;
	wchar_t				*ws;
	intmax_t			imax;
	uintmax_t			uimax;
	char				*s;
}				t_param;

typedef struct			s_env
{
	char				*os;
	t_param				*param;
	int					index;
	char				*flags;
	char				*lenmods;
	char				*conversions;
	int					alt;
	int					zero;
	int					neg;
	int					space;
	int					plus;
	int					field_width;
	int					precisflag;
	int					precision;
	int					outputlen;
	char				*mod;
	unsigned char		conversion;
	char				spacer;
	char				*xX_prefix;
	int					p_conv;
	int					null_printed;
	void				(*conversion_function)(va_list *ap, struct s_env *e);
	void				(*conv_funct_table[128])(va_list *ap, struct s_env *e);
	int					isneg;
	int					isnull;
	int					noconv;
}						t_env;

int				ft_printf(const char *restrict format, ...);

int				convert(va_list *ap, t_env *e);


/*
**	ftpf_init.c
*/
int				ftpf_init_env(t_env *e);
int				ftpf_reinit_env(t_env *e);
void			ftpf_init_convfunctions_pointers(t_env *e);

/*
**	ftpf_directives.c
*/
int				ftpf_directives(const char *restrict format, va_list *ap,
		t_env *e);
void			ftpf_get_precision(const char *restrict format, t_env *e);
void			ftpf_get_lenmod(const char *restrict format, t_env *e);
void			ftpf_directive_wrongchar_handler(const char *restrict format,
		t_env *e);
//void			(*ftpf_get_conv_funct(t_env *e, char conv))(va_list *ap, t_env *e);

/*
**	conversions_1.c
*/
void			ftpf_convert_dDi(va_list *ap, t_env *e);
void			ftpf_convert_xXp(va_list *ap, t_env *e);


void			convert_uU(va_list *ap, t_env *e);
void			convert_cC(va_list *ap, t_env *e);
void			convert_oO(va_list *ap, t_env *e);
void			convert_xX(va_list *ap, t_env *e);
void			convert_sS(va_list *ap, t_env *e);

void			ftpf_process_output_rules(t_env *e);
void			ftpf_write_dDi_param(t_env *e);
void			ftpf_write_xXp_param(t_env *e);

/*
**	modifiers.c
*/
void			manage_modifiers_dDi(va_list *ap, t_env *e);
void			manage_modifiers_xXp(va_list *ap, t_env *e);

//	LEGACY
void			manage_modifiers_ouxX(va_list *ap, t_env *e);

/*
**	precision.c
*/
int				manage_precision(void *value, t_env *e);
char			*manage_precision_s(char *str, t_env *e);
int				manage_field_width(t_env *e);

/*
**	ftpf_flags.c
*/
int				ftpf_get_flags(const char *restrict format, t_env *e);
int				ftpf_process_flags(t_env *e);
int				ftpf_apply_flags(t_env *e);


/*
**	printing.c
*/
void			manage_print_all(t_env *e);
void			print_null_ptr(t_env *e);


/*
**	misc.c
*/
int				get_max(int a, int b);

/*
**	others
*/
void			ft_puthex(unsigned int n, char *mode);
void			ft_puthex_ull(unsigned long long int n, char *mode);
void			ft_putoctal(unsigned long n);

void			ft_putnbr_void(void *n, size_t size);
void			ft_putnbr_short(short n);
void			ft_putnbr_char(signed char n);
void			ft_putnbr_ull(unsigned long long int n);
void			ft_putnbr_ll(long long n);
char			*ft_itoa_ll(long long int n, unsigned int base);
char			*ft_itoa_ull(unsigned long long n, unsigned int base);


#endif
