/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:53 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:22:57 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_fork	*create_forks(t_data *data)
{
	int		i;
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

static void	set_fork(t_fork *fork, t_args *args, int nbr_philos, int index)
{
	args->left_fork = &fork[index];
	if (nbr_philos == 1)
		args->right_fork = NULL;
	else if (index == 0)
		args->right_fork = &fork[nbr_philos - 1];
	else
		args->right_fork = &fork[index - 1];
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
		args[i].must_eat = data->times_must_eat;
		args[i].data = data;
		set_fork(fork, &args[i], data->nbr_philos, i);
		if (data->line[0][i] == 1)
			args[i].next_meal = 0;
		else if (data->line[1][i] == 1)
			args[i].next_meal = data->time.eat;
		else
			args[i].next_meal = data->time.eat * 2;
		args[i].iterations = args[i].next_meal / data->time.eat;
		pthread_mutex_init(&(args[i].philo_m), NULL);
	}
	return (args);
}

static pthread_t	*create_philo(t_args *args, pthread_t *philos)
{
	args->data->starting_time = time_now();
	args->last_meal = args->data->starting_time;
	pthread_create(philos, NULL, &one_philo_routine, (void *)args);
	return (philos);
}

pthread_t	*create_philos(t_data *data, t_args *args)
{
	pthread_t	*philos;
	int			i;

	i = -1;
	philos = malloc(sizeof(pthread_t) * data->nbr_philos);
	if (data->nbr_philos == 1)
		return (create_philo(args, philos));
	args->data->starting_time = time_now();
	while (++i < data->nbr_philos)
	{
		args[i].last_meal = args->data->starting_time;
		pthread_create(&philos[i], NULL, &routine, (void *)&args[i]);
	}
	return (philos);
}
