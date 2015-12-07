/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 14:39:02 by amulin            #+#    #+#             */
/*   Updated: 2015/12/07 18:45:18 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H

# define FT_PRINTF_TEST_H

# include <stdio.h>
# include "ft_printf.h"
# include <fcntl.h>

# include <limits.h>

# include <wchar.h>
# include <locale.h>

# define TERM_WIDTH 80
# define TESTS_PER_LINE 20
# define MAX_LEN_RANDOM_STR 1000
# define UI_SEPARATOR '-'

typedef struct		s_pft_list
{
	int				index;
	char			*input;
	void			*arg;
	char			*type;
	char			*refout;
	char			*testout;
	struct s_list	*next;
}					t_pft_list;

typedef struct		s_pft_env
{
	int				index;
	t_list			*lst_start;
}					t_pft_env;

/*
 * main_test.c functions
*/
int		single_test_run(char *str, void *arg, char *type);
int		run_all_tests(void);
void	init_test_env(t_pft_env *e);
void	clear_test_env(t_pft_env *e);

/*
 * NEW pft_list.c functions (NOT DONE YET)
*/
t_pft_list	*pft_lstnew(const char *input, void const *arg, const char *type);

/*
 * NEW test_functions.c functions (WIP)
*/
void	call_print(int (*printfn)(const char * restrict, ...),
		char *str, void *arg, char *type);
void	runtest_1_arg(char *str, void *arg, char *type, t_pft_env *e);


/*
 * test_sequences.c functions
*/
int		run_all_conversion_test(int *index);
int		run_single_string_test(int *index, int tests_in_sequence);
int		run_c_conversion_test(int *index);
int		run_s_conversion_test(int *index, int tests_in_sequence);
int		run_d_conversion_test(int *index, int tests_in_sequence);
int		run_u_conversion_test(int *index, int tests_in_sequence);
int		run_x_conversion_test(int *index, int tests_in_sequence);
int		run_X_conversion_test(int *index, int tests_in_sequence);
int		run_o_conversion_test(int *index, int tests_in_sequence);
int		run_p_conversion_test(int *index, int tests_in_sequence);

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
