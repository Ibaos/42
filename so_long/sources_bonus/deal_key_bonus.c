/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:07:00 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 16:07:08 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_in_screen(t_window_info *w)
{
	char	*steps;

	steps = ft_itoa(w->map.steps);
	if (!steps)
	{
		w->map.error = -10;
		error_messages(w->map.error);
		free_window(w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->map.wall_info.right,
		0, 0);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->map.wall_info.right,
		1 * w->map.pixels, 0 * w->map.pixels);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->map.wall_info.right,
		2 * w->map.pixels, 0 * w->map.pixels);
	mlx_string_put(w->mlx_ptr, w->win_ptr, 10, 20, 0xFFFFFF, "Move:");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 46, 20, 0xFFFFFF, steps);
	free(steps);
}

void	collectible_event(t_window_info *w, t_map_info *map)
{
	if (map->nb_collectible != 0
		&& map->nb_collectible <= (map->collectible_flood / 2))
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, map->exit_info.right,
			map->exit_info.x, map->exit_info.y);
	}
	if (map->nb_collectible == 0)
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, map->exit_info.up,
			map->exit_info.x, map->exit_info.y);
		map->elements[map->exit_info.y / map->pixels]
		[map->exit_info.x / map->pixels] = 'U';
	}
	if (map->elements[map->player_info.y / map->pixels]
		[map->player_info.x / map->pixels] == 'U' && map->player_info.x
		== map->exit_info.x && map->player_info.y == map->exit_info.y)
		free_window(w);
}

int	deal_key(int key, t_window_info *w)
{
	if (key == XK_Escape)
		free_window(w);
	if (key == XK_d)
		moove_right(w, &w->map.player_info);
	if (key == XK_a)
		moove_left(w, &w->map.player_info);
	if (key == XK_w)
		moove_up(w, &w->map.player_info);
	if (key == XK_s)
		moove_down(w, &w->map.player_info);
	collectible_event(w, &w->map);
	count_in_screen(w);
	if (w->map.monster.x && w->map.monster.y)
		moove_monster(w);
	return (0);
}
