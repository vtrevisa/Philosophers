/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:35:54 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:14:31 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	**fill_even_line(int nbr)
{
	int	i;
	int	j;
	int	**line;

	line = malloc (sizeof(int *) * nbr);
	i = -1;
	while (++i < nbr)
	{
		line[i] = malloc (sizeof(int) * nbr);
		j = -1;
		while (++j < nbr)
		{
			if (i % 2 == j % 2)
				line[i][j] = 1;
			else
				line[i][j] = 0;
		}
	}
	return (line);
}

static int	**fill_odd_line(int nbr)
{
	int	**line;
	int	i;
	int	j;

	line = fill_even_line(nbr);
	line[0][nbr - 1] = 0;
	i = 1;
	while (++i < nbr)
	{
		j = i - 1;
		while (--j >= 0)
		{
			if (i % 2 != j % 2)
				line[i][j] = 1;
			else
				line[i][j] = 0;
		}
	}
	return (line);
}

int	**organize_line(int nbr)
{
	int	**line;
	int	i;

	i = -1;
	if (nbr == 1)
	{
		line = malloc (sizeof (int *));
		line[0] = malloc (sizeof (int));
		line[0][0] = 1;
	}
	else if (nbr % 2 == 0)
		line = fill_even_line(nbr);
	else
		line = fill_odd_line(nbr);
	return (line);
}
