/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/

#include "ft_printf_test.h"

/*
 * Pseudo-random printable char generator
*/

char	gen_random_char(int allow_spec)
{
	char	c;

	c = 0;
	while (c < 32)
	{
		c = rand() % 128;
		if (!allow_spec && c == '%')
			c = '0';
	}
	return (c);
}


/*
 * Pseudo-random text string generator
*/
char	*gen_random_string(int maxlen, int allow_spec)
{
	int		len;
	char	*str;
	int		i;

	len = rand() % maxlen;
	str = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		str[i] = gen_random_char(allow_spec);
		if (allow_spec)
		{
			if (i == maxlen - 1 && str[i] == '%')
				str[i] = '0';
			if (str[i] == '%' && str[i] < maxlen - 1)
			{
				i++;
				str[i] = '%';
			}
		}
		i++;
	}
//	ft_putendl(str);
	return (str);
}
