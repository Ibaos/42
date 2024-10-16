/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:12:18 by vdomasch          #+#    #+#             */
/*   Updated: 2024/10/08 13:15:33 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static int	set_color(t_textures *textures, char *line, char orientation)
{
	int	color;
	int	coef;
	int	tmp;

	coef = 0x1000000;
	tmp = 0;
	while (*line && coef)
	{
		color = ft_atoi(line);
		if (color < 0 || color > 0xFF)
			return (print_error("Invalid color.\n", 1));
		while (*line && (ft_isdigit(*line)))
			line++;
		while (*line == ',' || *line == ' ' || *line == '\n')
			line++;
		tmp += color * (coef / 0x100);
		coef /= 0x100;
	}
	if (coef != 1)
		return (print_error("Invalid color.\n", 1));
	if (orientation == 'F')
		textures->floor_color = tmp;
	else if (orientation == 'C')
		textures->ceiling_color = tmp;
	return (orientation);
}

static int	set_texture(t_textures *textures, char *path, char orientation)
{
	int		i;
	char	*copy;

	i = 0;
	while (path[ft_strlen(path) - i - 1] == '\n'
		|| path[ft_strlen(path) - i - 1] == ' ')
		i++;
	if (ft_strncmp(&path[ft_strlen(path) - i - 4], ".xpm", 4))
		return (print_error("Invalid file extension.\n", 1));
	while (*path == ' ')
		path++;
	copy = ft_strdup(path);
	if (!copy)
		return (print_error("Malloc failed.\n", 0));
	copy[ft_strlen(copy) - i] = '\0';
	if (orientation == 'N')
		textures->no = copy;
	else if (orientation == 'S')
		textures->so = copy;
	else if (orientation == 'W')
		textures->we = copy;
	else if (orientation == 'E')
		textures->ea = copy;
	return (orientation);
}

bool	set_elemets(t_data *data, int fd)
{
	char	*str;
	int		count;
	int		check;

	count = 0;
	check = 0;
	while (get_next_line(fd, &str) > 0)
	{
		if ((((str[0] == 'N' || str[0] == 'S') && str[1] == 'O' )
				|| (str[0] == 'W' && str [1] == 'E')
				|| (str[0] == 'E' && str[1] == 'A'))
			&& str[2] == ' ' && ++count)
			check += set_texture(&data->textures, str + 3, str[0]);
		else if ((str[0] == 'F' || str[0] == 'C') && str[1] == ' ' && ++count)
			check += set_color(&data->textures, str + 2, str[0]);
		free(str);
		if (check == 454 || count == 6)
			break ;
	}
	if (check != 454 || count != 6)
		return (print_error("Invalid elements.\n", false));
	return (true);
}
