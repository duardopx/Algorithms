#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


struct queue
{
	int rear;
	int size;
	int front;
	int * array;
	unsigned capacity;
};

bool is_empty(struct queue * queue)
{
	return  queue->size == 0x0;
}

bool is_full (struct queue * queue)
{
	return queue->size == queue->capacity;
}

struct queue * create_queue (unsigned capacity)
{
	struct queue * new_queue = (struct queue *)malloc(sizeof(struct queue));
	new_queue->capacity = capacity;
	new_queue->rear = -0x1;
	new_queue->front = 0x0;
	new_queue->size = 0x0;
	new_queue->array = (int *)malloc(new_queue->capacity * sizeof(int));

	return new_queue;
}

int rear(struct queue * queue)
{
	if (is_empty(queue))
		return INT_MIN;

	return queue->array[queue->rear];
}

int front(struct queue * queue)
{
	if (is_empty(queue))
		return INT_MIN;

	return queue->array[queue->front];
}

void dequeue(struct queue * queue)
{
	if (is_empty(queue))
		return;

	queue->size--;
	queue->front++;
}

void enqueue(struct queue * queue, int value)
{
	if (is_full(queue))
		return;

	queue->size++;
	queue->array[(++queue->rear) % queue->size] = value;
}

void print_struct(struct queue * queue)
{
	int i;

	for (i = 0x0; i < queue->size; i++)
	{
		printf("{%d:[%d]}\n", i, queue->array[i]);
	}

	puts("");
}


int main(int argc, char ** argv)
{
	struct queue * queue;
	queue = create_queue(0xa);


	enqueue(queue, 0x0);
	enqueue(queue, 0x1);
	enqueue(queue, 0x2);
	enqueue(queue, 0x3);
	enqueue(queue, 0x4);
	enqueue(queue, 0x5);
	enqueue(queue, 0x6);
	enqueue(queue, 0x7);
	enqueue(queue, 0x8);
	enqueue(queue, 0x9);
	enqueue(queue, 0x9);
	enqueue(queue, 0x9);

	print_struct(queue);

	dequeue(queue);
	dequeue(queue);
	dequeue(queue);

	print_struct(queue);

	return 0x0;
}
