/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:29:09 by amulin            #+#    #+#             */
/*   Updated: 2015/12/07 17:10:02 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

void	runtest_1_arg(char *str, void *arg, char *type, t_env *e)
{
//	ToDo : redirect stram to char*. Not sure if can be done directly in one step.
//			Edit : will be done y capturing output to a file, then reading from
//			this file via gnl.


	if (ft_strcmp(type, "signed char"))
	{
//		Redirect upcoming printf output to ref.txt : OK
		if (!hijack_stream("ref.txt", stdout))
			return (-1);

//		Call printf : TODO
		call_print(&printf, str, arg, type);
		
//		Redirect upcoming ft_printf output to dummy.txt : OK
		if (!hijack_stream("dummy.txt", stdout))
			return (-1);

//		Call ft_printf : TODO
		call_print(&ft_printf, str, arg, type);

//		Reset output stream to stdout : OK
		reset_stdout();

//		Copy input string to e->list->input : TODO
//		Copy input arg to e->list->arg : TODO
//		Copy input type to e->list->type : TODO

//		Copy output from ref.txt to e->list->refout : TODO
//		Copy output from dummy.txt to e->list->testout : TODO
	}
}
