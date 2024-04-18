/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_accessibility.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:00:55 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 16:01:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_all_directions(t_map_info *map, char **map_dup, int x, int y)
{
	flood_map(map, map_dup, x + 1, y);
	flood_map(map, map_dup, x - 1, y);
	flood_map(map, map_dup, x, y + 1);
	flood_map(map, map_dup, x, y - 1);
}

void	flood_map(t_map_info *map, char **map_duplicate, int x, int y)
{
	if (map_duplicate[y][x] == '0')
	{
		map_duplicate[y][x] = 'F';
		flood_all_directions(map, map_duplicate, x, y);
	}
	if ((map_duplicate[y][x] == 'F') || (map_duplicate[y][x] == '1'))
		return ;
	if (map_duplicate[y][x] == 'P')
	{
		map_duplicate[y][x] = 'F';
		flood_all_directions(map, map_duplicate, x, y);
	}
	if (map_duplicate[y][x] == 'C')
	{
		map->collectible_flood++;
		map_duplicate[y][x] = 'F';
		flood_all_directions(map, map_duplicate, x, y);
	}
	if (map_duplicate[y][x] == 'E')
	{
		map->exit_flood++;
		map_duplicate[y][x] = 'F';
	}
}

char	**duplicate_map(t_map_info *map, size_t i)
{
	char	**dest;

	dest = malloc(sizeof(char *) * map->height);
	if (dest == NULL)
	{
		map->error = -10;
		free_map_elements(map->elements, map->height);
		return (error_messages(map->error), NULL);
	}
	open(map->name, O_RDONLY);
	while (i < map->height)
	{
		dest[i] = get_next_line(map->fd);
		if (dest[i] == NULL)
		{
			map->error = -10;
			free_map_elements(dest, i);
			free_map_elements(map->elements, map->height);
			return (error_messages(map->error), NULL);
		}
		i++;
	}
	close(map->fd);
	return (dest);
}

void	check_map_accessibility(t_map_info *map)
{
	char	**map_duplicate;

	map_duplicate = duplicate_map(map, 0);
	if (map_duplicate == NULL)
		return ;
	flood_map(map, map_duplicate, (map->player_info.x / map->pixels),
		map->player_info.y / map->pixels);
	free_map_elements(map_duplicate, map->height);
	if ((map->collectible_flood != map->nb_collectible)
		|| (map->exit_flood != map->nb_exit))
	{
		map->error = -7;
		free_map_elements(map->elements, map->height);
		error_messages(map->error);
		return ;
	}
}
