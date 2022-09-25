/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:05:19 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/22 00:11:14 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	enough_meals(t_thread *tmp)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i++ <= tmp->info->n_philo)
	{
		pthread_mutex_lock(&tmp->info->lock_death);
		if (tmp->info->meals_num == tmp->info->meals)
			count++;
		pthread_mutex_unlock(&tmp->info->lock_death);
		tmp = tmp->next;
	}
	if (count == tmp->info->n_philo)
		return (0);
	return (1);
}

int	is_died(t_thread *tmp)
{
	long		time;
	int			i;

	i = 1;
	while (i++ <= tmp->info->n_philo)
	{
		time = get_time() - tmp->info->start;
		pthread_mutex_lock(&tmp->info->lock);
		if (time >= (tmp->info->last_meal + tmp->info->t_t_d))
		{
			pthread_mutex_lock(&tmp->info->lock_write);
			printf("%ld philo %d has died\n",
				get_time() - tmp->info->start, tmp->data);
			return (0);
		}
		else
			pthread_mutex_unlock(&tmp->info->lock);
		tmp = tmp->next;
	}
	return (1);
}

void	print_status(char *str, t_thread *tmp)
{
	long	time;

	time = get_time() - tmp->info->start;
	if ((time >= tmp->info->last_meal + tmp->info->t_t_d))
	{
		pthread_mutex_lock(&tmp->info->lock_write);
		return ;
	}
	pthread_mutex_lock(&tmp->info->lock_write);
	printf("%ld philo %d %s\n",
		get_time() - tmp->info->start, tmp->data, str);
	pthread_mutex_unlock(&tmp->info->lock_write);
}

void	*routine(void *head)
{
	t_thread	*tmp;

	tmp = (t_thread *)head;
	while (1)
	{
		pthread_mutex_lock(&tmp->mutex);
		print_status("has taken a fork", tmp);
		pthread_mutex_lock(&tmp->next->mutex);
		print_status("has taken a fork", tmp);
		calcul_time(tmp);
		print_status("is eating", tmp);
		ft_sleep(tmp->info->t_t_e);
		if (tmp->info->meals_num != -2)
			calcul_meals(tmp);
		pthread_mutex_unlock(&tmp->mutex);
		pthread_mutex_unlock(&tmp->next->mutex);
		usleep(1 * 1000);
		print_status("is sleeping", tmp);
		ft_sleep(tmp->info->t_t_s);
		print_status("is thinking", tmp);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_thread	*head;

	if (ac == 6 || ac == 5)
	{
		if (!check_args(av))
		{
			printf("Error\n");
			return (0);
		}
		if (av[5] && ft_atoi(av[5]) == 0)
			return (0);
		create_list_t(&head, av, ac);
		create_mutexes(head);
		create_philos(head);
		while (is_died(head) && enough_meals(head))
			;
		destroy_mutexes(head);
	}
}
