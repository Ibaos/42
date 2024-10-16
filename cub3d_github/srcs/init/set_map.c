/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdomasch <vdomasch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:14:18 by bhumeau           #+#    #+#             */
/*   Updated: 2024/10/14 16:50:38 by vdomasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

static bool	is_space_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static void	is_line_longer(char *line, t_data *data)
{
	if (ft_strlen(line) > data->map.width)
		data->map.width = ft_strlen(line);
}

static char	*skip_space_line(int fd)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (is_space_line(line))
		{
			free(line);
			line = NULL;
		}
		else
			break ;
	}
	return (line);
}

static bool	init_map_line(char **line, char **map_line, int fd)
{
	*line = skip_space_line(fd);
	if (!*line)
		return (print_error("No map after elements.\n", false));
	*map_line = ft_strdup("");
	if (!*map_line)
	{
		if (*line)
			free(*line);
		return (print_error("Malloc failed.\n", false));
	}
	return (true);
}

bool	set_map(t_data *data, int fd)
{
	char	*line;
	char	*map_line;

	if (!init_map_line(&line, &map_line, fd))
		return (false);
	while (line || get_next_line(fd, &line) > 0)
	{
		is_line_longer(line, data);
		map_line = ft_strfreejoin(map_line, line);
		if (is_space_line(line))
		{
			free(line);
			free(map_line);
			return (print_error("Empty line in map.\n", false));
		}
		free(line);
		line = NULL;
		if (!map_line)
			return (false);
		data->map.height++;
	}
	data->map.map = split_size_free(map_line, '\n', data->map.width);
	if (!data->map.map)
		return (print_error("Malloc failed.\n", false));
	return (true);
}
