/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 00:07:20 by yessemna          #+#    #+#             */
/*   Updated: 2024/04/01 00:07:59 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// need to check -----------
void	handle_threads(pthread_t *thread, void *(*func)(void *), void *data, t_state state) 
{
	if (CREATE == state)
	{
		if (pthread_create(thread, NULL, func, data) != 0)
			error("Error: thread creation failed");
	}else if (JOIN == state)
	{
		if (pthread_join(*thread, NULL) != 0)
			error("Error: thread join failed");
	}else
		error("Error: Wrong thread operation");
}
// ---------------------------

void	handle_mutex(pthread_mutex_t *mutex, t_state state)
{
	if (INIT == state)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			error("Error: mutex init failed");
	}else if (DESTROY == state)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			error("Error: mutex destroy failed");
	}else if (LOCK == state)
	{
		if (pthread_mutex_lock(mutex) != 0)
			error("Error: mutex lock failed");
	}else if (UNLOCK == state)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			error("Error: mutex unlock failed");
	}else
		error("Error: Wrong mutex operation");
}
void	*allocate(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if(!ret)
		error("Error: malloc failed");
	return (ret);
}