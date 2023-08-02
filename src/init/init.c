/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:41 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/02 18:20:56 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
/* 		printf("argv[%d]: %s\n", i, argv[i]); */
		if (is_all_num(argv[i]))
			return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (arg_error());
	if (check_argv(argc, argv))
		return (arg_error());
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
	/* printf("Nbr= %d\nDie=%d\nEat=%d\nSleep=%d\nMEat=%d\n", data->nbr_philos, data->time.die, data->time.eat, data->time.sleep, data->times_must_eat); */
	/* data->simulation = */
	/* data->order; */
	/* 	data->lock_print;
	data->lock_data; */
}