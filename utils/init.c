/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 23:56:28 by yessemna          #+#    #+#             */
/*   Updated: 2024/04/01 00:46:57 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void    assign_fork(t_philo *philo, t_fork *forks, int phoilo_pos)
{
    int philo_nbr;
    
    philo_nbr = philo->data->philo_count;

    philo->right_fork = &forks[((phoilo_pos + 1) % philo_nbr)];
    philo->left_fork = &forks[phoilo_pos];
    if (philo->id % 2 == 0)
    {
        philo->right_fork = &forks[phoilo_pos];
        philo->left_fork = &forks[((phoilo_pos + 1) % philo_nbr)];
    }
}

void    init_philo(t_data *data)
{
    int i;
    t_philo *philo;

    i = -1;
    while (++i < data->philo_count)
    {
        philo = data->philos + i;
        philo->id = i + 1;
        philo->full = false;
        philo->meals_count = 0;
        philo->data = data;
        assign_fork(philo, data->forks, i);
    }
    
}

void	init(t_data *data)
{
	int i;
	
	i = -1;

	data->end_sim = NULL;
	data->philos = allocate(sizeof(t_philo) * data->philo_count);
	data->forks = allocate(sizeof(t_fork) * data->philo_count);
	while (++i < data->philo_count)
	{
		handle_mutex(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
    init_philo(data);
}