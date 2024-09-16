/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:16:32 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/15 17:16:33 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "stdint.h"

t_list	*list_get_first(t_list *list)
{
	while (list->prev)
		list = list->prev;
	return (list);
}

void	rank_list(t_list *list, int argc)
{
	int		rank;
	int		lowest;
	t_list	*pos;
	t_list	*tmp;

	rank = 0;
	while (rank < argc)
	{
		tmp = list;
		lowest = INT32_MAX;
		while (tmp)
		{
			if (tmp->rank < 0 && tmp->content <= lowest)
			{
				lowest = tmp->content;
				pos = tmp;
			}
			tmp = tmp->next;
		}
		pos->rank = rank;
		rank++;
	}
}

bool	ft_issorted(t_list *list)
{
	int	lowest;

	lowest = -1;
	while (list)
	{
		if (lowest > list->rank)
			return (0);
		lowest = list->rank;
		list = list->next;
	}
	return (1);
}

bool	ft_isspace(char c)
{
	return ((c >= 7 && c <= 13) || c == ' ');
}

bool	ft_isnumber(char c)
{
	return (c >= '0' && c <= '9');
}
