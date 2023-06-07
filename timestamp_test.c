#include "./Libft/Include/libft.h"
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

int	main(void)
{
	int	time_zero;
	struct timeval current_time;
	gettimeofday(&current_time, NULL);
	time_zero = current_time.tv_usec;
	while (1)
	{
		gettimeofday(&current_time, NULL);
		printf("Passed %ld ms since i was born\n", (current_time.tv_usec - time_zero));
	}
	/* while (1)
	{
		gettimeofday(&current_time, NULL);
		printf("Passed %ld s since i was born\n", (current_time.tv_sec - time_zero));
		sleep(1);
	} */
}