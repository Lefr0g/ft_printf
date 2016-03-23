/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:56:29 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:58:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Compares 2 ints, returns the biggest
*/

int	ft_getmax(int a, int b)
{
	if (a <= b)
		return (b);
	return (a);
}
