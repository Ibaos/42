/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:30:56 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static bool	load_addr_textures_big_map(t_image *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		map[i].addr = mlx_get_data_addr(map[i].img, &map[i].bits_per_pixel,
				&map[i].line_length, &map[i].endian);
		if (!map[i].addr)
			return (print_error("Failed to get big map address.\n", false));
		i++;
	}
	return (true);
}

static bool	load_textures_big_map(t_data *data, t_image *map)
{
	map[0].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map0.xpm",
			&map[0].width, &map[0].height);
	map[1].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map1.xpm",
			&map[1].width, &map[1].height);
	map[2].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map2.xpm",
			&map[2].width, &map[2].height);
	map[3].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map3.xpm",
			&map[3].width, &map[3].height);
	map[4].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map4.xpm",
			&map[4].width, &map[4].height);
	map[5].img = mlx_xpm_file_to_image(data->mlx.mlx, "./assets/big_map5.xpm",
			&map[5].width, &map[5].height);
	if (!map[0].img || !map[1].img || !map[2].img
		|| !map[3].img || !map[4].img || !map[5].img)
		return (print_error("Failed to load big map images.\n", false));
	if (!load_addr_textures_big_map(map))
		return (false);
	return (true);
}

static bool	load_textures_addr(t_image *images)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		images[i].addr = mlx_get_data_addr(images[i].img,
				&images[i].bits_per_pixel, &images[i].line_length,
				&images[i].endian);
		if (!images[i].addr)
			return (print_error("Failed to get textures address.\n", false));
		i++;
	}
	return (true);
}

static bool	load_textures(void *mlx, t_textures *textures, t_image *images)
{
	images[0].img = mlx_xpm_file_to_image(mlx, textures->no,
			&images[0].width, &images[0].height);
	images[1].img = mlx_xpm_file_to_image(mlx, textures->so,
			&images[1].width, &images[1].height);
	images[2].img = mlx_xpm_file_to_image(mlx, textures->we,
			&images[2].width, &images[2].height);
	images[3].img = mlx_xpm_file_to_image(mlx, textures->ea,
			&images[3].width, &images[3].height);
	images[4].img = mlx_xpm_file_to_image(mlx, "./assets/wooden-door.xpm",
			&images[4].width, &images[4].height);
	if (!images[0].img || !images[1].img || !images[2].img
		|| !images[3].img || !images[4].img)
		return (print_error("Failed to load images.\n", false));
	if (!load_textures_addr(images))
		return (false);
	return (true);
}

int	mlx_initialize(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (print_error("Failed to initialize mlx.\n", 1));
	data->mlx.win = mlx_new_window(data->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!data->mlx.win)
		return (print_error("Failed to create window.\n", 1));
	data->mlx.img.img = mlx_new_image(data->mlx.mlx, WIDTH, HEIGHT);
	if (!data->mlx.img.img)
		return (print_error("Failed to create image.\n", 1));
	data->mlx.img.addr = mlx_get_data_addr(data->mlx.img.img,
			&data->mlx.img.bits_per_pixel, &data->mlx.img.line_length,
			&data->mlx.img.endian);
	if (!data->mlx.img.addr)
		return (print_error("Failed to get image address.\n", 1));
	if (!load_textures(data->mlx.mlx, &data->textures, data->textures.images))
		return (print_error("Failed to load textures.\n", 1));
	if (!load_textures_big_map(data, data->textures.big_map))
		return (print_error("Failed to load big map textures.\n", 1));
	return (0);
}
