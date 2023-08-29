/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:29:05 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:27:18 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	wait(int time_wait, long long start)
{
	long long	time;

	usleep(time_wait * 0.9 * 1000);
	time = time_now() - start;
	while (time < time_wait)
	{
		usleep(100);
		time = time_now() - start;
	}
}

void	wait2(int time_wait, long long start)
{
	long long	time;

	time = time_now() - start;
	if (time_wait - time > 2)
	{
		usleep((time_wait - time) * 1000 * 0.9);
		time = time_now() - start;
	}
	while (time < time_wait)
	{
		usleep(100);
		time = time_now() - start;
	}
}
