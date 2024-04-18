/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:58:06 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:58:13 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map_elements(t_map_info *map)
{
	size_t	i;

	i = 0;
	map->elements = malloc(sizeof(char *) * map->height);
	if (map->elements == NULL)
	{
		map->error = -10;
		return (error_messages(map->error));
	}
	open(map->name, O_RDONLY);
	while (i < map->height)
	{
		map->elements[i] = get_next_line(map->fd);
		if (map->elements[i] == NULL)
		{
			map->error = -10;
			free_map_elements(map->elements, i);
			return (error_messages(map->error));
		}
		i++;
	}
	close(map->fd);
	check_walls(map, 0);
	if (map->error < 0)
		free_map_elements(map->elements, map->height);
}

void	check_walls_next(t_map_info *map, size_t i, size_t width, size_t height)
{
	while (i <= height)
	{
		if ((map->elements[i][0] != '1') || (map->elements[i][width] != '1'))
		{
			map->error = -4;
			return (error_messages(map->error));
		}
		i++;
	}
}

void	check_walls(t_map_info *map, size_t i)
{
	size_t	width;
	size_t	height;

	if (map->width == 0 || map->height == 0)
	{
		map->error = -10;
		return (error_messages(map->error));
	}
	width = map->width - 1;
	height = map->height - 1;
	while (i <= width)
	{
		if ((map->elements[0][i] != '1') || (map->elements[height][i] != '1'))
		{
			map->error = -4;
			return (error_messages(map->error));
		}
		i++;
	}
	i = 0;
	check_walls_next(map, i, width, height);
}
