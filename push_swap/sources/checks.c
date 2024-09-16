/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:15:07 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/15 17:15:08 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_minus(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j + 1] && argv[i][j] >= '0'
				&& argv[i][j] <= '9' && argv[i][j + 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	check_atoi(char **argv, int splitted)
{
	int	i;

	i = 1 - splitted;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == 0)
			if (argv[i][0] != '0')
				return (1);
		i++;
	}
	return (0);
}

bool	check_number(char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (!(ft_isnumber(c)) && c != '-' && !(ft_isspace(c)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

bool	check_duplicate(t_list *list_a)
{
	t_list	*i;
	t_list	*j;

	i = list_a;
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
