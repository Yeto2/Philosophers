/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:40:05 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/26 21:14:33 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_philos(t_monitor *mtr)
{
	int	i;

	i = 0;
	while (i < mtr->philo_num)
	{
		if (mtr->philo[i])
		{
			pthread_mutex_destroy(&mtr->philo[i]->meal_mutex);
			free(mtr->philo[i]);
		}
		i++;
	}
	free(mtr->philo);
}

void	destroy_mutex(t_monitor *mtr)
{
	pthread_mutex_destroy(&mtr->print_mutex);
	pthread_mutex_destroy(&mtr->num_eat_mutex);
}

void	free_monitor(t_monitor *mtr)
{
	int	i;

	if (mtr)
	{
		if (mtr->philo)
			free_philos(mtr);
		if (mtr->forks)
		{
			i = 0;
			while (i < mtr->philo_num)
				pthread_mutex_destroy(&mtr->forks[i++]);
			free(mtr->forks);
		}
		destroy_mutex(mtr);
		free(mtr);
	}
}
