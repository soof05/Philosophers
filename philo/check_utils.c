/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-ouaf <sel-ouaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:11:55 by sel-ouaf          #+#    #+#             */
/*   Updated: 2022/09/25 21:45:05 by sel-ouaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	nbr;

	nbr = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = (nbr * 10) + *str - 48;
		str++;
	}
	return (nbr);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	if (!str[i])
		return (0);
	return (1);
}

int	check_args(char **str)
{
	int	j;

	j = 1;
	while (str[j])
	{
		if (check_digits(str[j]))
			j++;
		else
			return (0);
	}
	if (ft_atoi(str[1]) == 0)
		return (0);
	return (1);
}
