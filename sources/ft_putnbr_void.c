/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/03 15:10:40 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_void(void *n, size_t size)
{
	long long	val;

	ft_bzero(&val, sizeof(val));
	ft_memcpy(&val, n, size);
	ft_putnbr_ll(val);
}
