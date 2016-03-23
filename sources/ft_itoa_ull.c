/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:04:03 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:04:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_process(unsigned long long n, char *result, unsigned long long i,
		unsigned int base)
{
	size_t	index;

	index = 0;
	while (i > 0)
	{
		if (base == 16 && (n / i) > 9)
			result[index] = (n / i) - 10 + 'A';
		else
			result[index] = (n / i) + '0';
		n = n % i;
		i = i / base;
		index++;
	}
	result[index] = '\0';
}

char		*ft_itoa_ull(unsigned long long int n, unsigned int base)
{
	size_t							j;
	unsigned long long				i;
	unsigned long long				buf;
	char							*result;

	i = 1;
	buf = n;
	j = 1;
	while (buf > base - 1)
	{
		buf = buf / base;
		i = i * base;
		j++;
	}
	result = ft_strnew(j + 1);
	if (!result)
		return (NULL);
	my_process(n, result, i, base);
	return (result);
}
