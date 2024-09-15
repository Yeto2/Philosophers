/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:48:45 by yessemna          #+#    #+#             */
/*   Updated: 2024/09/13 23:49:11 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*g_malloc(size_t size, t_call call)
{
	static t_col	*head;
	t_col			*tmp;
	void			*ptr;

	if (call == MALLOC)
	{
		ptr = malloc(size);
		if (!ptr)
			return (clear_all(&head), NULL);
		tmp = new_node(ptr);
		if (!tmp)
			return (clear_all(&head), free(ptr), NULL);
		add_back(&head, tmp);
		return (ptr);
	}
	else if (call == FREE)
		clear_all(&head);
	return (NULL);
}
