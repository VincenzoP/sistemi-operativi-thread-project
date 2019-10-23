#include "tqueue.h"
#include <stdio.h>

TQueue queue {NULL, NULL};


int test_tqueue_get_data_empty_queue();
int test_tqueue_get_data();


int test_tqueue_enqueue();

int main()
{
    test_tqueue_get_data_empty_queue();
	test_tqueue_enqueue();
	test_tqueue_get_data();
    return 0;
}



int test_tqueue_get_data_empty_queue(){
	if(tqueue_get_data(queue) != (void*) NULL) 
	{
	    printf("ERROR -> test_tqueue_get_data_empty_queue -> la coda vuota non ha ritornato null");
	}	
}

int test_tqueue_get_data(){
	if(tqueue_get_data(queue) == (void*) NULL)
	{
		printf("ERROR -> test_tqueue_get_data -> la coda con elementi ha ritornato null")
	}	
	//TODO test che sia stessa data
}

int test_tqueue_enqueue(){

}



