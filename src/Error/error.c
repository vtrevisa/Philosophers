/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:35:00 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 14:27:47 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	arg_error(void)
{
	printf("%sInvalid Args!\nTerminating execution...\n%s", RED, RESET);
	return (1);
}

int	no_number(void)
{
	printf("%sInvalid Number!\nargument must be a positive integer\n%s", \
RED, RESET);
	return (1);
}

int	too_big(void)
{
	printf("%sNumber too big!\n%s", RED, RESET);
	return (1);
}

int	more_than_zero(void)
{
	printf("%scmon, number must be more than zero, pal\n%s", RED, RESET);
	return (1);
}
