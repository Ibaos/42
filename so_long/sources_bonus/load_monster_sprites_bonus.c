/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_monster_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:58:49 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/07 15:58:50 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_monster_images(t_window_info *w)
{
	if (w->map.monster.right)
		mlx_destroy_image(w->mlx_ptr, w->map.monster.right);
	if (w->map.monster.left)
		mlx_destroy_image(w->mlx_ptr, w->map.monster.left);
}

void	monster_loaded(t_window_info *w)
{
	if (!w->map.monster.right || !w->map.monster.left)
	{
		w->map.error = -11;
		error_messages(w->map.error);
	}
}

void	load_monster_sprites_128(t_window_info *w)
{
	w->map.monster.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/monster_right.xpm",
			&w->map.monster.width, &w->map.monster.height);
	w->map.monster.left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/monster_left.xpm",
			&w->map.monster.width, &w->map.monster.height);
}

void	load_monster_sprites_64_and_32(t_window_info *w)
{
	if (w->map.pixels == 64)
	{
		w->map.monster.right = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/64/monster_right.xpm",
				&w->map.monster.width, &w->map.monster.height);
		w->map.monster.left = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/64/monster_left.xpm",
				&w->map.monster.width, &w->map.monster.height);
	}
	else
	{
		w->map.monster.right = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/32/monster_right.xpm",
				&w->map.monster.width, &w->map.monster.height);
		w->map.monster.left = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/32/monster_left.xpm",
				&w->map.monster.width, &w->map.monster.height);
	}
}

void	load_monster_sprites(t_window_info *w)
{
	if (w->map.pixels == 192)
	{
		w->map.monster.right = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/192/monster_right.xpm", &w->map.monster.width,
				&w->map.monster.height);
		w->map.monster.left = mlx_xpm_file_to_image(w->mlx_ptr,
				"./sprites/192/monster_left.xpm", &w->map.monster.width,
				&w->map.monster.height);
	}
	else if (w->map.pixels == 128)
		load_monster_sprites_128(w);
	else if (w->map.pixels == 64 || w->map.pixels == 32)
		load_monster_sprites_64_and_32(w);
	monster_loaded(w);
	if (w->map.error < 0)
		free_window(w);
	w->map.monster.pattern = 0;
}
