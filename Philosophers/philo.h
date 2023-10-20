/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:46:23 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/27 09:17:32 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>

typedef struct s_data
{
	int				n_philo;
	int				time_to_eat;
	bool			bonus_arg;
	int				time_to_sleep;
	int				time_to_die;
	pthread_mutex_t	*arr_forks;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*death;
	pthread_mutex_t	*eat_check;
	pthread_mutex_t	*print;
	pthread_mutex_t	*timer;
	pthread_mutex_t	*meal;
}	t_mutex;

typedef struct s_philo
{
	pthread_t			thread;
	t_data				*data;
	t_mutex				*mutex;
	int					id;
	int					left_fork;
	int					right_fork;
	int					eat_amount;
	long long unsigned	last_meal;
	long long unsigned	start_threads;
	bool				*death_check;
}	t_philo;

int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
int					ft_check_args(int argc, char **argv);
int					ft_strerror(char *str, int err);
int					ft_eat(t_philo *philo);
int					ft_bonus_arg(t_philo *philo);

void				*ft_calloc(size_t nmemb, size_t size);
void				ft_init_threads(t_philo *philo);
void				*ft_routine(void *arg);
void				ft_sleep(t_philo *philo);
void				*ft_monitoring_routine(void *arg);
void				ft_print_info(t_philo *philo, char *str);
void				ft_init_monitoring(t_philo *philo);
void				ft_correct_order(t_philo *philo);
void				ft_destroy_and_free(t_philo *philo);

t_data				*ft_init_data(int argc, char **argv);

t_philo				*ft_init_forks(t_data *data, t_mutex *mutex, char **argv);

t_mutex				*ft_init_mutex(t_mutex *mutex);

bool				ft_eat_amount_check(t_philo *philo);
bool				ft_death_check(t_philo *philo);
bool				ft_update(t_philo *philo, long long unsigned update, long long unsigned death_time);

long long unsigned	ft_get_time(void);
long long unsigned	ft_timer(long long unsigned start_threads, pthread_mutex_t *timer);

#endif
