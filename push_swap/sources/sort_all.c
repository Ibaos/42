/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:54:06 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/26 13:54:07 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_conditionnal_first(t_info *info)
{
	if (info->top <= info->num)
	{
		info->list_a = info->list_a->next;
		info->list_b = push_first(info->list_a, info->list_b, info);
		info->num++;
		info->first_push = 1;
	}
	else if (info->top <= (info->num + info->chunk))
	{
		info->list_a = info->list_a->next;
		info->list_b = push_first(info->list_a, info->list_b, info);
		info->num++;
		info->first_push = 1;
	}
	else
		rotate(info->list_a, 'a', info);
	info->list_a = list_get_first(info->list_a);
	info->list_b = list_get_first(info->list_b);
}

void	push_conditionnal(t_info *info)
{
	if (info->top <= info->num)
	{
		info->list_a = info->list_a->next;
		push(info->list_a, info->list_b, 'b', info);
		info->num++;
	}
	else if (info->top <= (info->num + info->chunk))
	{
		info->list_a = info->list_a->next;
		push(info->list_a, info->list_b, 'b', info);
		rotate(info->list_b, 'b', info);
		info->num++;
	}
	else
		rotate(info->list_a, 'a', info);
	info->list_a = list_get_first(info->list_a);
	info->list_b = list_get_first(info->list_b);
}

void	push_until_three(t_info *info)
{
	while (info->num <= info->rank_max)
	{
		info->list_a = list_get_first(info->list_a);
		while (info->list_a->rank > info->rank_max)
		{
			rotate(info->list_a, 'a', info);
			info->list_a = list_get_first(info->list_a);
		}
		info->top = info->list_a->rank;
		if (info->first_push == 1)
			push_conditionnal(info);
		else
			push_conditionnal_first(info);
		if (info->error == -1)
			return ;
	}
}

int	sort_three_remaining(t_info *info)
{
	sort_three(info, info->list_a->rank,
		info->list_a->next->rank, info->list_a->next->next->rank);
	if (info->error == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		list_get_first(info->list_b);
		free_list(info->list_b);
		return (1);
	}
	return (0);
}

void	sort_all(t_info *info)
{
	if (ft_issorted(info->list_a))
	{
		free(info->list_b);
		return ;
	}
	if (info->argc == 3)
	{
		sort_three(info, info->list_a->rank,
			info->list_a->next->rank, info->list_a->next->next->rank);
		if (info->error == -1)
			write(STDERR_FILENO, "Error\n", 6);
		free(info->list_b);
		return ;
	}
	push_until_three(info);
	if (info->error == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		list_get_first(info->list_b);
		free_list(info->list_b);
		return ;
	}
	if (sort_three_remaining(info))
		return ;
	push_back_to_a(info);
}
