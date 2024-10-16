/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:00:12 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

void	destroy_textures_big_map(t_data *data)
{
	if (data->textures.big_map[0].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[0].img);
	if (data->textures.big_map[1].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[1].img);
	if (data->textures.big_map[2].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[2].img);
	if (data->textures.big_map[3].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[3].img);
	if (data->textures.big_map[4].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[4].img);
	if (data->textures.big_map[5].img)
		mlx_destroy_image(data->mlx.mlx, data->textures.big_map[5].img);
}

void	free_mlx(t_data *data)
{
	if (data->mlx.mlx)
	{
		if (data->mlx.win)
		{
			if (data->mlx.img.img)
				mlx_destroy_image(data->mlx.mlx, data->mlx.img.img);
			if (data->textures.images[0].img)
				mlx_destroy_image(data->mlx.mlx, data->textures.images[0].img);
			if (data->textures.images[1].img)
				mlx_destroy_image(data->mlx.mlx, data->textures.images[1].img);
			if (data->textures.images[2].img)
				mlx_destroy_image(data->mlx.mlx, data->textures.images[2].img);
			if (data->textures.images[3].img)
				mlx_destroy_image(data->mlx.mlx, data->textures.images[3].img);
			if (data->textures.images[4].img)
				mlx_destroy_image(data->mlx.mlx, data->textures.images[4].img);
			if (data->textures.big_map)
				destroy_textures_big_map(data);
			mlx_destroy_window(data->mlx.mlx, data->mlx.win);
		}
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
}

void	free_map(char **map, int height)
{
	while (height >= 0)
	{
		free(map[height]);
		height--;
	}
	free(map);
}

void	free_all(t_data *data)
{
	if (data->textures.no)
		free(data->textures.no);
	if (data->textures.so)
		free(data->textures.so);
	if (data->textures.we)
		free(data->textures.we);
	if (data->textures.ea)
		free(data->textures.ea);
	if (data->textures.images)
		free(data->textures.images);
	if (data->textures.big_map)
		free(data->textures.big_map);
	if (data->map.map)
		free_map(data->map.map, data->map.height);
	free(data);
}
