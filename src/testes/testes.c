#include "../../include/philo.h"

void	show_forks(t_fork *fork, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		printf("Fork[%d] = %d\n", i, fork[i].free);
}

void	show_data(t_data *data)
{
	printf("Nbr= %d\n", data->nbr_philos);
	printf("Die=%d\n", data->time.die);
	printf("Eat=%d\n", data->time.eat);
	printf("Sleep=%d\n", data->time.sleep);
	printf("MEat=%d\n", data->times_must_eat);
}

void	show_args(t_args *args, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		printf("****MOSTRANDO ARGS[%d]****\n", i);
		printf("args[%d].nbr = %d\n", i, args[i].nbr);
		printf("args[%d].must_eat = %d\n", i, args[i].must_eat);
		printf("args[%d].last_meal = %lld\n", i, args[i].last_meal);
		printf("args[%d].next_meal = %lld\n", i, args[i].next_meal);
		printf("args[%d].nbr = %d\n", i, args[i].nbr);
		printf("args[%d].left_fork = %d\n", i, args[i].left_fork->free);
		if (data->nbr_philos == 1)
			printf("args[%d].rigt_fork = %ls\n", i, &args[i].right_fork->free);
		else
			printf("args[%d].rigt_fork = %d\n", i, args[i].right_fork->free);
	}
}