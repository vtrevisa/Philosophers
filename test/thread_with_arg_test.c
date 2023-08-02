# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

void	*routine(void *args)
{
	int *count;

	count = (int *)args;
	*count += 1;
	return (0);
}

int	main(void)
{
	pthread_t	p1;
	int			count;

	count = 0;
	printf("Count to 10!\n");
	sleep(1);
	while (count < 10)
	{
		printf("%d\n", count);
		pthread_create(&p1, NULL, &routine, &count);
		sleep(1);
	}
	printf("Done!\n");
	return (0);
}