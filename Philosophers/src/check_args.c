/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:46:25 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/26 16:05:50 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc && argv[i])
	{
		if (ft_atoi(argv[1]) == 0)
			return (ft_strerror("Hey, there's no philo!", 2));
		if (ft_atoi(argv[1]) > 200)
			return (ft_strerror("Too many philosophers", 3));
		if (ft_atoi(argv[i]) < 0)
			return (ft_strerror("Not negative numbers", 4));
		if (i == 5 && ft_atoi(argv[i]) == 0)
			return (ft_strerror("Philos are full", 4));
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (ft_strerror("Only numbers", 5));
			j++;
		}
		i++;
	}
	return (0);
}
