#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variable: acessible to all threads
int thread_count = 0;

void* hello(void *rank); // Thread function

int main(int argc, char *argv[])
{
	long thread; //use long in case of a 64-bit system
	pthread_t* thread_handles;
	// Get number of threads from command line
	thread_count = strtol(argv[1], NULL, 10);

	thread_handles = malloc(thread_count*sizeof(pthread_t));

	for(thread = 0; thread < thread_count; thread++)
	{
		pthread_create(&thread_handles[thread], NULL, hello, (void*) thread);
	}
	printf("Hello from the main thread\n");

	for(thread = 0; thread < thread_count; thread++)
	{
		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);
	return 0;
}

void *hello(void *rank)
{
	// Use long in case of 64-bit system
	long my_rank = (long) rank;
	printf("Hello form thread %ld of %d\n", my_rank, thread_count);
	return NULL;
}
