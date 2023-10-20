/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:30:56 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/24 15:07:14 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	t_mutex	*mutex;

	data = NULL;
	philo = NULL;
	mutex = NULL;
	if (argc < 5 || argc > 6)
		return (ft_strerror("Invalid arguments", 1));
	if (ft_check_args(argc, argv) == 0)
	{
		data = ft_init_data(argc, argv);
		mutex = ft_init_mutex(mutex);
		philo = ft_init_forks(data, mutex, argv);
		ft_init_threads(philo);
		ft_destroy_and_free(philo);
	}
	return (0);
}
