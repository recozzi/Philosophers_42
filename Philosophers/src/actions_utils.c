/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:16:28 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/24 15:00:06 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_bonus_arg(t_philo *philo)
{
	if (philo->data->bonus_arg == true)
	{
		pthread_mutex_lock(philo->mutex->eat_check);
		philo->eat_amount--;
		if (philo->eat_amount == 0)
		{
			ft_print_info(philo, "\033[0;45mIs full!\033[0m");
			pthread_mutex_unlock(philo->mutex->eat_check);
			return (1);
		}
		pthread_mutex_unlock(philo->mutex->eat_check);
	}
	return (0);
}

void	ft_correct_order(t_philo *philo)
{
	if (philo->right_fork > philo->left_fork)
	{
		pthread_mutex_lock(&philo->data->arr_forks[philo->left_fork]);
		ft_print_info(philo, "Has taken left fork");
		pthread_mutex_lock(&philo->data->arr_forks[philo->right_fork]);
		ft_print_info(philo, "Has taken right fork");
	}
	else if (philo->left_fork > philo->right_fork)
	{
		pthread_mutex_lock(&philo->data->arr_forks[philo->right_fork]);
		ft_print_info(philo, "Has taken right fork");
		pthread_mutex_lock(&philo->data->arr_forks[philo->left_fork]);
		ft_print_info(philo, "Has taken left fork");
	}
}

bool	ft_death_check(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex->death);
	if (*(philo->death_check) == false)
	{
		pthread_mutex_unlock(philo->mutex->death);
		return (false);
	}
	pthread_mutex_unlock(philo->mutex->death);
	return (true);
}

bool	ft_eat_amount_check(t_philo *philo)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	pthread_mutex_lock(philo->mutex->eat_check);
	while (i < philo->data->n_philo)
	{
		if (philo[i].eat_amount == 0)
			check++;
		if (check == philo->data->n_philo)
		{
			pthread_mutex_unlock(philo->mutex->eat_check);
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(philo->mutex->eat_check);
	return (false);
}
