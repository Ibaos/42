/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:09:38 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/16 16:40:14 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

void	print_message(char *message, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	if (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		printf(message, get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	odd_while_routine(t_philo *philo)
{
	while (get_mutex_bool(philo->m_right_fork, philo->right_fork))
		usleep(100);
	set_mutex_bool(philo->m_right_fork, philo->right_fork, true);
	print_message("%zu %d has taken a fork\n", philo);
	while (get_mutex_bool(&philo->m_left_fork, &philo->left_fork))
		usleep(100);
	set_mutex_bool(&philo->m_left_fork, &philo->left_fork, true);
	print_message("%zu %d has taken a fork\n", philo);
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	print_message("%zu %d is eating\n", philo);
	set_mutex_int(&philo->m_id, &philo->eat_count, philo->eat_count + 1);
	if (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		ft_msleep(philo->time_to_eat);
	set_mutex_bool(philo->m_right_fork, philo->right_fork, false);
	set_mutex_bool(&philo->m_left_fork, &philo->left_fork, false);
	print_message("%zu %d is sleeping\n", philo);
	if (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		ft_msleep(philo->time_to_sleep);
	print_message("%zu %d is thinking\n", philo);
	usleep(200);
}

void	*odd_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	while (!get_mutex_bool(&philo->data->m_data, &philo->data->ready))
	{
		usleep(10);
		set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	}
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	print_message("%zu %d is thinking\n", philo);
	ft_msleep(60);
	while (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		odd_while_routine(philo);
	return (0);
}

void	even_while_routine(t_philo *philo)
{
	while (get_mutex_bool(philo->m_right_fork, philo->right_fork))
		usleep(100);
	set_mutex_bool(philo->m_right_fork, philo->right_fork, true);
	print_message("%zu %d has taken a fork\n", philo);
	while (get_mutex_bool(&philo->m_left_fork, &philo->left_fork))
		usleep(100);
	set_mutex_bool(&philo->m_left_fork, &philo->left_fork, true);
	print_message("%zu %d has taken a fork\n", philo);
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	print_message("%zu %d is eating\n", philo);
	set_mutex_int(&philo->m_id, &philo->eat_count, philo->eat_count + 1);
	if (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		ft_msleep(philo->time_to_eat);
	set_mutex_bool(philo->m_right_fork, philo->right_fork, false);
	set_mutex_bool(&philo->m_left_fork, &philo->left_fork, false);
	print_message("%zu %d is sleeping\n", philo);
	if (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		ft_msleep(philo->time_to_sleep);
	print_message("%zu %d is thinking\n", philo);
	usleep(200);
}

void	*even_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	while (!get_mutex_bool(&philo->data->m_data, &philo->data->ready))
	{
		usleep(10);
		set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	}
	set_mutex_size_t(&philo->m_id, &philo->last_eat, get_time());
	print_message("%zu %d is thinking\n", philo);
	while (!get_mutex_bool(&philo->data->m_data, &philo->data->is_dead))
		even_while_routine(philo);
	return (0);
}
