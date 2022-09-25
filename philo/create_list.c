/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:04:58 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/25 21:34:57 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_thread	*creat_node(int n_philo, char **av, int ac)
{
	t_thread	*node;

	node = (t_thread *)malloc(sizeof(t_thread));
	if (!node)
		return (NULL);
	node->data = n_philo;
	node->info = init_args(av, ac);
	node->next = NULL;
	return (node);
}

void	create_list(t_thread **head, int n_philo, char **av, int ac)
{
	t_thread	*node;
	t_thread	*tmp;

	tmp = *head;
	node = creat_node(n_philo, av, ac);
	if (*head == NULL)
	{
		node->next = *head;
		*head = node;
		(*head)->next = (*head);
		return ;
	}
	while (tmp->next != *head)
		tmp = tmp->next;
	tmp->next = node;
	node->next = *head;
}

void	create_list_t(t_thread **head, char **av, int ac)
{
	int	i;

	i = 1;
	while (i <= ft_atoi(av[1]))
		create_list(head, i++, av, ac);
}
