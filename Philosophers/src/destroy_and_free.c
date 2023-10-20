/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 18:24:52 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/26 15:47:57 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destroy_and_free(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->n_philo)
		pthread_mutex_destroy(&philo->data->arr_forks[i]);
	pthread_mutex_destroy(philo->mutex->death);
	pthread_mutex_destroy(philo->mutex->eat_check);
	pthread_mutex_destroy(philo->mutex->meal);
	pthread_mutex_destroy(philo->mutex->print);
	pthread_mutex_destroy(philo->mutex->timer);
	free(philo->data->arr_forks);
	free(philo->mutex->death);
	free(philo->mutex->eat_check);
	free(philo->mutex->meal);
	free(philo->mutex->print);
	free(philo->mutex->timer);
	free(philo->mutex);
	free(philo->data);
	free(philo->death_check);
	free(philo);
}
