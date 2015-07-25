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

int	run_s_conversion_test(int *index, int tests_in_sequence)
{
	int		c;
	int		j;
	char	*str;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%s\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			str = gen_random_string(MAX_LEN_RANDOM_STR, 0);
			single_test_run("s test, s = %s\n", str, "str");
			ft_strdel(&str);
			j++;
			if (!(j % 5) && j != TESTS_PER_LINE && j != tests_in_sequence)
				printf(". ");
			c++;
		}
		(*index)++;
	}
	printf("\n");
	return (0);
}

int	run_c_conversion_test(int *index)
{
	int	c;
	int	j;

	c = 0;
	while (c < 128)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%c\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < 128)
		{
			single_test_run("c test, c = %c\n", &c, "char");
			j++;
			if (!(j % 5) && j != TESTS_PER_LINE)
				printf(". ");
			c++;
		}
		(*index)++;
	}
	printf("\n");
	return (0);
}

int	run_all_conversion_test(int *index)
{
	center_ui_str("Starting Conversion Tests", UI_SEPARATOR);
	run_c_conversion_test(index);
	run_s_conversion_test(index, 40);
	return (0);
}

int	run_single_string_test(int *index, int tests_in_sequence)
{
	char	*str;
	int		c;
	int		j;

	center_ui_str("Starting Simple String Tests", UI_SEPARATOR);

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  Single string :\t", *index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			str = gen_random_string(MAX_LEN_RANDOM_STR, 0);
			single_test_run(str, NULL, "none");
			ft_strdel(&str);
			j++;
			if (!(j % 5) && j != TESTS_PER_LINE && j!= tests_in_sequence)
				printf(". ");
			c++;
		}
		(*index)++;
	}
	printf("\n");
	return (0);
}
