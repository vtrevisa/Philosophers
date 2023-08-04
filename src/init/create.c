/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/03 16:24:18 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_fork	*create_forks(t_data *data)
{
	int	i;
	t_fork	*fork;

	i = -1;
	fork = malloc (sizeof(t_fork) * data->nbr_philos);
	while (++i < data->nbr_philos)
	{
		fork[i].free = 1;
		pthread_mutex_init(&(fork[i].mutex), NULL);
	}
	return (fork);
}

t_args	*create_args(t_data *data, t_fork *fork)
{
	t_args	*args;
	int		i;

	args = malloc (sizeof(t_args) * data->nbr_philos);
	i = -1;
	while (++i < data->nbr_philos)
	{
		args[i].nbr = i + 1;
		args[i].must_eat = 0;
		args[i].last_meal = time_now();
		args[i].next_meal = args[i].last_meal + data->time.die; //Probably wrong, need to fix later
		args[i].left_fork = &fork[i];
		if (data->nbr_philos == 1)
			args[i].right_fork = NULL;
		else if (i == 0)
			args[i].right_fork = &fork[data->nbr_philos - 1];
		else
			args[i].right_fork = &fork[i - 1];
		args[i].data = data;
	}
	return (args);
}
