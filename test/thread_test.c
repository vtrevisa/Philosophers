# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

void	*routine(void *args)
{
	printf("Thread here!\n");
	return (0);
}

int	main(void)
{
	pthread_t p1;

	printf("First thread!\n");
	sleep(1);
	pthread_create(&p1, NULL, &routine, NULL);
	sleep(1);
	printf("Ended thread!\n");
	return (0);
}