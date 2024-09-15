/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:33:07 by yessemna          #+#    #+#             */
/*   Updated: 2024/09/14 00:12:03 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	break_if_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtr->died_mutex);
	if (philo->mtr->isdead)
	{
		pthread_mutex_unlock(&philo->mtr->died_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->mtr->died_mutex);
	return (0);
}

void	routine_helper(void *arg, int philo_num)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->mtr->forks[philo->id - 1]);
	pthread_mutex_lock(&philo->mtr->forks[philo->id % philo_num]);
	ft_status(philo, "has taken a fork");
	ft_status(philo, "has taken a fork");
	ft_eat(philo);
	pthread_mutex_unlock(&philo->mtr->forks[philo->id - 1]);
	pthread_mutex_unlock(&philo->mtr->forks[philo->id % philo_num]);
	ft_sleep(philo);
	ft_think(philo);
	pthread_mutex_lock(&philo->mtr->num_eat_mutex);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		philo_num;

	((1) && (philo = arg, philo_num = philo->mtr->philo_num));
	if (philo_num == 1)
		return (handle_one_philo(philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->time_to_eat);
	while (1)
	{
		if (break_if_dead(philo))
			break ;
		if (is_full(philo->mtr))
			break ;
		routine_helper(arg, philo_num);
		if (philo->num_eat == 0)
		{
			pthread_mutex_unlock(&philo->mtr->num_eat_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->mtr->num_eat_mutex);
	}
	return (NULL);
}

void	check_philo_isdead(t_monitor **mtr)
{
	int	i;

	i = 0;
	while (++i < (*mtr)->philo_num)
	{
		pthread_mutex_lock(&(*mtr)->last_meal_mutex);
		pthread_mutex_lock(&(*mtr)->num_eat_mutex);
		if ((ft_get_current_time() - (*mtr)->philo[i]->last_meal)
			> (*mtr)->philo[i]->time_to_die && (*mtr)->philo[i]->num_eat != 0)
		{
			pthread_mutex_unlock(&(*mtr)->num_eat_mutex);
			pthread_mutex_lock(&(*mtr)->print_mutex);
			pthread_mutex_lock(&(*mtr)->died_mutex);
			(*mtr)->isdead = 1;
			pthread_mutex_unlock(&(*mtr)->died_mutex);
			printf("%ld %d is died\n",
				ft_get_current_time() - (*mtr)->philo[i]->start,
				(*mtr)->philo[i]->id);
			pthread_mutex_unlock(&(*mtr)->print_mutex);
			pthread_mutex_unlock(&(*mtr)->last_meal_mutex);
			break ;
		}
		pthread_mutex_unlock(&(*mtr)->num_eat_mutex);
		pthread_mutex_unlock(&(*mtr)->last_meal_mutex);
	}
}

void	*monitoring(void *arg)
{
	t_monitor	*mtr;

	mtr = (t_monitor *)arg;
	if (mtr->philo_num == 1)
		return (NULL);
	while (1)
	{
		if (is_full(mtr))
			break ;
		check_philo_isdead(&mtr);
		pthread_mutex_lock(&mtr->died_mutex);
		if (mtr->isdead)
		{
			pthread_mutex_unlock(&mtr->died_mutex);
			break ;
		}
		pthread_mutex_unlock(&mtr->died_mutex);
		ft_usleep(1);
	}
	return (NULL);
}
