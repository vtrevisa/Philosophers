/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:44 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 17:10:11 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_all(t_args *args, pthread_t *philos, t_fork *fork, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		free(data->line[i]);
	free(data->line);
	free(fork);
	free(args);
	free(philos);
}
