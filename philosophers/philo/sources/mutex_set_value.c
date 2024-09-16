/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_set_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:39:16 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/08 15:44:28 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/philo.h"

void	set_mutex_bool(pthread_mutex_t *mutex, bool *value, bool n_value)
{
	pthread_mutex_lock(mutex);
	*value = n_value;
	pthread_mutex_unlock(mutex);
}

void	set_mutex_int(pthread_mutex_t *mutex, int *value, int n_value)
{
	pthread_mutex_lock(mutex);
	*value = n_value;
	pthread_mutex_unlock(mutex);
}

void	set_mutex_size_t(pthread_mutex_t *mutex, size_t *value, size_t n_value)
{
	pthread_mutex_lock(mutex);
	*value = n_value;
	pthread_mutex_unlock(mutex);
}
