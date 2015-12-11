/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_process(long long int n, char *result, int i,
		unsigned int base)
{
	size_t	index;

	index = 0;
//	if (n < 0)
//	{
//		result[index] = '-';
//		index++;
//		n = -n;
//	}
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
/*
char		*my_exception(void)
{
	char	*result;

	result = ft_strnew(12);
	if (!result)
		return (NULL);
	ft_strcpy(result, "-2147483648");
	return (result);
}
*/
char		*ft_itoa_ll(long long int n, unsigned int base)
{
	size_t						j;
	long long int				i;
	long long int				buf;
	char						*result;

	i = 1;
	buf = n;
	j = 1;
//	if (buf == -2147483648LL)
//		return (my_exception());
//	if (buf < 0)
//		buf = -buf;
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
