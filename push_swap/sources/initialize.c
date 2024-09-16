/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:17:48 by bhumeau           #+#    #+#             */
/*   Updated: 2024/02/15 17:17:50 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

char	*replace_not_space(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) && str[i] != ' ')
			str[i] = ' ';
		i++;
	}
	result = malloc(sizeof(char *) * i + 1);
	if (result == NULL)
		return (NULL);
	while (i >= 0)
	{
		result[i] = str[i];
		i--;
	}
	return (result);
}

t_list	*initialize_list_split(t_info *info, char **argv)
{
	t_list	*list;
	char	**result;
	char	*tmp;

	info->splitted = 1;
	tmp = replace_not_space(argv[1]);
	if (tmp == NULL)
		return (NULL);
	result = ft_split(tmp, ' ');
	if (result[0] == NULL)
	{
		free(result);
		free(tmp);
		return (NULL);
	}
	info->argc = count_argc(result);
	list = initialize_list(info, result, 0);
	free(tmp);
	free_split(result, info->argc);
	return (list);
}

t_list	*initialize_list(t_info *info, char **argv, int i)
{
	t_list	*tmp;
	t_list	*list;

	i = 2 - info->splitted;
	if (check_atoi(argv, info->splitted) == 1)
		return (NULL);
	list = ft_lstnew(ft_atoi(argv[1 - info->splitted]), NULL);
	if (list == NULL)
		return (NULL);
	tmp = list;
	while (i < info->argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i]), tmp);
		if (tmp == NULL)
		{
			free_list(list);
			return (NULL);
		}
		ft_lstadd_back(&list, tmp);
		i++;
	}
	return (list);
}
