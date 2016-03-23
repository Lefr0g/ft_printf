/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:24 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:50:10 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_ull(unsigned long long int n)
{
	if (n > 9)
	{
		ft_putnbr_ull(n / 10);
		ft_putnbr_ull(n % 10);
	}
	else
		ft_putchar(n + '0');
}
