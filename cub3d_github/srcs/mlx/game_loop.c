/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:44:27 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static int	check_collision(t_data *d, double new_y, double new_x)
{
	char	tile;

	tile = d->map.map[(int)new_y][(int)new_x];
	return (tile != '1' && tile != 'c');
}

static void	move_player(t_data *d, t_player *p)
{
	if (p->walk_dir == 1 && check_collision(d,
			p->pos_y + p->dir_y * (p->move_speed + 0.28), p->pos_x))
		p->pos_y += p->dir_y * p->move_speed;
	if (p->walk_dir == 1 && check_collision(d,
			p->pos_y, p->pos_x + p->dir_x * (p->move_speed + 0.28)))
		p->pos_x += p->dir_x * p->move_speed;
	if (p->walk_dir == -1 && check_collision(d,
			p->pos_y - p->dir_y * (p->move_speed + 0.28), p->pos_x))
		p->pos_y -= p->dir_y * p->move_speed;
	if (p->walk_dir == -1 && check_collision(d,
			p->pos_y, p->pos_x - p->dir_x * (p->move_speed + 0.28)))
		p->pos_x -= p->dir_x * p->move_speed;
	if (p->strafe_dir == -1 && check_collision(d,
			p->pos_y, p->pos_x + p->dir_y * (p->move_speed + 0.28)))
		p->pos_x += p->dir_y * p->move_speed;
	if (p->strafe_dir == -1 && check_collision(d,
			p->pos_y - p->dir_x * (p->move_speed + 0.28), p->pos_x))
		p->pos_y -= p->dir_x * p->move_speed;
	if (p->strafe_dir == 1 && check_collision(d,
			p->pos_y, p->pos_x - p->dir_y * (p->move_speed + 0.28)))
		p->pos_x -= p->dir_y * p->move_speed;
	if (p->strafe_dir == 1 && check_collision(d,
			p->pos_y + p->dir_x * (p->move_speed + 0.28), p->pos_x))
		p->pos_y += p->dir_x * p->move_speed;
}

static void	rotate_player(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_v;

	rot_v = p->rot_speed;
	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	if (p->turn_dir == 1)
	{
		p->dir_x = p->dir_x * cos(-rot_v) - p->dir_y * sin(-rot_v);
		p->dir_y = old_dir_x * sin(-rot_v) + p->dir_y * cos(-rot_v);
		p->plane_x = p->plane_x * cos(-rot_v) - p->plane_y * sin(-rot_v);
		p->plane_y = old_plane_x * sin(-rot_v) + p->plane_y * cos(-rot_v);
	}
	if (p->turn_dir == -1)
	{
		p->dir_x = p->dir_x * cos(rot_v) - p->dir_y * sin(rot_v);
		p->dir_y = old_dir_x * sin(rot_v) + p->dir_y * cos(rot_v);
		p->plane_x = p->plane_x * cos(rot_v) - p->plane_y * sin(rot_v);
		p->plane_y = old_plane_x * sin(rot_v) + p->plane_y * cos(rot_v);
	}
}

static void	rotate_player_mouse(t_player *play, double x)
{
	double	rot_v;
	double	old_dir_x;
	double	old_plane_x;

	rot_v = play->rot_speed * x * 0.05;
	old_plane_x = play->plane_x;
	old_dir_x = play->dir_x;
	play->dir_x = play->dir_x * cos(rot_v) - play->dir_y * sin(rot_v);
	play->dir_y = old_dir_x * sin(rot_v) + play->dir_y * cos(rot_v);
	play->plane_x = play->plane_x * cos(rot_v) - play->plane_y * sin(rot_v);
	play->plane_y = old_plane_x * sin(rot_v) + play->plane_y * cos(rot_v);
}

int	game_loop(t_data *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (d->player.walk_dir || d->player.strafe_dir)
		move_player(d, &d->player);
	if (d->player.turn_dir)
		rotate_player(&d->player);
	if (d->move_mouse)
	{
		mlx_mouse_get_pos(d->mlx.mlx, d->mlx.win, &x, &y);
		rotate_player_mouse(&d->player, (x - WIDTH / 2));
		if (x > WIDTH / 2 + 1 || x < WIDTH / 2 - 1
			|| y > HEIGHT / 2 + 1 || y < HEIGHT / 2 - 1)
			mlx_mouse_move(d->mlx.mlx, d->mlx.win, WIDTH / 2,
				HEIGHT / 2);
	}
	raycasting(d);
	if (!d->show_map)
		draw_minimap(d, &d->map, (int)d->player.pos_x, (int)d->player.pos_y);
	else
		big_map(d, &d->textures);
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.win, d->mlx.img.img, 0, 0);
	return (0);
}
