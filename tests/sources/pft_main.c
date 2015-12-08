/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:40:21 by amulin            #+#    #+#             */
/*   Updated: 2015/12/08 19:44:05 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
//	run_x_conversion_test(&index, 1);

	run_all_conversion_test(&index);

	center_ui_str("End of Tests", UI_SEPARATOR);
	printf("\n");

	return (0);
}

int	main(void)
{
//	setlocale(LC_ALL, "");

	t_pft_env	e;

	char	*tbd;

	tbd = ft_strnew(1000);
	
	pft_init_env(&e);
	pft_load(&e);

	printf("This text in normal color\n");
	printf("%s", ansi_transform("This text is underlined\n", ANSI_UNDERLINED));
	printf("%s", ansi_transform("This text in yellow\n", ANSI_COLOR_YELLOW));
	printf("%s", ansi_transform("This text in red\n", ANSI_COLOR_RED));
	printf("%s", ansi_transform("This text in green\n", ANSI_COLOR_GREEN));
	printf("%s", ansi_transform("This text in blue\n", ANSI_COLOR_BLUE));
	printf("%s", ansi_transform("This text in cyan\n", ANSI_COLOR_CYAN));
	printf("%s", ansi_transform("This text in magenta\n", ANSI_COLOR_MAGENTA));

	ft_strcpy(tbd, ansi_transform("%s ", ANSI_COLOR_RED));
	ft_strcat(tbd, ansi_transform("gege", ANSI_UNDERLINED));
	ft_putendl(tbd);
//	ft_putendl(e.buf_sec_title);
//	ft_putendl(e.buf_seq_title);
	ft_putendl(e.lst_current->sec_title);
	ft_putendl("Dislaying the list below:\n\n");
	pft_lstprint(e.lst_current);
	pft_lstprint(e.lst_start);

//run_all_tests();

//NEW	pft_print_results(&e);
//NEW	pft_summary_prompt(%e);
//NEW	pft_clear_env(&e);
	return (0);
}

void	pft_init_env(t_pft_env *e)
{
	setlocale(LC_ALL, "");
	e->index = 0;
	e->lst_start = (t_pft_list*)malloc(sizeof(t_pft_list));
	e->lst_current = e->lst_start;
	e->buf_index = -1;
	e->buf_seq_id = -1;
	e->buf_seq_title = ft_strnew(100);
	e->buf_sec_id = -1;
	e->buf_sec_title = ft_strnew(100);
	e->buf_format = NULL;
	e->buf_arg = NULL;
	e->buf_type = NULL;
	e->buf_refout = NULL;
	e->buf_testout = NULL;
	e->buf_matching = -1;


/*
	e->lst_start = (t_list*)malloc(sizeof(t_pft_list));
	if (!e->lst_start)
	{
		ft_putendl("ERROR : init_test_env() failed. Aborting");
		exit(1);
	}
*/
}

void	pft_load_section_0(t_pft_env *e)
{
	ft_putendl("Check 1");
	e->lst_current = pft_lstnew("%d", 0, sizeof(int), "int");
	ft_putendl("Check 2");
	e->lst_current->index = 0;
	e->buf_sec_id = 0;
	ft_strcpy(e->lst_current->sec_title, "%d conversion");
	e->buf_seq_id = 0;
	ft_strcpy(e->lst_current->seq_title, "Vanilla");
}

void	pft_load(t_pft_env *e)
{
	pft_load_section_0(e);
}

void	clear_test_env(t_pft_env *e)
{
	free(e->lst_start);
}
