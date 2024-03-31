/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:32:19 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/31 00:42:17 by yessemna         ###   ########.fr       */
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
int main(int ac, char const *av[])
{
	t_data data;
	
    if (ac == 5 || ac == 6)
    {
			parsing(&data, av);
    }else
        error("Error: Wrong number of arguments");
    return 0;
}
