/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessemna <yessemna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:42:40 by yessemna          #+#    #+#             */
/*   Updated: 2024/06/22 22:03:12 by yessemna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int is_digit(char c)
// {
// 	return (c >= '0' && c <= '9');
// }
// const char *is_valid(const char *str)
// {
// 	const char *num;
// 	int len;
// 	len = 0;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '+')
// 		str++;
// 	else if (*str == '-')
// 		error("Error: number must be positive");
// 	if (!is_digit(*str))
// 		error("Error: Invalid argument");
// 	num = str;
// 	while (is_digit(*str++))
// 		len++;
// 	if (len > 10)
// 		error("Error: number is too big");
// 	return (num);
// }
// int ft_atol(const char *str)
// {
// 	long num;
// 	num = 0;
// 	str = is_valid(str);
// 	while (is_digit(*str))
// 		num = num * 10 + (*str++ - '0');
// 	if (num > INT_MAX)
// 		error("Error: number is too big");
// 	return (num);
// }
int	parsing(char *av[])
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}
