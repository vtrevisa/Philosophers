/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:32:58 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/04 15:31:12 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	if_neg;
	int	result;

	index = 0;
	if_neg = 1;
	result = 0;
	while ((str[index] >= '\t' && str[index] <= '\r') || (str[index] == ' '))
	{
		index++;
	}
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
		{
			if_neg *= -1;
		}
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	return (result * if_neg);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (2048);
	}
	else
		return (0);
}

int	is_all_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	print_action(long long time, int philo, char *action, t_data *data)
{
	pthread_mutex_lock(&(data->lock_print));
	printf("%-5lld %i %s\n", time, philo, action);
	pthread_mutex_unlock(&(data->lock_print));
}