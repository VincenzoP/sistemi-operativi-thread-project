#include "tqueue.h"
#include "stdlib.h"

#define NULL 0

typedef struct TQueueNode {
	struct TQueueNode* next;
	void* data;
} TQueueNode;

//typedef struct TQueueNode* TQueue;


/* Adds a new element at the end of the list, returns its position */
unsigned long int tqueue_enqueue(TQueue* q, void* data)
{
	TQueueNode* newNode = (TQueue)malloc(sizeof(TQueueNode));
	newNode->data = data;
	newNode->next = (void*) NULL;
	if(*q == (void*) NULL)
	{
		*q = newNode;
		newNode->next = newNode;
		return 0;
	} 
	else
	{
		int counter = 1;
		newNode->next = *q;
		TQueueNode* tmp = (*q)->next;
		while(tmp->next != *q)
		{
			tmp = tmp->next;
			++counter;
		}
		tmp->next = newNode;
		return counter;
	}
}

/* Removes and returns the element at the beginning of the list, NULL if the
queue is empty */
//TO TEST
void* tqueue_pop(TQueue* q)
{
	if(*q = (void*) NULL) 
		return (void*) NULL;		
	
	void* data_to_return = (*q)->data;
	if(tqueue_size(*q) == 1){
		*q = (void*)NULL;
		return data_to_return;
	}

	TQueueNode* first_elem = *q;
	TQueueNode* last_elem = (*q)->next; //non va prob
	TQueueNode* second_elem = (*q)->next;
	while(last_elem->next != first_elem)	
		last_elem = last_elem->next;

	last_elem->next = second_elem;
	//**q = (void* NULL);
	free(*q); //<_________________________________________________
	*q = second_elem;
	return data_to_return;
}

/* Returns the number of elements in the list */
//TO TEST !!!!!
unsigned long int tqueue_size(TQueue q)
{
	if(q == (void*) NULL)
		return 0;
	
	TQueueNode* first = q;
	TQueueNode* tmp = q->next;
	int count = 1;
	while(tmp != first){
		tmp = tmp->next;
		++count;
	} 
	return count;
}

/* Returns a 'view' on the list starting at (a positive) offset distance,
* NULL if the queue is empty */
//TO TEST !!!!
TQueue tqueue_at_offset(TQueue q, unsigned long int offset)
{
	if(q == (void*) NULL)
		return (void*) NULL;
	TQueueNode* element_at_offset = q;
	for(int i = 0; i<offset; i++){
		element_at_offset = element_at_offset->next;
	}	
	return element_at_offset;
	
}

/* Returns the data on the first node of the given list */
void* tqueue_get_data(TQueue q)
{
	if(q == (void*) NULL)
	{
		return (void*) NULL;
	}
	return q->data;
}
