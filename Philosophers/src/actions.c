/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:43:26 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/24 15:05:24 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_eat(t_philo *philo)
{
	ft_correct_order(philo);
	if (philo->left_fork == philo->right_fork)
	{
		pthread_mutex_lock(&philo->data->arr_forks[philo->right_fork]);
		ft_print_info(philo, "Has taken right fork");
		pthread_mutex_unlock(&philo->data->arr_forks[philo->right_fork]);
		return (1);
	}
	ft_print_info(philo, "\033[0;32mIs eating...\033[0m");
	pthread_mutex_lock(philo->mutex->meal);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(philo->mutex->meal);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->data->arr_forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->arr_forks[philo->right_fork]);
	if (ft_bonus_arg(philo) == 1)
		return (1);
	return (0);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_info(philo, "\033[94mIs sleeping...\033[0m");
	usleep(philo->data->time_to_sleep);
	ft_print_info(philo, "\033[33mIs thinking...\033[0m");
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (ft_death_check(philo) == false)
	{
		if (ft_eat(philo) == 1)
			break ;
		usleep(500);
		ft_sleep(philo);
	}
	return (NULL);
}
