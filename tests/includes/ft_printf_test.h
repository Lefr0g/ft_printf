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

#ifndef FT_PRINTF_TEST_H

# define FT_PRINTF_TEST_H

# include <stdio.h>
# include "ft_printf.h"
# include <fcntl.h>

# include <wchar.h>
# include <locale.h>

# define TERM_WIDTH 80
# define TESTS_PER_LINE 20
# define MAX_LEN_RANDOM_STR 1000
# define UI_SEPARATOR '-'

/*
 * main_test.c functions
*/
int		single_test_run(char *str, void *arg, char *type);

int		run_single_string_test(int *index, int tests_in_sequence);
int		run_all_conversion_test(int *index);
int		run_c_conversion_test(int *index);
int		run_s_conversion_test(int *index, int tests_in_sequence);

/*
 * gears.c functions
*/
int		reset_stdout(void);
int		capture_and_cmp(char *str, void *arg, char *type);
FILE	*hijack_stream(char *filename, FILE *stream);
int		compare(char *file1, char *file2);
char	*file_to_str(char *filename);
int		pass_and_print(int (*printfn)(const char * restrict, ...),
		char *str, void *arg, char *type);

/*
 * random_gens.c functions
*/
char	gen_random_char(int allow_spec);
char	*gen_random_string(int maxlen, int allow_spec);

/*
 * interface.c functions
*/
int		center_ui_str(char *str, char separator);

#endif