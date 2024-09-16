/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:21:32 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/15 16:10:32 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

void	initialize_basic_values(t_data *data, t_philo *philo, int i)
{
	philo->id = i + 1;
	philo->eat_count = 0;
	philo->data = data;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->number_of_philosophers = data->number_of_philosophers;
	philo->left_fork = false;
}

void	initialize_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->number_of_philosophers)
	{
		philo = &data->philos[i];
		initialize_basic_values(data, philo, i);
		if (i + 1 < data->number_of_philosophers)
		{
			philo->m_right_fork = &data->philos[i + 1].m_left_fork;
			philo->right_fork = &data->philos[i + 1].left_fork;
		}
		else
		{
			philo->m_right_fork = &data->philos[0].m_left_fork;
			philo->right_fork = &data->philos[0].left_fork;
		}
		pthread_mutex_init(&philo->m_left_fork, NULL);
		pthread_mutex_init(&philo->m_id, NULL);
		if (philo->id % 2 == 1)
			pthread_create(&philo->thread, NULL, &odd_routine, philo);
		else
			pthread_create(&philo->thread, NULL, &even_routine, philo);
	}
}

static bool	check_atoi_errors(t_data *data)
{
	if ((int)data->number_of_philosophers <= 0)
		;
	else if ((int)data->time_to_die <= 0)
		;
	else if ((int)data->time_to_eat <= 0)
		;
	else if ((int)data->time_to_sleep <= 0)
		;
	else
		return (true);
	ft_putstr_fd(VALUE_ERROR, 2);
	return (false);
}

bool	initialize_struct(t_data *data, int argc, char **argv)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = 0;
	data->is_dead = false;
	data->ready = false;
	pthread_mutex_init(&data->m_data, NULL);
	pthread_mutex_init(&data->m_ready, NULL);
	pthread_mutex_init(&data->m_print, NULL);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) <= 0)
		{
			ft_putstr_fd(VALUE_ERROR, 2);
			return (false);
		}
		else
			data->must_eat_nbr = ft_atoi(argv[5]);
	}
	else
		data->must_eat_nbr = -1;
	if (!check_atoi_errors(data))
		return (false);
	return (true);
}
