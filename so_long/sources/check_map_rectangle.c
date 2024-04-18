/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:57:03 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:57:12 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	strlenmap(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	check_map_rectangle(t_map_info *map, char *line)
{
	size_t	last_line_width;

	open(map->name, O_RDONLY);
	while (line != NULL)
	{
		last_line_width = map->width;
		line = get_next_line(map->fd);
		if (line != NULL)
			map->width = strlenmap(line);
		if (last_line_width != map->width && last_line_width != 0)
			map->error = -3;
		map->height++;
		free(line);
	}
	map->height--;
	close(map->fd);
	if (map->error < 0)
		return (error_messages(map->error));
	if ((map->width > 20) || (map->height > 10))
		map->pixels = 128;
	if ((map->width > 30) || (map->height > 16))
		map->pixels = 64;
	if ((map->width > 60) || (map->height > 32))
		map->pixels = 32;
}
