/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:28:25 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static void	set_player(t_data *data, size_t i, size_t j)
{
	if (data->map.map[i][j] == 'N')
	{
		data->player.dir_y = -1;
		data->player.plane_x = 0.66;
	}
	else if (data->map.map[i][j] == 'S')
	{
		data->player.dir_y = 1;
		data->player.plane_x = -0.66;
	}
	else if (data->map.map[i][j] == 'W')
	{
		data->player.dir_x = -1;
		data->player.plane_y = -0.66;
	}
	else if (data->map.map[i][j] == 'E')
	{
		data->player.dir_x = 1;
		data->player.plane_y = 0.66;
	}
}

bool	set_entities(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width - 1)
		{
			if (is_player(data->map.map[i][j]))
			{
				data->player.pos_x = j + 0.5;
				data->player.pos_y = i + 0.5;
				set_player(data, i, j);
				data->map.map[i][j] = '0';
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}
