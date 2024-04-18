/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:03:35 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/12 11:03:55 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_images(t_window_info *w, t_map_info *m, size_t x, size_t y)
{
	if (m->elements[y][x] == '1')
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, m->wall_info.right,
			x * m->pixels, y * m->pixels);
	if (m->elements[y][x] == '0')
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, m->empty_info.right,
			x * m->pixels, y * m->pixels);
	if (m->elements[y][x] == 'C')
	{
		if (m->collectible_flood % 2 == 1)
			mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
				m->object_info.right, x * m->pixels, y * m->pixels);
		else
			mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, m->object_info.left,
				x * m->pixels, y * m->pixels);
		m->collectible_flood--;
	}
	if (m->elements[y][x] == 'E')
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, m->exit_info.down,
			x * m->pixels, y * m->pixels);
	if (m->elements[y][x] == 'P')
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, m->player_info.right,
			x * m->pixels, y * m->pixels);
}

void	initialize_window_entitites(t_window_info *win)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < win->map.height)
	{
		x = 0;
		while (x < win->map.width)
		{
			print_images(win, &win->map, x, y);
			x++;
		}
		y++;
	}
	win->map.collectible_flood = win->map.nb_collectible;
}

void	check_map_all(t_window_info *win)
{
	check_argc_and_name(&(win->map));
	if (win->map.error < 0)
		return ;
	check_map_rectangle(&(win->map), " ");
	if (win->map.error < 0)
		return ;
	get_map_elements(&(win->map));
	if (win->map.error < 0)
		return ;
	check_map_entities(&(win->map), 1, 1);
	if (win->map.error < 0)
		return ;
	check_map_accessibility(&win->map);
	if (win->map.error < 0)
		return ;
}

void	mlx_start(t_window_info *win)
{
	win->win_ptr = mlx_new_window(win->mlx_ptr,
			win->map.width * win->map.pixels,
			win->map.height * win->map.pixels, "so_long");
	if (win->win_ptr == NULL)
	{
		win->map.error = -14;
		error_messages(win->map.error);
		free_window(win);
	}
	initialize_window_entitites(win);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, deal_key, win);
	mlx_hook(win->win_ptr, DestroyNotify, StructureNotifyMask,
		free_window, win);
	mlx_loop(win->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_window_info	win;

	initialize_struct_map(&win, argc, argv[1]);
	check_map_all(&win);
	if (win.map.error < 0)
		return (0);
	win.mlx_ptr = mlx_init();
	if (win.mlx_ptr == NULL)
	{
		win.map.error = -13;
		error_messages(win.map.error);
		free_map_elements(win.map.elements, win.map.height);
		free(win.mlx_ptr);
		return (0);
	}
	load_sprites(&win);
	if (win.map.error < 0)
		return (1);
	mlx_start(&win);
	return (0);
}
