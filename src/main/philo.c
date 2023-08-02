/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:35:56 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/02 18:12:13 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv) //number_of_philosophers - time_to_die - time_to_eat - time_to_sleep - [number_of_times_each_philosopher_must_eat]
{
	pthread_t	*philos;
	t_fork		*fork;
	t_args		*args;
	t_data		data;

	/*Check Args*/
	check_args(argc, argv);
	/*Fill Data*/
	init_data(argc, argv, &data);
	/*Create fork*/
	/*Create Args*/
	/*Create Philos*/
	/*Set Simulation*/
	/*Join*/
	/*Free_all*/
	return (0);
}