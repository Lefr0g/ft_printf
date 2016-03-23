/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 19:13:21 by amulin            #+#    #+#             */
/*   Updated: 2016/03/23 19:36:46 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		my_process(long long int n, char *result, long long int i,
		unsigned int base)
{
	size_t			index;

	index = 0;
	if (n < 0)
	{
		result[index] = '-';
		index++;
		n = -n;
	}
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

static char		*my_exception(long long int limit)
{
	char			*result;

	result = ft_strnew(21);
	if (!result)
		return (NULL);
	if (limit == LONG_MAX)
		ft_strcpy(result, "9223372036854775807");
	else if (limit == LONG_MIN)
		ft_strcpy(result, "-9223372036854775806");
	return (result);
}

char			*ft_itoa_ll(long long int n, unsigned int base)
{
	size_t			j;
	long long int	i;
	long long int	buf;
	char			*result;

	i = 1;
	buf = n;
	j = 1;
	if (buf == LONG_MAX || buf == LONG_MIN)
		return (my_exception(buf));
	if (buf < 0)
		buf = -buf;
	while (buf > base - 1)
	{
		buf = buf / base;
		i = i * base;
		j++;
	}
	result = ft_strnew(j + 2);
	if (!result)
		return (NULL);
	my_process(n, result, i, base);
	return (result);
}
