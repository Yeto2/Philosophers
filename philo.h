/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:32:15 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/25 04:42:37 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <time.h>
# include <sys/time.h>

typedef struct s_monitor t_monitor;

typedef struct s_philo
{
	pthread_mutex_t	meal_mutex;
	pthread_t		th;
	int				id;
	long			start;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	size_t			last_meal;
	int				num_eat;
	t_monitor			*mtr;
	int				must_eat_count;
}					t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	print_mutex;

	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	num_eat_mutex;
	pthread_mutex_t	*forks;
	pthread_t		thread_monitor;
	t_philo			**philo;
	int				philo_num;
	int				stop_eat;
	int				nbr_each_philo;
	int				philo_ready;
}   				t_monitor; 


int		ft_atoi(const char *str);
int		parsing(char *av[]);
void	ft_putstr_fd(char *s, int fd);

// init
int		init_monitor(t_monitor **mtr, char **av);
int		init_mutexes(t_monitor **mtr);
int		init_philos(t_monitor **mtr, char **av);

// time
size_t	ft_get_current_time(void);
void	ft_usleep(size_t milliseconds);

// actions
void ft_eat(t_philo *philo);
void ft_sleep(t_philo *philo);
void ft_think(t_philo *philo);
void ft_status(t_philo *philo, char *status);
int create_philo(t_monitor **mtr);
void handle_one_philo(t_philo *philo);
int is_full(t_monitor *mtr);

// routine
void *routine(void *arg);
void *monitoring(void *arg);

// free
void free_monitor(t_monitor *mtr);

#endif