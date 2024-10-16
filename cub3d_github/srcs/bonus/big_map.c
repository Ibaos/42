/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:20:57 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/08 14:16:31 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static void	draw_square_map(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	scale;

	if (400 / data->map.width < 240 / data->map.height)
		scale = 400 / data->map.width;
	else
		scale = 240 / data->map.height;
	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			my_mlx_pixel_put(&data->mlx.img, (WIDTH
					- (data->map.width - 1) * scale) / 2 + x * scale + j,
				(HEIGHT - (data->map.height * 0.68 * scale))
				/ 1.8 + y * scale + i, color);
			j++;
		}
		i++;
	}
}

static void	draw_map(t_data *data)
{
	unsigned long	x;
	unsigned long	y;

	x = 0;
	y = 0;
	while (x < data->map.width)
	{
		y = 0;
		while (y < data->map.height)
		{
			if (data->map.map[y][x] == '1')
				draw_square_map(data, x, y, MAP_COLOR_WALL);
			else if (data->map.map[y][x] == '0'
					|| is_player(data->map.map[y][x]))
				draw_square_map(data, x, y, MAP_COLOR_FLOOR);
			else if (is_door(data->map.map[y][x]))
				draw_square_map(data, x, y, MAP_COLOR_DOOR);
			else
				draw_square_map(data, x, y, MAP_COLOR_SCROLL);
			y++;
		}
		x++;
	}
}

void	big_map(t_data *data, t_textures *tex)
{
	unsigned int	color;
	int				x;
	int				y;

	x = -1;
	while (++x < tex->big_map[data->frame / 5].width)
	{
		y = -1;
		while (++y < tex->big_map[data->frame / 5].height)
		{
			color = get_pixel(tex->big_map, data->frame / 5, x, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&data->mlx.img, x + WIDTH / 2
					- tex->big_map[data->frame / 5].width / 2, y + HEIGHT / 1.8
					- tex->big_map[data->frame / 5].height / 2, color);
		}
	}
	if (data->show_map == 1 && data->frame == 0)
		draw_map(data);
	if (data->show_map == 1 && data->frame > 0)
		data->frame--;
	else if (data->show_map == 2 && data->frame < 25)
		data->frame++;
	if (data->show_map == 2 && data->frame == 25)
		data->show_map = 0;
}
