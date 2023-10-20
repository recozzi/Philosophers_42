/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 15:23:26 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:18:37 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long unsigned	ft_timer(long long unsigned start_threads, pthread_mutex_t *timer)
{
	long long unsigned	updated_time;
	struct timeval		time;

	pthread_mutex_lock(timer);
	gettimeofday(&time, NULL);
	updated_time = ((long long unsigned)time.tv_sec * 1000 + (long long unsigned)time.tv_usec / 1000) - start_threads;
	pthread_mutex_unlock(timer);
	return (updated_time); 
}

long long unsigned	ft_get_time(void)
{
	struct timeval	time;
	time_t			t_sec;
	time_t			t_microsec;

	gettimeofday(&time, NULL);
	t_sec = time.tv_sec * 1000;
	t_microsec = time.tv_usec / 1000;
	return ((long long unsigned)t_sec + (long long unsigned)t_microsec);
}
