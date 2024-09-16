/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhumeau <bhumeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:49:45 by bhumeau           #+#    #+#             */
/*   Updated: 2024/07/16 11:51:01 by bhumeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include "error_messages.h"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	m_id;
	pthread_mutex_t	m_left_fork;
	bool			left_fork;
	pthread_mutex_t	*m_right_fork;
	bool			*right_fork;
	int				eat_count;
	int				number_of_philosophers;
	size_t			last_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				number_of_philosophers;
	int				must_eat_nbr;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	bool			is_dead;
	bool			ready;
	int				nb_have_eaten;
	pthread_mutex_t	m_data;
	pthread_mutex_t	m_ready;
	pthread_mutex_t	m_print;
}	t_data;

int		ft_atoi(const char *nptr);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
bool	initialize_struct(t_data *data, int argc, char **argv);
void	initialize_philos(t_data *data);
void	initialize_basic_values(t_data *data, t_philo *philo, int i);
size_t	get_time(void);
void	*odd_routine(void *arg);
void	*even_routine(void *arg);
void	observer_routine(t_data *data, int nb_philos);
void	ft_msleep(size_t time);
void	ft_msleep_died(size_t time, t_data *data);
void	print_message(char *message, t_philo *philo);

bool	get_mutex_bool(pthread_mutex_t *mutex, bool *value);
int		get_mutex_int(pthread_mutex_t *mutex, int *value);
size_t	get_mutex_size_t(pthread_mutex_t *mutex, size_t *value);

void	set_mutex_bool(pthread_mutex_t *mutex, bool *value, bool n_value);
void	set_mutex_int(pthread_mutex_t *mutex, int *value, int n_value);
void	set_mutex_size_t(pthread_mutex_t *mutex, size_t *value, size_t n_value);

#endif