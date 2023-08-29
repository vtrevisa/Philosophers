/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:29:11 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:32:04 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	take_fork(t_args *args, int nbr)
{
	long long	time;

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

static void	set_must_eat(t_args *args)
{
	if (args->must_eat > 0)
	{
		args->must_eat--;
		if (args->must_eat == 0)
			update_simulation(args->data);
	}
}

void	to_eat(t_args *args, int nbr)
{
	long long	time;

	take_fork(args, nbr);
	pthread_mutex_lock(&(args->philo_m));
	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "is eating", args->data);
	args->last_meal = time_now();
	pthread_mutex_unlock(&(args->philo_m));
	wait(args->data->time.eat, args->last_meal);
	pthread_mutex_unlock(&(args->left_fork->mutex));
	pthread_mutex_unlock(&(args->right_fork->mutex));
	args->left_fork->free = 1;
	args->right_fork->free = 1;
	set_must_eat(args);
}

void	to_sleep(t_args *args, int nbr)
{
	int	time;

	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "is sleeping", args->data);
	wait(args->data->time.sleep, time_now());
}

void	to_think(t_args *args, int nbr)
{
	int	time;
	int	index;
	int	will_eat;

	time = time_now() - args->data->starting_time;
	print_action(time, nbr, "is thinking", args->data);
	usleep(100);
	if (args->data->time.sleep > 2 * args->data->time.eat)
		return ;
	args->iterations += 2;
	index = args->iterations % args->data->nbr_philos;
	will_eat = args->data->line[index][args->nbr - 1];
	if (will_eat)
		wait2(args->data->time.eat * 2, args->last_meal);
	else
	{
		wait2(args->data->time.eat * 3, args->last_meal);
		args->iterations++;
	}
}
