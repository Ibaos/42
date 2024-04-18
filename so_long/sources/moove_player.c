/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:43:20 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:43:31 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_steps(t_window_info *w)
{
	char	*steps;

	steps = ft_itoa(w->map.steps);
	if (!steps)
	{
		w->map.error = -10;
		error_messages(w->map.error);
		free_window(w);
	}
	write(STDOUT_FILENO, "Steps: ", 7);
	write(STDOUT_FILENO, steps, ft_strlen(steps));
	write(STDOUT_FILENO, "\n", 1);
	free(steps);
}

void	moove_right(t_window_info *w, t_sprites *p)
{
	if (w->map.elements[p->y / w->map.pixels][(p->x / w->map.pixels) + 1] != '1'
		&& w->map.elements[p->y / w->map.pixels]
		[(p->x / w->map.pixels) + 1] != 'E')
	{
		if (w->map.elements[p->y / w->map.pixels]
			[(p->x / w->map.pixels) + 1] == 'C')
		{
			w->map.nb_collectible--;
			w->map.elements[p->y / w->map.pixels]
			[(p->x / w->map.pixels) + 1] = '0';
		}
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			w->map.empty_info.right, p->x, p->y);
		p->x += w->map.pixels;
		w->map.steps++;
		print_steps(w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, p->right, p->x, p->y);
}

void	moove_left(t_window_info *w, t_sprites *p)
{
	if (w->map.elements[p->y / w->map.pixels][(p->x / w->map.pixels) - 1] != '1'
		&& w->map.elements[p->y / w->map.pixels]
		[(p->x / w->map.pixels) - 1] != 'E')
	{
		if (w->map.elements[p->y / w->map.pixels]
			[(p->x / w->map.pixels) - 1] == 'C')
		{
			w->map.nb_collectible--;
			w->map.elements[p->y / w->map.pixels]
			[(p->x / w->map.pixels) - 1] = '0';
		}
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			w->map.empty_info.right, p->x, p->y);
		p->x -= w->map.pixels;
		w->map.steps++;
		print_steps(w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, p->left, p->x, p->y);
}

void	moove_up(t_window_info *w, t_sprites *p)
{
	if (w->map.elements[(p->y / w->map.pixels) - 1]
		[p->x / w->map.pixels] != '1'
		&& w->map.elements[(p->y / w->map.pixels) - 1]
		[p->x / w->map.pixels] != 'E')
	{
		if (w->map.elements[(p->y / w->map.pixels) - 1]
			[p->x / w->map.pixels] == 'C')
		{
			w->map.nb_collectible--;
			w->map.elements[(p->y / w->map.pixels) - 1]
			[p->x / w->map.pixels] = '0';
		}
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			w->map.empty_info.right, p->x, p->y);
		p->y -= w->map.pixels;
		w->map.steps++;
		print_steps(w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, p->up, p->x, p->y);
}

void	moove_down(t_window_info *w, t_sprites *p)
{
	if (w->map.elements[(p->y / w->map.pixels) + 1]
		[p->x / w->map.pixels] != '1'
		&& w->map.elements[(p->y / w->map.pixels) + 1]
		[p->x / w->map.pixels] != 'E')
	{
		if (w->map.elements[(p->y / w->map.pixels) + 1]
			[p->x / w->map.pixels] == 'C')
		{
			w->map.nb_collectible--;
			w->map.elements[(p->y / w->map.pixels) + 1]
			[p->x / w->map.pixels] = '0';
		}
		mlx_put_image_to_window(w->mlx_ptr, w->win_ptr,
			w->map.empty_info.right, p->x, p->y);
		p->y += w->map.pixels;
		w->map.steps++;
		print_steps(w);
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, p->down, p->x, p->y);
}
