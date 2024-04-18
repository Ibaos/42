/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:04:41 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/06 16:04:42 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	images_loaded(t_map_info *map, t_sprites *player)
{
	if (!player->up || !player->left || !player->down || !player->right)
		map->error = -11;
	if (!map->wall_info.right || !map->empty_info.right)
		map->error = -11;
	if (!map->object_info.right || !map->object_info.left)
		map->error = -11;
	if (!map->exit_info.down || !map->exit_info.right || !map->exit_info.up)
		map->error = -11;
}
