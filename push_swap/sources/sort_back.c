/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:59:47 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/26 17:59:49 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_next_rank(t_info *info)
{
	info->list_b = list_get_first(info->list_b);
	info->next_rank = 0;
	while (info->list_a->rank != (info->list_b->rank + 1))
	{
		info->next_rank++;
		info->list_b = info->list_b->next;
	}
	info->list_b = list_get_first(info->list_b);
	return (info->next_rank);
}

void	push_element_to_a(t_info *info)
{
	info->list_a = list_get_first(info->list_a);
	info->list_b = list_get_first(info->list_b);
	if (find_next_rank(info) <= (info->num / 2))
	{
		while (info->list_a->rank != (info->list_b->rank + 1))
		{
			rotate(info->list_b, 'b', info);
			info->list_b = list_get_first(info->list_b);
		}
	}
	else
	{
		while (info->list_a->rank != (info->list_b->rank + 1))
		{
			reverse_rotate(info->list_b, 'b', info);
			info->list_b = list_get_first(info->list_b);
		}
	}
	if (info->list_b->next)
		info->list_b = info->list_b->next;
	push(info->list_b, info->list_a, 'a', info);
	info->num--;
}

void	push_back_to_a(t_info *info)
{
	while (info->num > 0)
	{
		push_element_to_a(info);
		if (info->error == -1)
		{
			list_get_first(info->list_a);
			list_get_first(info->list_b);
			write(STDERR_FILENO, "Error\n", 6);
			if (info->list_a->rank != info->list_b->rank && info->num != 0)
			{
				free_list(info->list_b);
				return ;
			}
		}
	}
}
