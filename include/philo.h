/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:36:47 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/02 18:20:22 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //write
# include <sys/time.h> //gettimeofday
# include <pthread.h> //threads
# include <stdio.h> //printf
# include <stdlib.h> //malloc e free

# define RED "\033[38;2;222;56;43m"
# define BLUE "\033[38;2;34;183;235m"
# define RESET "\033[0m"

typedef struct s_time
{
	int		die;
	int		eat;
	int		sleep;
} t_time;

typedef struct s_fork
{
	int		free;
	pthread_mutex_t	mutex;
} t_fork;

typedef struct s_data
{
	int			nbr_philos;
	int			times_must_eat;
	int			simulation;
	int			**order;
	t_time		time;
	long long	starting_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_data;
}	t_data;

typedef struct s_args
{
	int			nbr;
	int			must_eat;
	int			iterations;
	long long	last_meal;
	long long	next_meal;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_data		*data;
} t_args;

/*ACTIONS*/

/*ERROR*/
int	arg_error(void);
/*INIT*/
int	check_args(int argc, char **argv);
void	init_data(int argc, char **argv, t_data *data);
/*TIME*/

/*UTILS*/
int	ft_atoi(const char *str);
int	is_all_num(char *str);
#endif