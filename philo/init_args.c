/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:26:46 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/25 21:34:42 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current;
	long			time;

	if (gettimeofday(&current, NULL) == -1)
		return (0);
	time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

t_phil	*init_args(char **av, int ac)
{
	t_phil	*info;

	info = malloc(sizeof (t_phil));
	if (ac == 5)
		info->meals_num = -2;
	if (ac == 6)
		info->meals_num = ft_atoi(av[5]);
	info->start = get_time();
	info->n_philo = ft_atoi(av[1]);
	info->t_t_d = ft_atoi(av[2]);
	info->t_t_e = ft_atoi(av[3]);
	info->t_t_s = ft_atoi(av[4]);
	info->last_meal = 0;
	pthread_mutex_init(&info->lock, NULL);
	pthread_mutex_init(&info->lock_eat, NULL);
	pthread_mutex_init(&info->lock_write, NULL);
	pthread_mutex_init(&info->lock_calc, NULL);
	pthread_mutex_init(&info->lock_death, NULL);
	return (info);
}
