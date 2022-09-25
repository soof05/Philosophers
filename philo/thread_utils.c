/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:06:55 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/24 12:00:14 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_thread *head)
{
	t_thread	*tmp;
	int			i;

	tmp = head;
	i = tmp->info->n_philo;
	while (i)
	{
		pthread_create(&tmp->thread, NULL, &routine, (void *)tmp);
		usleep(100);
		tmp = tmp->next;
		i--;
	}
}

void	create_mutexes(t_thread *head)
{
	t_thread	*tmp;
	int			i;

	tmp = head;
	i = tmp->info->n_philo;
	while (i)
	{
		pthread_mutex_init(&tmp->mutex, NULL);
		tmp = tmp->next;
		i--;
	}
}

void	destroy_mutexes(t_thread *head)
{
	t_thread	*tmp;
	int			i;

	tmp = head;
	i = tmp->info->n_philo;
	while (i)
	{
		pthread_mutex_destroy(&tmp->mutex);
		tmp = tmp->next;
		i--;
	}
}
