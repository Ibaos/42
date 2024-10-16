/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:48:21 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 17:43:36 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static int	mouse_and_map(t_data *data, int keycode)
{
	if (keycode == XK_q && data->move_mouse == 0 && !data->show_map)
	{
		data->move_mouse = 1;
		mlx_mouse_move(data->mlx.mlx, data->mlx.win,
			WIDTH / 2, HEIGHT / 2);
	}
	else if (keycode == XK_q && data->move_mouse == 1 && !data->show_map)
		data->move_mouse = 0;
	else if (keycode == XK_e && !data->show_map)
		open_close_door(data);
	else if (keycode == XK_m && data->show_map == 0)
	{
		data->move_mouse = 0;
		data->show_map = 1;
		data->frame = 24;
	}
	else if (keycode == XK_m && data->show_map == 1)
		data->show_map = 2;
	return (0);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data->mlx.mlx);
	if (keycode == XK_w && !data->show_map)
		data->player.walk_dir = 1;
	if (keycode == XK_s && !data->show_map)
		data->player.walk_dir = -1;
	if (keycode == XK_a && !data->show_map)
		data->player.strafe_dir = -1;
	if (keycode == XK_d && !data->show_map)
		data->player.strafe_dir = 1;
	if (keycode == XK_Left && !data->show_map)
		data->player.turn_dir = 1;
	if (keycode == XK_Right && !data->show_map)
		data->player.turn_dir = -1;
	if (keycode == XK_Shift_L && !data->show_map)
	{
		data->player.move_speed *= 1.5;
		data->player.rot_speed *= 1.5;
	}
	mouse_and_map(data, keycode);
	return (0);
}

static int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->player.walk_dir = 0;
	if (keycode == XK_s)
		data->player.walk_dir = 0;
	if (keycode == XK_a)
		data->player.strafe_dir = 0;
	if (keycode == XK_d)
		data->player.strafe_dir = 0;
	if (keycode == XK_Left)
		data->player.turn_dir = 0;
	if (keycode == XK_Right)
		data->player.turn_dir = 0;
	if (keycode == XK_Shift_L)
	{
		data->player.move_speed /= 1.5;
		data->player.rot_speed /= 1.5;
	}
	return (0);
}

void	mlx(t_data *data)
{
	if (!mlx_initialize(data))
	{
		mlx_hook(data->mlx.win, 17, 1L << 3, mlx_loop_end, data->mlx.mlx);
		mlx_hook(data->mlx.win, 2, 1L << 0, key_press, data);
		mlx_hook(data->mlx.win, 3, 1L << 1, key_release, data);
		mlx_loop_hook(data->mlx.mlx, game_loop, data);
		mlx_loop(data->mlx.mlx);
	}
	free_mlx(data);
}
