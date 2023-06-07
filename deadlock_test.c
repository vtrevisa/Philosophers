#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "./Libft/Include/libft.h"

#define THREAD_NUM 8

pthread_mutex_t mutexFuel;
int fuel = 50;

pthread_mutex_t mutexWater;
int water = 10;

void	*routine(void *args)
{
	if (rand() % 2 == 0)
	{
		pthread_mutex_lock(&mutexFuel);
		sleep(1);
		pthread_mutex_lock(&mutexWater);
	}
	else
	{
		pthread_mutex_lock(&mutexWater);
		sleep(1);
		pthread_mutex_lock(&mutexFuel);
	}
	fuel += 50;
	water = fuel;
	ft_printf("Incremented fuel to: %d and set Water to: %d\n", fuel, water);
	pthread_mutex_unlock(&mutexFuel);
	pthread_mutex_unlock(&mutexWater);
}

int	main(int argc, char **argv)
{
	pthread_t th[THREAD_NUM];
	pthread_mutex_init(&mutexFuel, NULL);
	pthread_mutex_init(&mutexWater, NULL);
	int i;
	
	i = 0;
	ft_printf("Will we get a deadlock?\n");
	while (i < THREAD_NUM)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
		i++;
	}
	ft_printf("Fuel: %d\n", fuel);
	ft_printf("Water: %d\n", water);
	ft_printf("Not yet, Launch again!\n");
	pthread_mutex_destroy(&mutexFuel);
	pthread_mutex_destroy(&mutexWater);
	return (0);
}