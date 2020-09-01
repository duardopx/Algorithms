#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

struct queue
{
	int rear;
	int size;
	int front;
	int * array;
	unsigned capacity;
};


bool is_empty(struct queue * queue);
bool is_full (struct queue * queue);
struct queue * create_queue (unsigned capacity);

int rear(struct queue * queue);
int front(struct queue * queue);
void dequeue(struct queue * queue);
void enqueue(struct queue * queue, int value);
void print_struct(struct queue * queue);

#endif
