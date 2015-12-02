/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/02 19:30:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_ll(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr_ll(-n);
	}
	else if (n > 9)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + '0');
}
