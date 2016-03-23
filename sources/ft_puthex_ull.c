/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:42:05 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:42:26 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_ull(unsigned long long int n, char *mode)
{
	if (n > 15)
	{
		ft_puthex_ull(n / 16, mode);
		ft_puthex_ull(n % 16, mode);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else if (!ft_strcmp(mode, "min"))
			ft_putchar((n - 10) + 'a');
		else if (!ft_strcmp(mode, "maj"))
			ft_putchar((n - 10) + 'A');
	}
}
