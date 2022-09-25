/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:57:16 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/21 23:23:20 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	calcul_time(t_thread *tmp)
{
	pthread_mutex_lock(&tmp->info->lock);
	tmp->info->last_meal = get_time() - tmp->info->start;
	pthread_mutex_unlock(&tmp->info->lock);
}

void	calcul_meals(t_thread *tmp)
{
	pthread_mutex_lock(&tmp->info->lock_death);
	tmp->info->meals++;
	pthread_mutex_unlock(&tmp->info->lock_death);
}

void	ft_sleep(long slp_time)
{
	long	time;

	time = get_time();
	while (get_time() - time < slp_time)
		usleep(100);
}
