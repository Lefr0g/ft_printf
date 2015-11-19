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
			single_test_run("%s", str, "str");
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
			single_test_run("%c", &c, "char");
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

int	run_d_conversion_test(int *index, int tests_in_sequence)
{
	int	c;
	int	j;
	int	val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%d\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 3)
				val = 0;
			if (c == tests_in_sequence - 2)
				val = INT_MIN;
			else if (c == tests_in_sequence - 1)
				val = INT_MAX;
			else
				val = rand();
			single_test_run("%d", &val, "int");
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

int	run_u_conversion_test(int *index, int tests_in_sequence)
{
	int	c;
	int	j;
	int	val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%u\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 3)
				val = 0;
			if (c == tests_in_sequence - 2)
				val = INT_MIN;
			else if (c == tests_in_sequence - 1)
				val = INT_MAX;
			else
				val = rand();
			single_test_run("%u", &val, "int");
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

int	run_x_conversion_test(int *index, int tests_in_sequence)
{
	int	c;
	int	j;
	int	val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%x\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 3)
				val = 0;
			if (c == tests_in_sequence - 2)
				val = INT_MIN;
			else if (c == tests_in_sequence - 1)
				val = INT_MAX;
			else
				val = rand();
			single_test_run("%x", &val, "int");
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

int	run_X_conversion_test(int *index, int tests_in_sequence)
{
	int	c;
	int	j;
	int	val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%X\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 3)
				val = 0;
			if (c == tests_in_sequence - 2)
				val = INT_MIN;
			else if (c == tests_in_sequence - 1)
				val = INT_MAX;
			else
				val = rand();
			single_test_run("%X", &val, "int");
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

int	run_o_conversion_test(int *index, int tests_in_sequence)
{
	int	c;
	int	j;
	int	val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%o\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 3)
				val = 0;
			if (c == tests_in_sequence - 2)
				val = INT_MIN;
			else if (c == tests_in_sequence - 1)
				val = INT_MAX;
			else
				val = rand();
			single_test_run("%o", &val, "int");
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

int	run_p_conversion_test(int *index, int tests_in_sequence)
{
	int		c;
	int		j;
	void	*val;

	c = 0;
	while (c < tests_in_sequence)
	{
		j = 0;
		printf("\n   \033[33m%.2d\033[0m -  \033[33m%%p\033[0m conversion :\t",
				*index);	
		while (j < TESTS_PER_LINE && c < tests_in_sequence)
		{
			if (c == tests_in_sequence - 2)
				val = NULL;
			else if (c == tests_in_sequence - 1)
				val = NULL;
			else
				val = (void*)malloc(sizeof(void));
			single_test_run("%p", &val, "int");
			free(val);
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

int	run_all_conversion_test(int *index)
{
	center_ui_str("Starting Conversion Tests", UI_SEPARATOR);
	run_c_conversion_test(index);
	run_s_conversion_test(index, 40);
	run_d_conversion_test(index, 40);
	run_u_conversion_test(index, 40);
	run_x_conversion_test(index, 40);
	run_X_conversion_test(index, 40);
	run_o_conversion_test(index, 40);
	run_p_conversion_test(index, 80);
	return (0);
}
