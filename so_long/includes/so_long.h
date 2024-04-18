/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:38:03 by bhumeau           #+#    #+#             */
/*   Updated: 2024/01/12 12:38:06 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../includes/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct monster
{
	void		*right;
	void		*left;
	int			count;
	int			pattern;
	int			x;
	int			y;
	int			height;
	int			width;
}				t_monster;

typedef struct sprites
{
	void		*right;
	void		*left;
	void		*up;
	void		*down;
	int			x;
	int			y;
	int			height;
	int			width;
}				t_sprites;

typedef struct map
{
	char		*name;
	char		**elements;
	int			fd;
	int			error;
	int			argc;
	size_t		pixels;
	size_t		height;
	size_t		width;
	size_t		nb_player;
	size_t		nb_collectible;
	size_t		nb_exit;
	size_t		collectible_flood;
	size_t		exit_flood;
	size_t		steps;
	t_sprites	player_info;
	t_sprites	object_info;
	t_sprites	wall_info;
	t_sprites	empty_info;
	t_sprites	exit_info;
	t_monster	monster;
}				t_map_info;

typedef struct window_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map_info	map;
}				t_window_info;

void	initialize_struct_map(t_window_info *win, int argc, char *argv);
void	initialize_window_entitites(t_window_info *win);
void	print_images(t_window_info *w, t_map_info *m, size_t x, size_t y);
void	check_map_all(t_window_info *win);
void	check_argc_and_name(t_map_info *map);
void	check_map_rectangle(t_map_info *map, char *line);
void	get_map_elements(t_map_info *map);
void	check_walls(t_map_info *map, size_t i);
void	check_map_entities(t_map_info *map, size_t i, size_t j);
void	check_entities_number(t_map_info *map);
void	check_map_accessibility(t_map_info *map);
char	**duplicate_map(t_map_info *map, size_t i);
void	flood_map(t_map_info *map, char **map_duplicate, int x, int y);
void	flood_all_directions(t_map_info *map, char **map_dup, int x, int y);
void	free_map_elements(char **str, size_t i);
int		free_window(t_window_info *w);
void	error_messages(int error_number);
int		no_event(void);
int		deal_key(int key, t_window_info *w);
void	collectible_event(t_window_info *w, t_map_info *map);
void	moove_down(t_window_info *w, t_sprites *p);
void	moove_up(t_window_info *w, t_sprites *p);
void	moove_left(t_window_info *w, t_sprites *p);
void	moove_right(t_window_info *w, t_sprites *p);
void	load_sprites(t_window_info *w);
void	load_sprites_192(t_window_info *w, t_map_info *m, t_sprites *e);
void	load_player_sprite_192(t_window_info *w, t_sprites *p);
void	load_sprites_128(t_window_info *w, t_map_info *m, t_sprites *e);
void	load_player_sprite_128(t_window_info *w, t_sprites *p);
void	load_sprites_64(t_window_info *w, t_map_info *m, t_sprites *e);
void	load_player_sprite_64(t_window_info *w, t_sprites *p);
void	load_sprites_32(t_window_info *w, t_map_info *m, t_sprites *e);
void	load_player_sprite_32(t_window_info *w, t_sprites *p);
void	images_loaded(t_map_info *map, t_sprites *player);
char	*ft_itoa(int n);
void	moove_monster(t_window_info *w);
void	load_monster_sprites(t_window_info *w);
void	free_monster_images(t_window_info *w);

#endif