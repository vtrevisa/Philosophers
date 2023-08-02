/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:30:41 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/02 18:08:59 by vtrevisa         ###   ########.fr       */
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
