/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 14:39:02 by amulin            #+#    #+#             */
/*   Updated: 2015/12/08 19:33:15 by amulin           ###   ########.fr       */
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
# define ANSI_COLOR_RED "\033[31m"
# define ANSI_COLOR_GREEN "\033[32m"
# define ANSI_COLOR_YELLOW "\033[33m"
# define ANSI_COLOR_BLUE "\033[34m"
# define ANSI_COLOR_MAGENTA "\033[35m"
# define ANSI_COLOR_CYAN "\033[36m"
# define ANSI_UNDERLINED "\033[4m"
# define ANSI_RESET "\033[0m"

typedef struct			s_pft_list
{
	int					index;
	int					seq_id;
	char				*seq_title;
	int					sec_id;
	char				*sec_title;
	char				*format;
	void				*arg;
	char				*type;
	char				*refout;
	char				*testout;
	short				matching;
	struct s_pft_list	*next;
}						t_pft_list;

typedef struct			s_pft_env
{
	int					index;
	t_pft_list			*lst_start;
	t_pft_list			*lst_current;
	int					buf_index;
	int					buf_seq_id;
	char				*buf_seq_title;
	int					buf_sec_id;
	char				*buf_sec_title;
	char				*buf_format;
	void				*buf_arg;
	size_t				buf_size;
	char				*buf_type;
	char				*buf_refout;
	char				*buf_testout;
	short				buf_matching;
}						t_pft_env;

/*
 * pft_main.c functions
*/
int		single_test_run(char *str, void *arg, char *type);
int		run_all_tests(void);

void	pft_init_env(t_pft_env *e);
void	pft_load(t_pft_env *e);
void	pft_clear_env(t_pft_env *e);

/*
 * NEW pft_list.c functions
*/
t_pft_list	*pft_lstnew(const char *input, void const *arg, size_t size, 
		const char *type);
void	pft_lstaddnext(t_pft_env *e);
void	pft_lstprint(t_pft_list *list);

/*
 * NEW test_functions.c functions (WIP)
*/
void	call_print(int (*printfn)(const char * restrict, ...),
		char *str, void *arg, char *type);
void	runtest_1_arg(char *str, void *arg, char *type, t_pft_env *e);
void	copy_arg(void *dst, const void *arg, const char *type);

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
 * pft_gears.c functions
*/
int		reset_stdout(void);
int		capture_and_cmp(char *str, void *arg, char *type);
FILE	*hijack_stream(char *filename, FILE *stream);
int		compare(char *file1, char *file2);
char	*file_to_str(char *filename);
int		pass_and_print(int (*printfn)(const char * restrict, ...),
		char *str, void *arg, char *type);

/*
 * pft_random_gens.c functions
*/
char	gen_random_char(int allow_spec);
char	*gen_random_string(int maxlen, int allow_spec);

/*
 * pft_interface.c functions
*/
int		center_ui_str(char *str, char separator);
char	*ansi_transform(char *str, char *ansi_code);

#endif
