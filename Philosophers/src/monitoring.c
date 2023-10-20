/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:06:37 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:19:57 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_init_monitoring(t_philo *philo)
{
	pthread_t	monitoring;

	pthread_create(&monitoring, NULL, ft_monitoring_routine, philo);
	pthread_join(monitoring, NULL);
}

bool	ft_update(t_philo *philo, long long unsigned update, long long unsigned death_time)
{
	if (update > death_time)
	{
		ft_print_info(philo, "\033[0;41mHas died!\033[0m");
		pthread_mutex_lock(philo->mutex->death);
		*philo->death_check = true;
		pthread_mutex_unlock(philo->mutex->death);
		return (true);
	}
	return (false);
}

void	*ft_monitoring_routine(void *arg)
{
	int						i;
	long long unsigned		death_time;
	long long unsigned		update;
	t_philo					*philo;

	i = 0;
	philo = (t_philo *)arg;
	death_time = philo->data->time_to_die / 1000;
	while (1) 
	{
		if (i == philo->data->n_philo)
			i = 0;
		pthread_mutex_lock(philo[i].mutex->meal);
		update = ft_timer(philo[i].last_meal, philo[i].mutex->timer);
		pthread_mutex_unlock(philo[i].mutex->meal);
		if (ft_update(&philo[i], update, death_time) == true)
			break ;
		if (philo->data->bonus_arg == true && \
			ft_eat_amount_check(philo) == true)
			break ;
		i++;
	}
	return (NULL);
}
