/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:39:05 by bhumeau           #+#    #+#             */
/*   Updated: 2024/03/07 13:39:06 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_struct_map(t_window_info *win, int argc, char *argv)
{
	win->map.height = 0;
	win->map.width = 0;
	win->map.error = 0;
	win->map.name = argv;
	win->map.argc = argc;
	win->map.nb_player = 0;
	win->map.nb_collectible = 0;
	win->map.nb_exit = 0;
	win->map.collectible_flood = 0;
	win->map.exit_flood = 0;
	win->map.pixels = 192;
	win->map.steps = 0;
	win->win_ptr = NULL;
}
