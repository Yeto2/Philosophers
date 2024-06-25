/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:07 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/25 01:28:49 by yessemna         ###   ########.fr       */
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
		return(handle_one_philo(philo), NULL);
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
	return (NULL);
}
void check_philo_isdead(t_monitor *mtr, int *is_dead)
{
	int i;

	i = 0;
	while (i < mtr->philo_num)
	{
		pthread_mutex_lock(&mtr->last_meal_mutex);
		if((ft_get_current_time() - mtr->philo[i]->last_meal) > mtr->philo[i]->time_to_die)
		{
			pthread_mutex_lock(&mtr->print_mutex);
			*is_dead = 1;
			printf("%ld %d is died",
				ft_get_current_time() - mtr->philo[i]->start, mtr->philo[i]->id);
			pthread_mutex_unlock(&mtr->print_mutex);
			pthread_mutex_unlock(&mtr->last_meal_mutex);
			break;
		}
		pthread_mutex_unlock(&mtr->last_meal_mutex);
		i++;
	}
}
void *monitoring(void *arg)
{
	t_monitor *mtr;
	int is_dead;

	is_dead = 0;
	mtr = (t_monitor *)arg;
	if(mtr->philo_num == 1)
		return (NULL);
	while (1)
	{
		if(is_full(mtr))
			break;
		check_philo_isdead(mtr, &is_dead);
		if(is_dead)
			break ;
		ft_usleep(1);
	}
	return (NULL);
}