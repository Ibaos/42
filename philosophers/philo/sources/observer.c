/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:01:29 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/16 10:48:52 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

bool	verify_death(t_data *data, int nb_philos)
{
	int		i;

	i = 0;
	while (i < nb_philos)
	{
		if (get_time() - get_mutex_size_t(&data->philos[i].m_id,
				&data->philos[i].last_eat) > data->time_to_die)
		{
			print_message("%zu %d died\n", &data->philos[i]);
			set_mutex_bool(&data->m_data, &data->is_dead, true);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	verify_eaten(t_data *data, int nb_philos)
{
	int	i;

	i = 0;
	data->nb_have_eaten = 0;
	while (i < nb_philos)
	{
		if (get_mutex_int(&data->philos[i].m_id,
				&data->philos[i].eat_count) >= data->must_eat_nbr)
			data->nb_have_eaten++;
		i++;
	}
	if (data->nb_have_eaten >= nb_philos)
	{
		set_mutex_bool(&data->m_data, &data->is_dead, true);
		return (true);
	}
	return (false);
}

void	observer_routine(t_data *data, int nb_philos)
{
	ft_msleep(10);
	if (data->must_eat_nbr == -1)
	{
		while (42)
		{
			if (verify_death(data, nb_philos))
				break ;
			usleep(100);
		}
	}
	else
	{
		while (42)
		{
			if (verify_death(data, nb_philos))
				return ;
			if (verify_eaten(data, nb_philos))
				return ;
			usleep(100);
		}
	}
}
