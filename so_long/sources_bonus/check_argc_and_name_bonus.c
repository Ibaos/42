/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_and_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:56:04 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:56:12 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_extension(t_map_info *map)
{
	int	i;

	i = ft_strlen(map->name);
	if (map->name[i] != '\0' || map->name[i - 1] != 'r'
		|| map->name[i - 2] != 'e' || map->name[i - 3] != 'b'
		|| map->name[i - 4] != '.')
	{
		map->error = -15;
		error_messages(map->error);
	}
}

void	check_argc_and_name(t_map_info *map)
{
	char	str[1];

	str[0] = '\0';
	if (map->argc != 2)
	{
		map->error = -1;
		return (error_messages(map->error));
	}
	map->fd = open(map->name, O_RDONLY);
	if (map->fd == -1)
	{
		map->error = -2;
		return (error_messages(map->error));
	}
	read(map->fd, str, 1);
	close(map->fd);
	if (str[0] != '1')
	{
		map->error = -6;
		return (error_messages(map->error));
	}
	check_map_extension(map);
}
