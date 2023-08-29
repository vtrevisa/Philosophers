/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:29:55 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:32:30 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*one_philo_routine(void	*args)
{
	long long	time;
	t_args		*philo;

	philo = (t_args *)args;
	pthread_mutex_lock(&(philo->left_fork->mutex));
	philo->left_fork->free = 0;
	time = time_now() - philo->data->starting_time;
	print_action(time, philo->nbr, "has taken a fork", philo->data);
	wait(philo->data->time.die, philo->data->starting_time);
	pthread_mutex_unlock(&(philo->left_fork->mutex));
}

static int	fork_free(t_fork *fork)
{
	int	free;

	pthread_mutex_lock(&(fork->mutex));
	free = fork->free;
	pthread_mutex_unlock(&(fork->mutex));
	return (free);
}

void	*routine(void *args)
{
	t_args	*philo;

	philo = (t_args *)args;
	if (philo->next_meal)
		usleep(philo->next_meal * 1000 * 0.9);
	while (simulation_status(philo->data) != 0)
	{
		if (!fork_free(philo->left_fork) || !fork_free(philo->right_fork))
		{
			usleep (500);
			continue ;
		}
		to_eat(philo, philo->nbr);
		to_sleep(philo, philo->nbr);
		to_think(philo, philo->nbr);
	}
}
