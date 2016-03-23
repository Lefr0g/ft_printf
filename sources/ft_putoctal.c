/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:34:32 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:53:25 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putoctal(unsigned long long n)
{
	if (n > 7)
	{
		ft_putoctal(n / 8);
		ft_putoctal(n % 8);
	}
	else
		ft_putchar(n + '0');
}
