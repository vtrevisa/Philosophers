/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:49:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:33:05 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	update_simulation(t_data *data)
{
	if (simulation_status(data) != 0)
	{
		pthread_mutex_lock(&(data->lock_data));
		data->simulation--;
		pthread_mutex_unlock(&(data->lock_data));
	}
}

int	simulation_status(t_data *data)
{
	int	simulation;

	pthread_mutex_lock(&(data->lock_data));
	simulation = data->simulation;
	pthread_mutex_unlock(&(data->lock_data));
	return (simulation);
}

static void	rip(int nbr, t_data *data)
{
	long long	time;

	time = time_now() - data->starting_time;
	pthread_mutex_lock(&(data->lock_print));
	printf("%-5lld %i %s\n", time, nbr, "died");
	pthread_mutex_unlock(&(data->lock_print));
}

void	manager(t_args *args, t_data *data)
{
	int			i;
	long long	time;

	while (simulation_status(data) != 0)
	{
		i = -1;
		while (++i < data->nbr_philos)
		{
			if (simulation_status(data) == 0)
				break ;
			pthread_mutex_lock(&(args[i].philo_m));
			time = time_now() - args[i].last_meal;
			if (time >= data->time.die)
			{
				pthread_mutex_lock(&(data->lock_data));
				data->simulation = 0;
				pthread_mutex_unlock(&(data->lock_data));
				rip(args->nbr, data);
			}
			usleep (100);
			pthread_mutex_unlock(&(args[i].philo_m));
		}
		usleep(100);
	}
}
