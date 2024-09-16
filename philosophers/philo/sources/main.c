/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:51:42 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/16 11:54:02 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

void	free_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	while (--i >= 0)
	{
		pthread_mutex_destroy(&data->philos[i].m_left_fork);
		pthread_mutex_destroy(&data->philos[i].m_id);
	}
	pthread_mutex_destroy(&data->m_data);
	pthread_mutex_destroy(&data->m_ready);
	pthread_mutex_destroy(&data->m_print);
	free(data->philos);
}

void	*deadly_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_init(&philo->m_id, NULL);
	philo->right_fork = &philo->left_fork;
	while (!get_mutex_bool(&philo->data->m_data, &philo->data->ready))
	{
		usleep(10);
		set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	}
	if (!philo->left_fork)
	{
		philo->left_fork = 1;
		print_message("%zu %d has taken a fork\n", philo);
	}
	while (!philo->right_fork || get_mutex_bool(&philo->data->m_data,
			&philo->data->is_dead))
	{
		if (get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
			return (0);
		else
			print_message("%zu %d has taken a fork\n", philo);
	}
	return (0);
}

void	one_philo(t_data *data)
{
	initialize_basic_values(data, data->philos, 0);
	pthread_create(&data->philos->thread, NULL, &deadly_routine,
		&data->philos[0]);
	usleep(10);
	set_mutex_size_t(&data->m_data, &data->start_time, get_time());
	set_mutex_bool(&data->m_data, &data->ready, true);
	observer_routine(data, get_mutex_int(&data->m_data,
			&data->number_of_philosophers));
	pthread_join(data->philos[0].thread, NULL);
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->philos[0].m_id);
	free(data->philos);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf(FORMAT NB_PHILO TTDIE TTEAT TTSLEEP NB_EAT));
	if (!initialize_struct(&data, argc, argv))
		return (1);
	data.philos = malloc(sizeof(t_philo) * data.number_of_philosophers);
	if (!data.philos)
		return (ft_putstr_fd(MALLOC_ERROR, 2));
	if (ft_atoi(argv[1]) == 1)
	{
		one_philo(&data);
		return (0);
	}
	initialize_philos(&data);
	set_mutex_size_t(&data.m_data, &data.start_time, get_time());
	set_mutex_bool(&data.m_data, &data.ready, true);
	ft_msleep(10);
	observer_routine(&data, get_mutex_int(&data.m_data,
			&data.number_of_philosophers));
	ft_msleep(10);
	free_and_destroy(&data);
	return (0);
}
