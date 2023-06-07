# Philosophers

| FUNCTION NAME | FUNCTION PROTOTPE | DESCRIPTION |
| ------------- | ----------------- | ----------- |
|memset| void *memset(void *str, int c, size_t n); | copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str.|
|usleep|int usleep(useconds_t usec);|suspend execution for microsecond intervals|
|gettimeofday|int gettimeofday(struct timeval *restrict tv,struct timezone *restrict tz);|get the actual time|
|pthread_create|int pthread_create(pthread_t *restrict thread,const pthread_attr_t, *restrict attr, void *(*start_routine)(void *),void *restrict arg);| starts a new thread in the calling process. The new thread starts execution by invoking start_routine(); arg is passed as the sole argument of start_routine().|
|pthread_detach|int pthread_detach(pthread_t thread);|marks the thread identified by thread as detached.  When a detached thread terminates, its resources are automatically released back to the system without the need for another thread to join with the terminated thread.|
|pthread_join|int pthread_join(pthread_t thread, void **value_ptr);|suspend execution of the calling thread until the target thread terminates, unless the target thread has already terminated.|
|pthread_mutex_init|int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);|initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used;|
|pthread_mutex_destroy|int pthread_mutex_destroy(pthread_mutex_t *mutex);|destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised.|
|pthread_mutex_lock|int pthread_mutex_lock(pthread_mutex_t *mutex);|The mutex object referenced by mutex is locked|
|pthread_mutex_unlock|int pthread_mutex_unlock(pthread_mutex_t *mutex);|releases the mutex object referenced by mutex.|