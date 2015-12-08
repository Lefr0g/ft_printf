/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:32:29 by amulin            #+#    #+#             */
/*   Updated: 2015/12/08 20:04:52 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_test.h"

t_pft_list	*pft_lstnew(const char *format, void const *arg, size_t size, 
		const char *type)
{
	ft_putendl("check A");
	t_pft_list	*elem;
	elem = (t_pft_list*)malloc(sizeof(t_pft_list));
	if (!elem)
	{
		ft_putendl("ERROR : pft_lstnew() : list memory allocation fail");
		exit (1);
	}
	elem->index = 0;
	elem->seq_id = 0;
	elem->seq_title = ft_strnew(100);
	elem->sec_id = 0;
	elem->sec_title = ft_strnew(100);
	elem->format = ft_strdup(format);
	elem->arg = ft_memalloc(16);
	ft_memmove(elem->arg, arg, size);
//	(void)size;
//	copy_arg(elem->arg, arg, type);
	ft_putendl("check B");
	elem->type = ft_strdup(type);
	elem->refout = ft_strnew(1000);
	elem->testout = ft_strnew(1000);
	elem->matching = -1;
	elem->next = NULL;
	if (!elem->format || !elem->arg || !elem->type || !elem->refout
			|| !elem->testout || !elem->seq_title || !elem->sec_title)
	{
		ft_putendl("ERROR : pft_lstnew() : item memory allocation fail");
		exit (1);
	}
	return (elem);
}

void	pft_lstaddnext(t_pft_env *e)
{
	t_pft_list	*buf;
	t_pft_list	*new;

	buf = e->lst_current;
	new = pft_lstnew(e->buf_format, e->buf_arg, e->buf_size, e->buf_type);
	new->index = e->buf_index;
	new->seq_id = e->buf_seq_id;
	new->seq_title = e->buf_seq_title;
	new->sec_id = e->buf_sec_id;
	new->sec_title = e->buf_sec_title;

	buf->next = new;
	e->lst_current = new;
}

void	pft_lstprint(t_pft_list *list)
{
	t_pft_list	*buf;
	
	buf = list;
	while (buf)
	{
		printf("List elem index = "ANSI_COLOR_YELLOW"%d"ANSI_RESET", at address "
				ANSI_COLOR_YELLOW"%p"ANSI_RESET"\n", buf->index, buf);
		printf("_____________________________________________________INFO\n");
		printf("Section\t\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"' ("
				ANSI_COLOR_YELLOW"%d"ANSI_RESET")\n",
				buf->sec_title, buf->sec_id);
		printf("Sequence\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"' ("
				ANSI_COLOR_YELLOW"%d"ANSI_RESET")\n",
				buf->seq_title, buf->seq_id);
		printf("____________________________________________________INPUT\n");
		printf("Format string\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"'\n",
			   buf->format);
		if (buf->arg)
			printf("Argument\t= '"ANSI_COLOR_YELLOW"%lld"ANSI_RESET"'\n",
					*(long long*)buf->arg);
		else
			printf("Argument\t= '"ANSI_COLOR_RED"(null)"ANSI_RESET"'\n");
		printf("Type\t\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"'\n", buf->type);
		printf("___________________________________________________OUTPUT\n");
		printf("Reference\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"'\n",
				buf->refout);
		printf("Tested\t\t= '"ANSI_COLOR_YELLOW"%s"ANSI_RESET"'\n",
				buf->testout);
		printf("Status\t\t= "ANSI_COLOR_YELLOW"%hd"ANSI_RESET"\n\n\n",
				buf->matching);
		buf = buf->next;
	}
}
