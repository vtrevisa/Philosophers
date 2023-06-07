/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:36:28 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/06/05 16:45:11 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "./Libft/Include/libft.h"

int mails = 0;

void	*routine()
{
	int i = 0;
	
	while (i < 100000)
	{
		mails++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_t p1, p2;

	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
	{
		return (1);
	}
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
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
	ft_printf("Number of mails: %d\n", mails);
	return (0);
}