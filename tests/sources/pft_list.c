/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:32:29 by amulin            #+#    #+#             */
/*   Updated: 2015/12/07 18:44:50 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_pft_list	*pft_lstnew(const char *input, void const *arg, const char *type)
{
	t_pft_list	*elem;
	elem = (t_pft_list*)malloc(sizeof(t_pft_list));
	if (!elem)
	{
		ft_putendl("ERROR : pft_lstnew() : list memory allocation fail");
		exit (1);
	}
	elem->index = 0;
	elem->input = ft_strnew(1000);
	elem->arg = ft_memalloc(16);
	elem->type = ft_strnew(100);
	elem->refout = ft_strnew(1000);
	elem->testout = ft_strnew(1000);
	elem->next = NULL;
	if (!elem->input || !elem->arg || !elem->type || !elem->refout
			|| !elem->testout)
	{
		ft_putendl("ERROR : pft_lstnew() : item memory allocation fail");
		exit (1);
	}
}
