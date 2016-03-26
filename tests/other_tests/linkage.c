/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:48:44 by amulin            #+#    #+#             */
/*   Updated: 2016/03/26 18:01:45 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This test only verifies if a ft_printf() internal function is accessible
// from the compiled library or not.

#include "ft_printf.h"
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	wchar_t	*wstr = L"er我是ty一只猫。er5";

	ft_putnbr_ull(4345);
	ft_printf("\n%d\n", 4345);
	ft_printf("%S\n", wstr);
	return (0);
}
