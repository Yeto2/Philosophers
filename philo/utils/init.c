/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:56:28 by yessemna          #+#    #+#             */
/*   Updated: 2024/09/14 00:11:08 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_philo(t_monitor **mtr)
{
	int	i;

	i = 0;
	while (i < (*mtr)->philo_num)
	{
		if (pthread_create(&(*mtr)->philo[i]->th,
				NULL, &routine, (*mtr)->philo[i]))
			return (-1);
		i++;
	}
	if (pthread_create(&(*mtr)->thread_monitor,
			NULL, &monitoring, (*mtr)))
		return (-1);
	return (0);
}

int	init_monitor(t_monitor **mtr, char **av)
{
	int	philo_num;

	(*mtr) = g_malloc(sizeof(t_monitor), MALLOC);
	if (!mtr)
		return (-1);
	philo_num = ft_atoi(av[1]);
	(*mtr)->philo = g_malloc(sizeof(t_philo *) * philo_num, MALLOC);
	if (!(*mtr)->philo)
		return (-1);
	(*mtr)->philo_num = philo_num;
	(*mtr)->forks = g_malloc(sizeof(pthread_mutex_t) * philo_num, MALLOC);
	if (!(*mtr)->forks)
		return (-1);
	(*mtr)->isdead = 0;
	return (0);
}

int	init_mutexes(t_monitor **mtr)
{
	int	i;

	i = 0;
	while (i < (*mtr)->philo_num)
	{
		if (pthread_mutex_init(&(*mtr)->forks[i++], NULL))
			return (-1);
	}
	if (pthread_mutex_init(&(*mtr)->print_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*mtr)->last_meal_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*mtr)->num_eat_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&(*mtr)->died_mutex, NULL))
		return (-1);
	return (0);
}

t_philo	*setup_philo(t_philo *philo, char **av)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (NULL);
	philo = g_malloc(sizeof(t_philo), MALLOC);
	if (!philo)
		return (NULL);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	philo->last_meal = philo->start;
	if (av[5])
		philo->num_eat = ft_atoi(av[5]);
	else
		philo->num_eat = -1;
	if (pthread_mutex_init(&philo->meal_mutex, NULL))
		return (NULL);
	return (philo);
}

int	init_philos(t_monitor **mtr, char **av)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < (*mtr)->philo_num)
	{
		philo = setup_philo((*mtr)->philo[i], av);
		if (!philo)
			return (-1);
		(*mtr)->philo[i] = philo;
		(*mtr)->philo[i]->id = i + 1;
		(*mtr)->philo[i]->mtr = (*mtr);
		i++;
	}
	return (0);
}
