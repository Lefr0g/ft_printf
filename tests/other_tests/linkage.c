/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:48:44 by amulin            #+#    #+#             */
/*   Updated: 2015/12/02 15:51:40 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This test only verifies if a ft_printf() internal function is accessible
// from the compiled library or not.

#include "ft_printf.h"

int	main(void)
{
	ft_putnbr_ull(4345);
	return (0);
}
