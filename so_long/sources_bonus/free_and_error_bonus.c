/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:45:05 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/25 15:45:15 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_messages_bis(int error_number)
{
	if (error_number == -7)
	{
		write(STDERR_FILENO, "Player can't reach all", 22);
		write(STDERR_FILENO, " the collectibles or the exit!\n", 31);
	}
	if (error_number == -9)
	{
		write(STDERR_FILENO, "There is an incorrect", 21);
		write(STDERR_FILENO, " character in the map!\n", 23);
	}
	if (error_number == -10)
		write(STDERR_FILENO, "Malloc failed!\n", 15);
	if (error_number == -11)
		write(STDERR_FILENO, "Images are not loaded!\n", 23);
	if (error_number == -12)
		write(STDERR_FILENO, "Only 1 monster maximum is allowed!\n", 35);
	if (error_number == -13)
		write(STDERR_FILENO, "Mlx_init failed!\n", 17);
	if (error_number == -14)
		write(STDERR_FILENO, "Mlx_new_window failed!\n", 23);
	if (error_number == -15)
		write(STDERR_FILENO, "Invalid map extension!\n", 23);
}

void	error_messages(int error_number)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (error_number == -1)
	{
		write(STDERR_FILENO, "Need only 2 arguments, ", 23);
		write(STDERR_FILENO, "the project name and the map name!\n", 35);
	}
	if (error_number == -2)
		write(STDERR_FILENO, "Map name is incorrect!\n", 23);
	if (error_number == -3)
		write(STDERR_FILENO, "Map is not a rectangle!\n", 24);
	if (error_number == -4)
		write(STDERR_FILENO, "Map need to be closed by walls!\n", 32);
	if (error_number == -5)
	{
		write(STDERR_FILENO, "Map needs to have 1 player, 1 exit and ", 39);
		write(STDERR_FILENO, "at least 1 collectible!\n", 24);
	}
	if (error_number == -6)
		write(STDERR_FILENO, "Map must start with the character '1'!\n", 39);
	if (error_number < -6)
		error_messages_bis(error_number);
}

void	free_window_next(t_window_info *w)
{
	free_monster_images(w);
	if (w->win_ptr)
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	free_map_elements(w->map.elements, w->map.height);
	mlx_destroy_display(w->mlx_ptr);
	free(w->mlx_ptr);
	exit(0);
}

int	free_window(t_window_info *w)
{
	if (w->map.player_info.right)
		mlx_destroy_image(w->mlx_ptr, w->map.player_info.right);
	if (w->map.player_info.left)
		mlx_destroy_image(w->mlx_ptr, w->map.player_info.left);
	if (w->map.player_info.up)
		mlx_destroy_image(w->mlx_ptr, w->map.player_info.up);
	if (w->map.player_info.down)
		mlx_destroy_image(w->mlx_ptr, w->map.player_info.down);
	if (w->map.wall_info.right)
		mlx_destroy_image(w->mlx_ptr, w->map.wall_info.right);
	if (w->map.object_info.right)
		mlx_destroy_image(w->mlx_ptr, w->map.object_info.right);
	if (w->map.object_info.left)
		mlx_destroy_image(w->mlx_ptr, w->map.object_info.left);
	if (w->map.empty_info.right)
		mlx_destroy_image(w->mlx_ptr, w->map.empty_info.right);
	if (w->map.exit_info.down)
		mlx_destroy_image(w->mlx_ptr, w->map.exit_info.down);
	if (w->map.exit_info.right)
		mlx_destroy_image(w->mlx_ptr, w->map.exit_info.right);
	if (w->map.exit_info.up)
		mlx_destroy_image(w->mlx_ptr, w->map.exit_info.up);
	free_window_next(w);
	return (0);
}

void	free_map_elements(char **str, size_t i)
{
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}
