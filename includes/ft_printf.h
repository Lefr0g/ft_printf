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


typedef union	u_param
{
	int		d;
	long	l;
	char	c;
	char	*s;
}				t_param;

int				ft_printf(const char *restrict format, ...);

int				convert(const char *restrict format, va_list ap);

void			ft_puthex(long n, char *mode);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
int				ft_strcmp(const char *s1, const char *s2);

#endif
