/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:33:26 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_image *images, int tex_num, int x, int y)
{
	char	*dst;

	dst = images[tex_num].addr + (y * images[tex_num].line_length
			+ x * (images[tex_num].bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static int	find_side(t_raycast *raycast)
{
	if (raycast->there_is_door)
		return (4);
	if (raycast->side == 0)
	{
		if (raycast->ray_dir_x > 0)
			return (2);
		else
			return (3);
	}
	else
	{
		if (raycast->ray_dir_y > 0)
			return (0);
		else
			return (1);
	}
}

static void	put_textures(t_data *data, t_raycast *ray, int x, int y)
{
	int		color;
	int		scaling;
	int		tex_x;
	int		tex_y;
	double	wall_x;

	if (ray->side == 0)
		wall_x = (data->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y);
	else
		wall_x = (data->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->textures.images[find_side(ray)].width);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		tex_x = data->textures.images[find_side(ray)].width - tex_x - 1;
	scaling = (y * 256) - HEIGHT * 128 + ray->line_height * 128;
	tex_y = ((scaling * data->textures.images[find_side(ray)].height)
			/ ray->line_height) / 256;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= data->textures.images[find_side(ray)].height)
		tex_y = data->textures.images[find_side(ray)].height - 1;
	color = get_pixel(data->textures.images, find_side(ray), tex_x, tex_y);
	my_mlx_pixel_put(&data->mlx.img, x, y, color);
}

void	draw(t_data *d, t_raycast *raycast, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (!d->show_map && x < SIZE_MINIMAP && y < SIZE_MINIMAP)
			;
		else if (y < raycast->draw_start)
			my_mlx_pixel_put(&d->mlx.img, x, y, d->textures.ceiling_color);
		else if (y >= raycast->draw_start && y <= raycast->draw_end)
			put_textures(d, raycast, x, y);
		else
			my_mlx_pixel_put(&d->mlx.img, x, y, d->textures.floor_color);
		y++;
	}
	raycast->there_is_door = false;
}
