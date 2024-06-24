/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:07 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/24 18:41:35 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *routine(void *arg)
{
	t_philo	*philo;
	int		philo_num;
	
	philo = (t_philo *)arg;
	philo_num = philo->mtr->philo_num;
	
	if(philo_num == 1)
		handle_one_philo(philo);
	if(philo->id  % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		if(is_full(philo->mtr))
			break;
		pthread_mutex_lock(&philo->mtr->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->mtr->forks[philo->id % philo_num]);
		ft_status(philo, "has taken a fork");
		ft_status(philo, "has taken a fork");
		ft_eat(philo);
		pthread_mutex_unlock(&philo->mtr->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->mtr->forks[philo->id % philo_num]);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}

void *monitoring(void *arg)
{

}