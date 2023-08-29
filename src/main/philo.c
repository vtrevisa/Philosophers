/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:35:56 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 16:59:26 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	join_philos(t_data *data, pthread_t *philos)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		pthread_join(philos[i], NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	*philos;
	t_fork		*fork;
	t_args		*args;
	t_data		data;

	if (check_args(argc, argv))
		return (1);
	init_data(argc, argv, &data);
	fork = create_forks(&data);
	args = create_args(&data, fork);
	philos = create_philos(&data, args);
	manager(args, &data);
	join_philos(&data, philos);
	free_all(args, philos, fork, &data);
	return (0);
}
