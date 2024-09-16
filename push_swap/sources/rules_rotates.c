/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:11:59 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/15 17:12:00 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list *list, char c, t_info *info)
{
	t_list	*l_last;
	t_list	*l_before;

	l_last = ft_lstlast(list);
	list = list_get_first(list);
	l_before = l_last->prev;
	l_last->next = list;
	list->prev = l_last;
	l_last->prev = NULL;
	l_before->next = NULL;
	if (c == 'a')
		if (write(STDOUT_FILENO, "rra\n", 4) == -1)
			info->error = -1;
	if (c == 'b')
		if (write(STDOUT_FILENO, "rrb\n", 4) == -1)
			info->error = -1;
}

void	reverse_rotate_all(t_list *list, t_list *list_bis, t_info *info)
{
	reverse_rotate(list, 0, info);
	reverse_rotate(list_bis, 0, info);
	if (write(STDOUT_FILENO, "rrr\n", 4) == -1)
		info->error = -1;
}

void	rotate(t_list *list, char c, t_info *info)
{
	t_list	*l_last;
	t_list	*l_after;

	list = list_get_first(list);
	l_after = list->next;
	l_last = ft_lstlast(list);
	l_last->next = list;
	list->prev = l_last;
	list->next = NULL;
	l_after->prev = NULL;
	if (c == 'a')
		if (write(STDOUT_FILENO, "ra\n", 3) == -1)
			info->error = -1;
	if (c == 'b')
		if (write(STDOUT_FILENO, "rb\n", 3) == -1)
			info->error = -1;
}

void	rotate_all(t_list *list, t_list *list_bis, t_info *info)
{
	rotate(list, 0, info);
	rotate(list_bis, 0, info);
	if (write(STDOUT_FILENO, "rr\n", 4) == -1)
		info->error = -1;
}
