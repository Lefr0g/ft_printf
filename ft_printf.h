/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 11:46:15 by amulin            #+#    #+#             */
/*   Updated: 2015/06/05 16:05:44 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef union	u_param
{
	int		d;
	long	l;
	char	c;
	char	*s;
}				t_param;

int				ft_printf(const char *restrict format, ...);

#endif
