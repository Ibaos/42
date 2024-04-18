/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_monster.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:44:00 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/08 13:44:03 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	isdead(t_window_info *w)
{
	if (w->map.monster.x == w->map.player_info.x
		&& w->map.monster.y == w->map.player_info.y)
	{
		write(STDERR_FILENO, "Game Over!\n", 11);
		free_window(w);
	}
}

void	moove_monster_right(t_window_info *w, t_map_info *m)
{
	if (m->elements[m->monster.y / m->pixels]
		[m->monster.x / m->pixels + 1] == '0')
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->empty_info.right, m->monster.x, m->monster.y);
		m->monster.x += m->pixels;
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->monster.right, m->monster.x, m->monster.y);
	}
	else
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->monster.left, m->monster.x, m->monster.y);
		m->monster.pattern = 1;
	}
}

void	moove_monster_left(t_window_info *w, t_map_info *m)
{
	if (m->elements[m->monster.y / m->pixels]
		[m->monster.x / m->pixels - 1] == '0')
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->empty_info.right, m->monster.x, m->monster.y);
		m->monster.x -= m->pixels;
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->monster.left, m->monster.x, m->monster.y);
	}
	else
	{
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			m->monster.right, m->monster.x, m->monster.y);
		m->monster.pattern = 0;
	}
}

void	moove_monster(t_window_info *w)
{
	isdead(w);
	if (w->map.monster.pattern == 0)
		moove_monster_right(w, &w->map);
	else
		moove_monster_left(w, &w->map);
	isdead(w);
}
