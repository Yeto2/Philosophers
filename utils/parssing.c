/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:42:40 by yessemna          #+#    #+#             */
/*   Updated: 2024/03/31 00:44:44 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
const char *is_valid(const char *str)
{
	const char *num;
	int len;
	len = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error("Error: number must be positive");
	if (!is_digit(*str))
		error("Error: Invalid argument");
	num = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		error("Error: number is too big");
	return (num);
}
int ft_atol(const char *str)
{
	long num;
	num = 0;
	str = is_valid(str);
	while (is_digit(*str))
		num = num * 10 + (*str++ - '0');
	if (num > INT_MAX)
		error("Error: number is too big");
	return (num);
}
void	parsing(t_data *data, char const *av[])
{
	data->philo_count = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1e3;
	data->time_to_eat = ft_atol(av[3]) * 1e3;
	data->time_to_sleep = ft_atol(av[4]) * 1e3;
	if (data->time_to_die < 6e4
		|| data->time_to_eat < 6e4
		|| data->time_to_sleep < 6e4)
		error("Error: timestamp must be greater than 60ms");
	if (av[5])
		data->must_eat_count = ft_atol(av[5]);
	else
		data->must_eat_count = -1;
	if (data->must_eat_count == 0)
		error("Error: Invalid argument");
}
