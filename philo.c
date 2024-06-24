/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:32:19 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/24 18:35:58 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
			5 800 200 200 7
			
			1   2  3   4  5
				
			->  5 — The number of philosophers
			->  800 — The time a philosopher will die if he doesn’t eat
			->  200 — The time it takes a philosopher to eat
			->  200 — The time it takes a philosopher to sleep
			->  7 — Number of times all the philosophers need to eat before terminating the program **
*/

int is_full(t_monitor *mtr)
{
	int i;

	i = 0;
	
	while (i < mtr->philo_num)
	{
		pthread_mutex_lock(&mtr->num_eat_mutex);
		if (mtr->philo[i]->num_eat != 0)
		{
			pthread_mutex_unlock(&mtr->num_eat_mutex);
			return (0);
		}
		pthread_mutex_unlock(&mtr->num_eat_mutex);
		i++;
	}
	return (1);
}

void handle_one_philo(t_philo *philo)
{
	printf("%ld %d has taken a fork\n",
		ft_get_current_time() - philo->start, philo->id);
	ft_usleep(philo->time_to_die);
	printf("%ld %d died\n",
		ft_get_current_time() - philo->start, philo->id);
}

int join_threads(t_monitor **mtr)
{
	int i;

	i = 0;
	if ((*mtr)->philo_num == 1)
	{
		if(pthread_join((*mtr)->philo[i]->th,NULL))
			return (-1);
	}
	else
	{
		while (i < (*mtr)->philo_num)
		{
			if(pthread_join((*mtr)->philo[i]->th,NULL))
				return (-1);
			i++;
		}
	}
	if(pthread_join((*mtr)->thread_monitor,NULL))
			return (-1);
	return (0);
}

int main(int ac, char *av[])
{
	t_monitor *mtr;
	
	(void)mtr;
    if (ac == 5 || ac == 6)
    {
		// Parssing
		if (parsing(av))
			return(ft_putstr_fd("invalid arguments", 2), 1);
		if (ft_atoi(av[1] ) > 200)
			return(ft_putstr_fd("invalid arguments", 2), 1);
		if (init_monitor(&mtr, av))
			return(ft_putstr_fd("invalid arguments", 2), 1);
		if (init_mutexes(&mtr))
			return(ft_putstr_fd("invalid arguments", 2), 1);
		if (init_philos(&mtr, av))
			return(ft_putstr_fd("invalid arguments", 2), 1);
		
		create_philo(&mtr);
		join_threads(&mtr);
    }else
        return(ft_putstr_fd("invalid arguments", 2), 1);
    return 0;
}
