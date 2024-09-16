/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap->c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42->fr>                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:53:30 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/12 10:53:35 by bhumeau          ###   ########->fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_chunk_and_rank_max(t_info *info)
{
	info->chunk = 0.000000053 * info->argc * info->argc
		+ 0.03 * info->argc + 14.5;
	info->rank_max = info->argc - 4;
}

bool	check_errors(char **argv, t_info *info)
{
	if (check_duplicate(info->list_a) || check_number(argv)
		|| check_minus(argv))
	{
		free_list(info->list_a);
		return (1);
	}
	return (0);
}

bool	check_errors_and_initialize_list(t_info *info, char **argv)
{
	if (info->argc == 2)
	{
		if (argv[1][0] == '\0')
			return (1);
		info->list_a = initialize_list_split(info, argv);
		if (info->list_a == NULL)
			return (1);
	}
	else
	{
		info->list_a = initialize_list(info, argv, 0);
		if (info->list_a == NULL)
			return (1);
		info->argc--;
	}
	return (check_errors(argv, info));
}

void	sorting_algorythm(t_info *info)
{
	initialize_chunk_and_rank_max(info);
	if (info->argc == 2)
	{
		sort_two(info);
		if (info->error == -1)
			write(STDERR_FILENO, "Error\n", 6);
		free_list(info->list_a);
		free(info->list_b);
		return ;
	}
	sort_all(info);
	info->list_a = list_get_first(info->list_a);
	free_list(info->list_a);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (0);
	ft_memset(&info, 0, sizeof(info));
	info.list_b = ft_lstnew(0, NULL);
	if (info.list_b == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	info.argc = argc;
	if (check_errors_and_initialize_list(&info, argv))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free(info.list_b);
		return (1);
	}
	rank_list(info.list_a, info.argc);
	sorting_algorythm(&info);
	return (0);
}
