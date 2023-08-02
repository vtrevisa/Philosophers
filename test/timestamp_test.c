#include "./Libft/Include/libft.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

/* int	main(void)
{
	int	time_zero;
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	time_zero = current_time.tv_usec;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		printf("Passed %ld00 ms since i was born\n", (current_time.tv_usec - time_zero)/100);
		sleep (1);
	}
} */

int	main(void)
{
	struct timeval	time;

	while (1)
	{
		gettimeofday(&time, NULL);
		printf("Time: %ld\n",(time.tv_sec * 1000) + (time.tv_usec / 1000));
		sleep(1);
	}

	return (0);
}