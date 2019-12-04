#include "tqueue.h"
#include <stdio.h>

TQueue queue = NULL;
TQueue* head = &queue;

int test_tqueue_get_data_empty_queue();
int test_tqueue_get_data();
int test_tqueue_enqueue();

int main()
{
	printf("bella");
    test_tqueue_get_data_empty_queue();
	test_tqueue_enqueue();
	test_tqueue_get_data();
    return 0;
}


int test_tqueue_get_data_empty_queue(){
	printf("bella2");
	if(tqueue_get_data(queue) != (void*) NULL) 
	{
	    printf("ERROR -> test_tqueue_get_data_empty_queue -> la coda vuota non ha ritornato null\n");
		return 0;
	}
	printf("SUCCESS -> test_tqueue_get_data_empty_queue\n");	
}

int test_tqueue_get_data(){
	if(tqueue_get_data(queue) == (void*) NULL)
	{
		printf("ERROR -> test_tqueue_get_data -> la coda con elementi ha ritornato null\n");
		return 0;
	}	
	//TODO test che sia stessa data
	printf("SUCCESS -> test_tqueue_get_data\n");
}

int test_tqueue_enqueue(){
	unsigned long int returnedValZero = tqueue_enqueue(head, (void*)NULL);
    if(returnedValZero != 0)
	{
		printf("ERROR -> first element enqueued doesn't return 0\n");
		return 0;
	}
	returnedValZero = tqueue_enqueue(head, (void*)NULL);
	if(returnedValZero != 1)
	{
		printf("ERROR -> second element enqueued doesn't return 1\n");
		return 0;
	}
	returnedValZero = tqueue_enqueue(head, (void*)NULL);
	if(returnedValZero != 2)
	{
		printf("ERROR -> third element enqueued doesn't return 2\n");
		return 0;
	}
}



