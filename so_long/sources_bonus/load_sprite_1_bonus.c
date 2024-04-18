/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:39:02 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:39:06 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_player_sprite_32(t_window_info *w, t_sprites *p)
{
	p->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/knight_right.xpm", &p->width, &p->height);
	p->left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/knight_left.xpm", &p->width, &p->height);
	p->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/knight_up.xpm", &p->width, &p->height);
	p->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/knight_down.xpm", &p->width, &p->height);
}

void	load_sprites_32(t_window_info *w, t_map_info *m, t_sprites *e)
{
	load_player_sprite_32(w, &w->map.player_info);
	m->wall_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/tree.xpm", &m->wall_info.width,
			&m->wall_info.height);
	m->empty_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/grass.xpm", &m->empty_info.width,
			&m->empty_info.height);
	m->object_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/wood.xpm", &m->object_info.width,
			&m->object_info.height);
	m->object_info.left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/rocks.xpm", &m->object_info.width,
			&m->object_info.height);
	e->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/tower_down.xpm", &e->width, &e->height);
	e->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/tower_right.xpm", &e->width, &e->height);
	e->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/32/tower_up.xpm", &e->width, &e->height);
}

void	load_player_sprite_64(t_window_info *w, t_sprites *p)
{
	p->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/knight_right.xpm", &p->width, &p->height);
	p->left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/knight_left.xpm", &p->width, &p->height);
	p->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/knight_up.xpm", &p->width, &p->height);
	p->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/knight_down.xpm", &p->width, &p->height);
}

void	load_sprites_64(t_window_info *w, t_map_info *m, t_sprites *e)
{
	load_player_sprite_64(w, &w->map.player_info);
	m->wall_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/tree.xpm", &m->wall_info.width,
			&m->wall_info.height);
	m->empty_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/grass.xpm", &m->empty_info.width,
			&m->empty_info.height);
	m->object_info.right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/wood.xpm", &m->object_info.width,
			&m->object_info.height);
	m->object_info.left = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/rocks.xpm", &m->object_info.width,
			&m->object_info.height);
	e->down = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/tower_down.xpm", &e->width, &e->height);
	e->right = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/tower_right.xpm", &e->width, &e->height);
	e->up = mlx_xpm_file_to_image(w->mlx_ptr,
			"./sprites/64/tower_up.xpm", &e->width, &e->height);
}
