/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:41 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:48:41 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	check_argv(int argc, char **argv)
{
	int			i;
	long int	nbr;

	i = 0;
	while (++i < argc)
	{
		if (is_all_num(argv[i]))
			return (no_number());
		nbr = ft_atoli(argv[i]);
		if (i > 11 || nbr > INT_MAX)
			return (too_big());
		if (nbr == 0)
			return (more_than_zero());
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (arg_error());
	else if (check_argv(argc, argv))
		return (1);
	else
		return (0);
}

void	init_data(int argc, char **argv, t_data *data)
{
	data->nbr_philos = ft_atoi(argv[1]);
	data->time.die = ft_atoi(argv[2]);
	data->time.eat = ft_atoi(argv[3]);
	data->time.sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else
		data->times_must_eat = -1;
	data->simulation = data->nbr_philos;
	data->line = organize_line(data->nbr_philos);
	pthread_mutex_init(&(data->lock_print), NULL);
	pthread_mutex_init(&(data->lock_data), NULL);
}
