#include "../include/philo.h"

static void	fill_even_matrix_line(int **m, int size)
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

static void	fill_odd_matrix_line(int **m, int size)
{
	int	i;
	int	j;

	fill_even_matrix_line(m, size);
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

static int	**create_matrix_line(int nbr_of_philos)
{
	int	**line;
	int	i;

	line = malloc(sizeof(int *) * nbr_of_philos);
	i = 0;
	while (i < nbr_of_philos)
	{
		line[i] = malloc(sizeof(int) * nbr_of_philos);
		i++;
	}
	if (nbr_of_philos == 1)
		line[0][0] = 1;
	else if (nbr_of_philos % 2 == 0)
		fill_even_matrix_line(line, nbr_of_philos);
	else
		fill_odd_matrix_line(line, nbr_of_philos);
	return (line);
}

int	main(void)
{
	t_data data;
	data.nbr_philos = 5;
	data.line = create_matrix_line(data.nbr_philos);
	printf("line Matrix\n");
	printf("  ");
	for (int i = 0; i < data.nbr_philos; i++)
		printf("| %d ", i);
	printf("|\n");
	for (int i = 0; i < data.nbr_philos; i++)
	{
		printf("%d |", i);
		for(int j = 0; j <data.nbr_philos;j++)
			printf(" %d |", data.line[i][j]);
		printf("\n");
	}
}