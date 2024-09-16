/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:07:41 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/04 15:07:42 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_info *info)
{
	if (!ft_issorted(info->list_a))
	{
		rotate(info->list_a, 'a', info);
		info->list_a = list_get_first(info->list_a);
	}
}

void	sort_three(t_info *info, int a, int b, int c)
{
	if (a < b && b > c && a < c)
	{
		reverse_rotate(info->list_a, 'a', info);
		info->list_a = list_get_first(info->list_a);
		swap(info->list_a, 'a', info);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(info->list_a, 'a', info);
	else if (a > b && b < c && a < c)
		swap(info->list_a, 'a', info);
	else if (a > b && b < c && a > c)
		rotate(info->list_a, 'a', info);
	else if (a > b && b > c && a > c)
	{
		rotate(info->list_a, 'a', info);
		info->list_a = list_get_first(info->list_a);
		swap(info->list_a, 'a', info);
	}
	else if (a > b && b < c && a < c)
		swap(info->list_a, 'a', info);
}
