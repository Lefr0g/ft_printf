/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:44:07 by amulin            #+#    #+#             */
/*   Updated: 2016/02/24 17:57:49 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <locale.h>
#include <wchar.h>

/*
** TODO : create function that converts the binary value input (code point)
** into UTF-8 binary, then print this output to the terminal.
** Attention : endianness must be taken care of.
*/

void	ft_putwchar_t(wchar_t c)
{
	write(1, &c, 4);
}
