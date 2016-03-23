/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:15 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 22:17:16 by amulin           ###   ########.fr       */
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
void			ftpf_conversion_call(t_env *e, const char *restrict format,
		va_list *ap, int *convlen);


int				convert(va_list *ap, t_env *e);


/*
**	ftpf_init.c
*/
int				ftpf_init_env(t_env *e);
void			ftpf_init_mallocs(t_env *e);
int				ftpf_reinit_env(t_env *e);
void			ftpf_init_convfunctions_pointers(t_env *e);
void			ftpf_free_all(t_env *e);

/*
**	ftpf_directives.c
*/
int				ftpf_directives(const char *restrict format, va_list *ap,
		t_env *e);
void			ftpf_directives_action(const char *restrict f, va_list *ap,
		t_env *e);
void			ftpf_get_precision(const char *restrict format, t_env *e);
void			ftpf_get_lenmod(const char *restrict format, t_env *e);
void			ftpf_wrongchar_handler(const char *restrict format,
		t_env *e);
//void			(*ftpf_get_conv_funct(t_env *e, char conv))(va_list *ap, t_env *e);

/*
**	conversions_1.c
*/
void			ftpf_convert_di(va_list *ap, t_env *e);
void			ftpf_convert_u(va_list *ap, t_env *e);
void			ftpf_convert_o(va_list *ap, t_env *e);
void			ftpf_convert_xp(va_list *ap, t_env *e);
void			ftpf_convert_c(va_list *ap, t_env *e);
void			ftpf_convert_s(va_list *ap, t_env *e);
void			ftpf_convert_b(va_list *ap, t_env *e);


void			ftpf_process_output_rules(t_env *e);
void			ftpf_write_di_param(t_env *e);
void			ftpf_write_o_param(t_env *e);
void			ftpf_write_xp_param(t_env *e);

/*
**	ftpf_lenmods_signed.c
*/
void			ftpf_manage_lenmod_di(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_di_sub(va_list *ap, t_env *e, char **ret);

/*
**	ftpf_lenmods_text.c
*/
void			ftpf_manage_lenmod_c(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_s(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_s_wide(va_list *ap, t_env *e);
void			ftpf_s_nullexception(t_env *e);

/*
**	ftpf_lenmods_unsigned.c
*/
void			ftpf_manage_lenmod_u(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_u_sub(va_list *ap, t_env *e, char **ret);
void			ftpf_manage_lenmod_o(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_o_sub(va_list *ap, t_env *e, char **ret);
void			ftpf_manage_lenmod_xp(va_list *ap, t_env *e);
void			ftpf_manage_lenmod_xp_sub(va_list *ap, t_env *e, char **ret);

//	LEGACY
void			manage_modifiers_ouxX(va_list *ap, t_env *e);

/*
**	ftpf_precision.c
*/
int				ftpf_manage_precision(void *value, t_env *e);
char			*manage_precision_s(char *str, t_env *e);
int				ftpf_manage_field_width(t_env *e);

/*
**	ftpf_flags.c
*/
int				ftpf_get_flags(const char *restrict format, t_env *e);
int				ftpf_process_flags(t_env *e);
void			ftpf_process_flag_alt(t_env *e);
void			ftpf_process_flag_plus(t_env *e);


/*
**	printing.c
*/
void			manage_print_all(t_env *e);
void			print_null_ptr(t_env *e);

/*
**	others
*/

int				ft_getmax(int a, int b);
void			ft_puthex_ull(unsigned long long int n, char *mode);
void			ft_putoctal(unsigned long long n);
void			ft_putnbr_ull(unsigned long long int n);
void			ft_putnbr_ll(long long n);
char			*ft_itoa_ll(long long int n, unsigned int base);
char			*ft_itoa_ull(unsigned long long n, unsigned int base);


#endif
