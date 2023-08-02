/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:36:28 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/07/27 16:12:11 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "../include/philo.h"

typedef struct s_data
{
	int	mails;
	pthread_mutex_t mutex;
} t_data;

void	*routine(void *data)
{
	int	i;
	t_data	*ndata;

	ndata = (t_data *)data;
	i = 0;
	while (i < 100000)
	{
		pthread_mutex_lock(&ndata->mutex);
		ndata->mails += 1;
		i++;
		pthread_mutex_unlock(&ndata->mutex);
	}
}

int	main(int argc, char **argv)
{
	t_data data;
	pthread_t p1, p2;

	data.mails = 0;
	pthread_mutex_init(&data.mutex, NULL);

	if (pthread_create(&p1, NULL, &routine, &data) != 0)
	{
		return (1);
	}
	if (pthread_create(&p2, NULL, &routine, &data) != 0)
	{
		return (2);
	}
	if (pthread_join(p1, NULL) != 0)
	{
		return (3);
	}
	if (pthread_join(p2, NULL) != 0)
	{
		return (4);
	}
	printf("Number of mails: %d\n", data.mails);
	return (0);
}