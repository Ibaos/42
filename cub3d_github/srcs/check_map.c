/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:51:06 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 14:16:13 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

bool	is_door(char c)
{
	return (c == 'c' || c == 'o');
}

static bool	is_neighbors_valid(char **map, size_t i, size_t j)
{
	return ((map[i - 1][j] == '0' || map[i - 1][j] == '1'
			|| is_door(map[i - 1][j]) || is_player(map[i - 1][j]))
		&& (map[i + 1][j] == '0' || map[i + 1][j] == '1'
			|| is_door(map[i + 1][j]) || is_player(map[i + 1][j]))
		&& (map[i][j - 1] == '0' || map[i][j - 1] == '1'
			|| is_door(map[i][j - 1]) || is_player(map[i][j - 1]))
		&& (map[i][j + 1] == '0' || map[i][j + 1] == '1'
			|| is_door(map[i][j + 1]) || is_player(map[i][j + 1])));
}

bool	check_map(char **map, size_t width, size_t height, int player_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width - 1)
		{
			if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '0'
				&& !is_player(map[i][j]) && !is_door(map[i][j]))
				return (print_error("Invalid character in map.\n", false));
			if ((map[i][j] == '0' || is_door(map[i][j]) || is_player(map[i][j]))
				&& ((i == 0 || i == height - 1 || j == 0
				|| j == width - 1) || !is_neighbors_valid(map, i, j)))
				return (print_error("Invalid border.\n", false));
			if (is_player(map[i][j]))
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (print_error("Invalid number of player.\n", false));
	return (true);
}
