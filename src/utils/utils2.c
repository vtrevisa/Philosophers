/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 10:17:22 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:13:31 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long int	ft_atoli(const char *str)
{
	int			index;
	int			if_neg;
	long int	result;

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
