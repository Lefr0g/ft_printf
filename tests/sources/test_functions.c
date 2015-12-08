/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:29:09 by amulin            #+#    #+#             */
/*   Updated: 2015/12/08 12:15:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

void	call_print(int (*printfn)(const char * restrict, ...), char *str,
		void *arg, char *type)
{
	if (!str)
	{
		ft_putendl("ERROR : call_print() : no format string input");
		exit(1);
	}
	if (arg && !ft_strcmp(type, "none") && !arg)
		printfn(str);
	else if (arg && !ft_strcmp(type, "signed char"))
		printfn(str, *(signed char*)arg);
	else if (arg && !ft_strcmp(type, "short"))
		printfn(str, *(short*)arg);
	else if (arg && !ft_strcmp(type, "int"))
		printfn(str, *(int*)arg);
	else if (arg && !ft_strcmp(type, "long"))
		printfn(str, *(long*)arg);
	else if (arg && !ft_strcmp(type, "long long"))
		printfn(str, *(long long*)arg);
	else if (arg && !ft_strcmp(type, "intmax_t"))
		printfn(str, *(intmax_t*)arg);
	else if (arg && !ft_strcmp(type, "unsigned char"))
		printfn(str, *(unsigned char*)arg);
	else if (arg && !ft_strcmp(type, "unsigned short"))
		printfn(str, *(unsigned short*)arg);
	else if (arg && !ft_strcmp(type, "unsigned int"))
		printfn(str, *(unsigned int*)arg);
	else if (arg && !ft_strcmp(type, "unsigned long"))
		printfn(str, *(unsigned long*)arg);
	else if (arg && !ft_strcmp(type, "unsigned long long"))
		printfn(str, *(unsigned long long*)arg);
	else if (arg && !ft_strcmp(type, "uintmax_t"))
		printfn(str, *(uintmax_t*)arg);
	else if (arg && !ft_strcmp(type, "size_t"))
		printfn(str, *(size_t*)arg);
	else if (arg && !ft_strcmp(type, "wint_t"))
		printfn(str, *(wint_t*)arg);
	else if (arg && !ft_strcmp(type, "wchar_t*"))
		printfn(str, (wchar_t*)arg);
	else if (arg && !ft_strcmp(type, "char*"))
		printfn(str, (char*)arg);
	else
	{
		ft_putendl("ERROR : call_print() : unknown argument type");
		exit(1);
	}
}

void	runtest_1_arg(char *str, void *arg, char *type, t_pft_env *e)
{
//	ToDo : redirect stram to char*. Not sure if can be done directly in one step.
//			Edit : will be done by capturing output to a file, then reading from
//			this file via gnl().


	if (ft_strcmp(type, "signed char"))
	{
//		Redirect upcoming printf output to ref.txt : OK
		if (!hijack_stream("ref.txt", stdout))
			return (-1);

//		Call printf : test needed
		call_print(&printf, str, arg, type);
		
//		Redirect upcoming ft_printf output to dummy.txt : OK
		if (!hijack_stream("dummy.txt", stdout))
			return (-1);

//		Call ft_printf : test needed
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
