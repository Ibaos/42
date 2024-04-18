/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:11 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:39:12 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_sprite_128(t_window_info *w, t_sprites *p)
{
	p->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/knight_right.xpm", &p->width, &p->height);
	p->left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/knight_left.xpm", &p->width, &p->height);
	p->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/knight_up.xpm", &p->width, &p->height);
	p->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/knight_down.xpm", &p->width, &p->height);
}

void	load_sprites_128(t_window_info *w, t_map_info *m, t_sprites *e)
{
	load_player_sprite_128(w, &w->map.player_info);
	m->wall_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/tree.xpm", &m->wall_info.width,
			&m->wall_info.height);
	m->empty_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/grass.xpm", &m->empty_info.width,
			&m->empty_info.height);
	m->object_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/wood.xpm", &m->object_info.width,
			&m->object_info.height);
	m->object_info.left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/rocks.xpm", &m->object_info.width,
			&m->object_info.height);
	e->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/tower_down.xpm", &e->width, &e->height);
	e->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/tower_right.xpm", &e->width, &e->height);
	e->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/128/tower_up.xpm", &e->width, &e->height);
}

void	load_player_sprite_192(t_window_info *w, t_sprites *p)
{
	p->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/knight_right.xpm", &p->width, &p->height);
	p->left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/knight_left.xpm", &p->width, &p->height);
	p->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/knight_up.xpm", &p->width, &p->height);
	p->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/knight_down.xpm", &p->width, &p->height);
}

void	load_sprites_192(t_window_info *w, t_map_info *m, t_sprites *e)
{
	load_player_sprite_192(w, &w->map.player_info);
	m->wall_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/tree.xpm", &m->wall_info.width,
			&m->wall_info.height);
	m->empty_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/grass.xpm", &m->empty_info.width,
			&m->empty_info.height);
	m->object_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/wood.xpm", &m->object_info.width,
			&m->object_info.height);
	m->object_info.left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/rocks.xpm", &m->object_info.width,
			&m->object_info.height);
	e->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/tower_down.xpm", &e->width, &e->height);
	e->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/tower_right.xpm", &e->width, &e->height);
	e->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/192/tower_up.xpm", &e->width, &e->height);
}

void	load_sprites(t_window_info *w)
{
	if (w->map.pixels == 192)
		load_sprites_192(w, &w->map, &w->map.exit_info);
	else if (w->map.pixels == 128)
		load_sprites_128(w, &w->map, &w->map.exit_info);
	else if (w->map.pixels == 64)
		load_sprites_64(w, &w->map, &w->map.exit_info);
	else
		load_sprites_32(w, &w->map, &w->map.exit_info);
	images_loaded(&w->map, &w->map.player_info);
	if (w->map.error < 0)
	{
		error_messages(w->map.error);
		free_window(w);
	}
}
