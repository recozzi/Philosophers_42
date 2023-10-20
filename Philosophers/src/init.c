/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:52:12 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:21:42 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		philo[i].start_threads = ft_get_time();
		philo[i].last_meal = philo[i].start_threads;
		pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		i++;
	}
	ft_init_monitoring(philo);
	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

t_philo	*ft_init_forks(t_data *data, t_mutex *mutex, char **argv)
{
	bool	*death_check;
	t_philo	*philo;
	int		i;

	philo = ft_calloc(data->n_philo, sizeof(t_philo));
	death_check = malloc(sizeof(bool));
	*death_check = false;
	i = -1;
	while (++i < data->n_philo)
		pthread_mutex_init(&data->arr_forks[i], NULL);
	i = -1;
	while (++i < data->n_philo)
	{
		philo[i].right_fork = i;
		if (i == data->n_philo - 1)
			philo[i].left_fork = 0;
		else
			philo[i].left_fork = i + 1;
		philo[i].id = i;
		philo[i].data = data;
		philo[i].mutex = mutex;
		philo[i].death_check = death_check;
		if (data->bonus_arg == true)
			philo[i].eat_amount = ft_atoi(argv[5]);
	}
	return (philo);
}

t_mutex	*ft_init_mutex(t_mutex *mutex)
{
	mutex = ft_calloc(1, sizeof(t_mutex));
	mutex->death = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->print = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->timer = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->eat_check = ft_calloc(1, sizeof(pthread_mutex_t));
	mutex->meal = ft_calloc(1, sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex->death, NULL);
	pthread_mutex_init(mutex->print, NULL);
	pthread_mutex_init(mutex->timer, NULL);
	pthread_mutex_init(mutex->eat_check, NULL);
	pthread_mutex_init(mutex->meal, NULL);
	return (mutex);
}

t_data	*ft_init_data(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]) * 1000;
	data->time_to_eat = ft_atoi(argv[3]) * 1000;
	data->time_to_sleep = ft_atoi(argv[4]) * 1000;
	data->bonus_arg = false;
	if (argc == 6 && ft_atoi(argv[5]) > 0)
		data->bonus_arg = true;
	data->arr_forks = ft_calloc(data->n_philo, sizeof(pthread_mutex_t));
	return (data);
}
