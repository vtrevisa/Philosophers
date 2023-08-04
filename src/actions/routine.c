/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:29:55 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/04 16:21:03 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	take_fork(t_args *args, int nbr)
{
	long long time;

	if (nbr % 2)
	{
		pthread_mutex_lock(&(args->left_fork->mutex));
		pthread_mutex_lock(&(args->right_fork->mutex));
	}
	else
	{
		pthread_mutex_lock(&(args->right_fork->mutex));
		pthread_mutex_lock(&(args->left_fork->mutex));
	}
	args->left_fork->free = 0;
	args->right_fork->free = 0;
	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "has taken a fork", args->data);
	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "has taken a fork", args->data);
}

static void	to_eat(t_args *args, int nbr)
{
	long long	time;
	long long	eating_start;
	
	/*take_fork*/
	take_fork(args, nbr);
	/*eat*/
	eating_start = time_now();
	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "is eating", args->data);
	usleep (args->data->time.eat);
	args->last_meal = time_now();
	/*drop fork*/
	pthread_mutex_unlock(&(args->left_fork->mutex));
	pthread_mutex_unlock(&(args->right_fork->mutex));
	args->left_fork->free = 1;
	args->right_fork->free = 1;
}

static void	to_sleep(t_args *args, int	nbr)
{
	int	time;

	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "is sleeping", args->data);
	usleep(args->data->time.sleep);
}

static void	to_think(t_args *args, int nbr)
{
	int	time;

	time - time_now() - args->data->starting_time;
	print_action(time, nbr, "is thinking", args->data);
	if (args->data->nbr_philos % 2)
		usleep(args->data->time.eat * 3);
	else
		usleep(args->data->time.eat * 2);
}

void	*routine(void *args)
{
	t_args	*philo;
	while (1)
	{
		philo = (t_args *)args;
		/*EAT*/
		to_eat(philo, philo->nbr);
		/*SLEEP*/
		to_sleep(philo, philo->nbr);
		/*THINK*/
		to_think(philo, philo->nbr);
	}
}