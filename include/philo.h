/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtrevisa <vtrevisa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:36:47 by vtrevisa          #+#    #+#             */
/*   Updated: 2023/08/29 16:59:37 by vtrevisa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h> //write
# include <sys/time.h> //gettimeofday
# include <pthread.h> //threads
# include <stdio.h> //printf
# include <stdlib.h> //malloc e free
# include <limits.h>//INT_MAX

# define RED "\033[38;2;222;56;43m"
# define BLUE "\033[38;2;34;183;235m"
# define RESET "\033[0m"

typedef struct s_time
{
	int		die;
	int		eat;
	int		sleep;
}	t_time;

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_data
{
	int				nbr_philos;
	int				times_must_eat;
	int				simulation;
	int				**line;
	t_time			time;
	long long		starting_time;
	pthread_mutex_t	lock_print;
	pthread_mutex_t	lock_data;
}	t_data;

typedef struct s_args
{
	int				nbr;
	int				must_eat;
	int				iterations;
	long long		last_meal;
	long long		next_meal;
	t_fork			*right_fork;
	t_fork			*left_fork;
	t_data			*data;
	pthread_mutex_t	philo_m;
}	t_args;

	/*-----ACTIONS-----*/
/*ACTIONS.C*/
void			to_think(t_args *args, int nbr);
void			to_sleep(t_args *args, int nbr);
void			to_eat(t_args *args, int nbr);

/*ROUTINE.C*/
void			*one_philo_routine(void	*args);
void			*routine(void *args);

	/*-----ERROR-----*/
int				arg_error(void);
int				no_number(void);
int				too_big(void);
int				more_than_zero(void);

	/*-----INIT-----*/
/*CREATE.C*/
t_fork			*create_forks(t_data *data);
t_args			*create_args(t_data *data, t_fork *fork);
pthread_t		*create_philos(t_data *data, t_args *args);

/*INIT.C*/
int				check_args(int argc, char **argv);
void			init_data(int argc, char **argv, t_data *data);

/*LINE.C*/
int				**organize_line(int nbr);

	/*-----MAIN-----*/
/*FREE.C*/
void			free_all(t_args *args, pthread_t *philos, t_fork *fork, t_data *data);
/*MANAGER.C*/
void			manager(t_args *args, t_data *data);
int				simulation_status(t_data *data);
void			update_simulation(t_data *data);

	/*-----TESTES-----*/
void			show_forks(t_fork *fork, t_data *data);
void			show_args(t_args *args, t_data *data);
void			show_line(int nbr, int **line);
void			show_data(t_data *data);

	/*-----TIME-----*/
long long		time_now(void);
void			wait(int time_wait, long long start);
void			wait2(int time_wait, long long start);

	/*-----UTILS-----*/
/*UTILS.C*/
int				ft_atoi(const char *str);
int				is_all_num(char *str);
void			print_action(long long time, int philo, char *action, \
				t_data *data);

/*UTILS2.C*/
long int		ft_atoli(const char *str);

#endif