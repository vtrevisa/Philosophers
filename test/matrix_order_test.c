#include "../include/philo.h"

static void	fill_even_matrix_order(int **m, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i % 2 == 0 && j % 2 == 0)
				m[i][j] = 1;
			else if (i % 2 == 1 && j % 2 == 1)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	fill_odd_matrix_order(int **m, int size)
{
	int	i;
	int	j;

	fill_even_matrix_order(m, size);
	m[0][size - 1] = 0;
	i = 2;
	while (i < size)
	{
		j = i - 2;
		while (j >= 0)
		{
			if (i % 2 == 1 && j % 2 == 0)
				m[i][j] = 1;
			else if (i % 2 == 0 && j % 2 == 1)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j--;
		}
		i++;
	}
}

static int	**create_matrix_order(int nbr_of_philos)
{
	int	**order;
	int	i;

	order = malloc(sizeof(int *) * nbr_of_philos);
	i = 0;
	while (i < nbr_of_philos)
	{
		order[i] = malloc(sizeof(int) * nbr_of_philos);
		i++;
	}
	if (nbr_of_philos == 1)
		order[0][0] = 1;
	else if (nbr_of_philos % 2 == 0)
		fill_even_matrix_order(order, nbr_of_philos);
	else
		fill_odd_matrix_order(order, nbr_of_philos);
	return (order);
}

int	main(void)
{
	t_data data;
	data.nbr_philos = 5;
	data.order = create_matrix_order(data.nbr_philos);
	printf("Order Matrix\n");
	printf("  ");
	for (int i = 0; i < data.nbr_philos; i++)
		printf("| %d ", i);
	printf("|\n");
	for (int i = 0; i < data.nbr_philos; i++)
	{
		printf("%d |", i);
		for(int j = 0; j <data.nbr_philos;j++)
			printf(" %d |", data.order[i][j]);
		printf("\n");
	}
}