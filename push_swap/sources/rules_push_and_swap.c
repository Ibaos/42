/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_and_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:13:04 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/15 17:13:05 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*push_first(t_list *l_src, t_list *l_dest, t_info *info)
{
	l_src->prev->next = l_dest->next;
	l_dest->next = l_src->prev;
	l_src->prev = NULL;
	l_dest->next->prev = l_dest;
	l_dest = l_dest->next;
	free(l_dest->prev);
	l_dest->prev = NULL;
	if (write(STDOUT_FILENO, "pb\n", 3) == -1)
		info->error = -1;
	return (l_dest);
}

t_list	*push(t_list *l_src, t_list *l_dest, char c, t_info *info)
{
	t_list	*save;

	if (c == 'a')
		if (write(STDOUT_FILENO, "pa\n", 3) == -1)
			info->error = -1;
	if (c == 'b')
		if (write(STDOUT_FILENO, "pb\n", 3) == -1)
			info->error = -1;
	save = NULL;
	if (l_src->next)
		save = l_src->next;
	if (l_src->next == NULL && l_src->prev == NULL)
	{
		l_dest->prev = l_src;
		l_src->next = l_dest;
		return (save);
	}
	l_src->prev->next = l_dest;
	l_dest->prev = l_src->prev;
	l_src->prev = NULL;
	return (save);
}

void	swap(t_list *list, char c, t_info *info)
{
	t_list	*l_after;

	l_after = list->next;
	l_after->next->prev = list;
	list->prev = list->next;
	list->next = l_after->next;
	l_after->prev = NULL;
	l_after->next = list;
	if (c == 'a')
		if (write(STDOUT_FILENO, "sa\n", 3) == -1)
			info->error = -1;
	if (c == 'b')
		if (write(STDOUT_FILENO, "sb\n", 3) == -1)
			info->error = -1;
}

void	swap_all(t_list *list, t_list *list_bis, t_info *info)
{
	swap(list, 0, info);
	swap(list_bis, 0, info);
	if (write(STDOUT_FILENO, "ss\n", 4) == -1)
		info->error = -1;
}
