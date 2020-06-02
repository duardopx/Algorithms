#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


struct stack
{
	int size;
	int top;
	int * array;
	unsigned capacity;
};

bool is_empty(struct stack * stack)
{
	return  stack->size == 0x0;
}

bool is_full (struct stack * stack)
{
	return stack->size == stack->capacity;
}

struct stack * create_stack(unsigned capacity)
{
	struct stack * new_stack = (struct stack *)malloc(sizeof(struct stack));
	new_stack->capacity = capacity;
	new_stack->top = -0x1;
	new_stack->size = 0x0;
	new_stack->array = (int *)malloc(new_stack->capacity * sizeof(int));

	return new_stack;
}

void push(struct stack * stack, int value)
{
	if (is_full(stack))
		return;

	stack->size++;
	stack->array[++stack->top] = value;
}

int pop(struct stack * stack)
{
	if (is_empty(stack))
		return INT_MIN;

	stack->size--;
	return stack->array[stack->top--];
}


void print_struct(struct stack * stack)
{
	int i;

	for (i = 0x0; i < stack->size; i++)
	{
		printf("{%d:[%d]}\n", i, stack->array[i]);
	}

	puts("");
}


int main(int argc, char ** argv)
{
	struct stack * stack = create_stack(0xa);

	push(stack, 0xa);
	push(stack, 0x1);
	push(stack, 0x2);
	push(stack, 0x3);
	push(stack, 0x4);

	print_struct(stack);

	pop(stack);
	pop(stack);

	print_struct(stack);

	push(stack, 0x3);
	push(stack, 0x4);

	print_struct(stack);


	return 0x0;
}
