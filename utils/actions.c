/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:42:11 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/26 21:14:45 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->mtr->print_mutex);
	printf("%ld %d %s \n",
		ft_get_current_time() - philo->start, philo->id, status);
	pthread_mutex_unlock(&philo->mtr->print_mutex);
}

void	ft_eat(t_philo *philo)
{
	long	cur_time;

	cur_time = ft_get_current_time();
	ft_status(philo, "is_eating");
	pthread_mutex_lock(&philo->mtr->last_meal_mutex);
	philo->last_meal = cur_time;
	pthread_mutex_unlock(&philo->mtr->last_meal_mutex);
	pthread_mutex_lock(&philo->mtr->num_eat_mutex);
	if (philo->num_eat > 0)
		philo->num_eat--;
	pthread_mutex_unlock(&philo->mtr->num_eat_mutex);
	ft_usleep(philo->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	ft_status(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_status(philo, "is thinking");
}
