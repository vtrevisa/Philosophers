/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:35:56 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/04 16:37:51 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	join_philos(t_data *data, pthread_t *philos)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		pthread_join(philos[i], NULL);
	}
}

int	main(int argc, char **argv) //number_of_philosophers - time_to_die - time_to_eat - time_to_sleep - [number_of_times_each_philosopher_must_eat]
{
	pthread_t	*philos;
	t_fork		*fork;
	t_args		*args;
	t_data		data;

	/*Check Args*/
	if (check_args(argc, argv))
		return (1);
	/*Fill Data*/
	init_data(argc, argv, &data);
	/*Create fork*/
	fork = create_forks(&data);
	/*Create Args*/
	args = create_args(&data, fork);
	/*Create Philos*/
	philos = create_philos(&data, args);
	/*Set Simulation*/
	/*Join*/
	join_philos(&data, philos);
	/*Free_all*/
	return (0);
}