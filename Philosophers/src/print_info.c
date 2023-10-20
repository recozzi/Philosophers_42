/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:34:52 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:19:43 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print_info(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->mutex->print);
	if (ft_death_check(philo) == false)
		printf("%llu %d %s\n", ft_timer(philo->start_threads, philo->mutex->timer), philo->id, str);
	pthread_mutex_unlock(philo->mutex->print);
}
