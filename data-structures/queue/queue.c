#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 0x64

int queue[QUEUE_SIZE];

int queue_pointer = -0x1;
int base_pointer = 0x0;

char queue_empty()
{
	if (queue_pointer < 0x0)
	{
		printf("> Queue is empty");
		return 0x1;
	}

	return 0x0;
}

void push(int * queue, int value)
{

	if (queue_pointer >= QUEUE_SIZE)
	{
		return;
	}

	queue_pointer += 0x1;

	printf("> queue_pointer value: [%d]\n", queue_pointer);
	queue[queue_pointer] = value;
}


int pop(int * queue)
{
	int return_element = queue[base_pointer];
	base_pointer += 0x1;
	
	return return_element;
}

void print_queue()
{
	int i;

	for (i = 0x0; i <= queue_pointer; i++)
	{
		printf("{%d:[%d]}\n", i, queue[i]);
	}
	puts("");
}


int main(int argc, char ** argv)
{
	int fodac;
	push(queue, 0xa);
	push(queue, 0xb);
	push(queue, 0xc);
	push(queue, 0xd);

	print_queue();

	fodac = pop(queue);

	print_queue();
	printf("%d\n", fodac);

	return 0x0;
}
