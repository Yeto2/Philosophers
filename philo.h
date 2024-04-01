/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 01:32:15 by yessemna          #+#    #+#             */
/*   Updated: 2024/04/01 00:50:11 by yessemna         ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct s_fork
{
    pthread_mutex_t	fork;
    int             fork_id;
}					t_fork;

typedef struct s_philo
{
    int         id;
    int         meals_count;
    bool        full;
    long		last_meal_time;
    t_fork      *left_fork;
    t_fork      *right_fork;
    pthread_t   thread_id;
    t_data      *data;
}					t_philo;

typedef struct s_data
{
    int				philo_count;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				must_eat_count;
    int				start_sim;
    bool				end_sim;
    t_fork          *forks;
    t_philo	        *philos;
}					t_data;

typedef enum e_mutex
{
    INIT,
    DESTROY,
    LOCK,
    UNLOCK,
    CREATE,
    JOIN
}   t_state;


void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	error(char *str);
void	parsing(t_data *data, char const *av[]);
// -->  init
void	init(t_data *data);
void	*allocate(size_t bytes);
void	handle_mutex(pthread_mutex_t *mutex, t_state state);
void	handle_threads(pthread_t *thread, void *(*func)(void *), void *data, t_state state);
// ----------


#endif