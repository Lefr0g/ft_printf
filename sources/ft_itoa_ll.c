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
	char	*result;

	result = ft_strnew(21);
	if (!result)
		return (NULL);
	if (limit == LONG_MAX)
		ft_strcpy(result, "9223372036854775807");
	else
		ft_strcpy(result, "-9223372036854775806");
	return (result);
}

char		*ft_itoa_ll(long long int n, unsigned int base)
{
	size_t						j;
	long long int				i;
	long long int				buf;
	char						*result;

	i = 1;
	buf = n;
	j = 1;
	if (buf == LONG_MAX || buf == LONG_MIN)
		return (my_exception(buf));
	if (buf < 0)
	{
		buf = -buf;
		j++;
	}
	while (buf > base - 1)
	{
		buf = buf / base;
		i = i * base;
		j++;
	}
//	printf("\nft_itoa_ll() is allocating a %d wide table\n", (int)j + 1);
//	ft_putchar('\n');
//	ft_print_memory(&i, sizeof(long long));
//	ft_putchar('\n');
	result = ft_strnew(j + 1);
	if (!result)
		return (NULL);

//	TODO
//	Regler le probleme de i pour (par exemple) n == LONG_MIN + 2


	my_process(n, result, i, base);
	return (result);
}
