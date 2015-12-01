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
 *	TO DO:
 *
 *	The run_x_conversion_test() function must be modified in order to allow to
 *	specify the string used by the printf function call as a parameter of
 *	this function.
 *	This will allow running the tests for flags, length, precision etc... using
 *	the same function.
 *
 *
*/



int	single_test_run(char *str, void *arg, char *type)
{
	int		res;
	int		i;
	wchar_t	ok;
	wchar_t	ko;
/*
 * Tick boxes
 * ok = L'\x2611';
 * ko = L'\x2612';
*/
//	ok = L'\x1409';

/*
 * Smileys
 * 	ok = L'\x1f619';
 * 	ko = L'\x1f628';
*/

/*
 *Trefle et bang
 * ok = L'\x1f340';
 * ko = L'\x1f4a5';
*/

//	Check mark & ballot (add / remove 1 to little end for bold / light version)
	ok = L'\x2714';
	ko = L'\x2718';

	i = 0;
	if ((res = capture_and_cmp(str, arg, type)) < 0)
	{
		reset_stdout();
		ft_putstr("<< ERROR >> main() : error in capture_and_cmp(). Aborting\n");
		exit(1);
	}
	else
	{
		reset_stdout();
		if (!res)
			printf("\033[32m%C \033[0m", ok);
		else
			printf("\033[31m%C \033[0m", ko);
		i++;
	}
	return (0);
}

int	run_all_tests(void)
{
	int					index;
	
	index = 0;

	run_single_string_test(&index, 20);
	
	run_all_conversion_test(&index);

	center_ui_str("End of Tests", UI_SEPARATOR);
	printf("\n");

	return (0);
}

int	main(void)
{
	setlocale(LC_ALL, "");
	run_all_tests();
	return (0);
}
