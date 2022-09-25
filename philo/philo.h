/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:11:36 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/25 21:33:01 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct phil
{
	int				n_philo;
	int				t_t_d;
	int				t_t_e;
	int				t_t_s;
	long			start;
	long			last_meal;
	int				meals;
	int				meals_num;
	pthread_mutex_t	lock_eat;
	pthread_mutex_t	lock_write;
	pthread_mutex_t	lock;
	pthread_mutex_t	lock_calc;
	pthread_mutex_t	lock_death;
}	t_phil;

typedef struct t_thread
{
	int				data;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	t_phil			*info;
	struct t_thread	*next;
}	t_thread;

long		get_time(void);
t_phil		*init_args(char **av, int ac);
int			check_args(char **str);
int			check_digits(char *str);
void		create_list_t(t_thread **head, char **av, int ac);
t_thread	*creat_node(int n_philo, char **av, int ac);
void		create_list(t_thread **head, int n_philo, char **av, int ac);
int			ft_atoi(char *str);
void		print_status(char *str, t_thread *tmp);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		calcul_time(t_thread *tmp);
void		calcul_meals(t_thread *tmp);
void		ft_sleep(long slp_time);
void		create_list_t(t_thread **head, char **av, int ac);
void		create_mutexes(t_thread *head);
void		create_philos(t_thread *head);
void		destroy_mutexes(t_thread *head);
void		*routine(void *head);

#endif