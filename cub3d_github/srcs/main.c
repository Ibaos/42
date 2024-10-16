/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:15:43 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/09 13:26:12 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

int	print_error(char *error, int ret)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	return (ret);
}

static bool	init_textures(t_data *data)
{
	data->textures.no = NULL;
	data->textures.so = NULL;
	data->textures.we = NULL;
	data->textures.ea = NULL;
	data->textures.floor_color = -1;
	data->textures.ceiling_color = -1;
	data->textures.images = malloc(sizeof(t_image) * 5);
	if (!data->textures.images)
	{
		free(data);
		return (false);
	}
	data->textures.big_map = malloc(sizeof(t_image) * 6);
	if (!data->textures.big_map)
	{
		free(data->textures.images);
		free(data);
		return (false);
	}
	ft_memset(data->textures.images, 0, sizeof(t_image) * 5);
	ft_memset(data->textures.big_map, 0, sizeof(t_image) * 6);
	return (true);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data || !init_textures(data))
		return (NULL);
	data->move_mouse = 0;
	data->show_map = 0;
	data->map.map = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0;
	data->player.walk_dir = 0;
	data->player.strafe_dir = 0;
	data->player.turn_dir = 0;
	data->player.move_speed = 0.1;
	data->player.rot_speed = 0.05;
	return (data);
}

static bool	parsing(t_data *data, char *path)
{
	int	fd;

	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4))
		return (print_error("Invalid file extension.\n", false));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (print_error("Can't open file.\n", false));
	if (!set_elemets(data, fd))
		return (false);
	if (!set_map(data, fd))
		return (false);
	close(fd);
	if (!check_map(data->map.map, data->map.width, data->map.height, 0))
		return (false);
	if (!set_entities(data))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (print_error("Invalid number of argument.\n", 1));
	if (WIDTH < 640 || HEIGHT < 480)
		return (print_error("Resolution too low.\n", 1));
	if (WIDTH > 1920 || HEIGHT > 1080)
		return (print_error("Resolution too high.\n", 1));
	data = init_data();
	if (!data)
		return (print_error("Failed to allocate memory.\n", 1));
	if (parsing(data, argv[1]))
	{
		if (data->map.height < LIMIT && data->map.width < LIMIT)
			mlx(data);
		else
			print_error("Map too big.\n", 1);
	}
	free_all(data);
	return (0);
}
