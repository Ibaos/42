/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:00:05 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 16:00:13 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_entities_number(t_map_info *map)
{
	if ((map->nb_player != 1) || (map->nb_collectible < 1)
		|| (map->nb_exit != 1))
		map->error = -5;
	if (map->error < 0)
	{
		free_map_elements(map->elements, map->height);
		error_messages(map->error);
	}
}

void	check_map_entities(t_map_info *map, size_t i, size_t j)
{
	while (i < map->height - 1)
	{
		j = 0;
		while (j++ < map->width - 1)
		{
			if (map->elements[i][j] == 'P')
			{
				map->player_info.x = j * map->pixels;
				map->player_info.y = i * map->pixels;
				map->nb_player++;
			}
			else if (map->elements[i][j] == 'C')
				map->nb_collectible++;
			else if (map->elements[i][j] == 'E')
			{
				map->nb_exit++;
				map->exit_info.x = j * map->pixels;
				map->exit_info.y = i * map->pixels;
			}
			else if (map->elements[i][j] != '1' && map->elements[i][j] != '0')
				map->error = -9;
		}
		i++;
	}
	check_entities_number(map);
}
