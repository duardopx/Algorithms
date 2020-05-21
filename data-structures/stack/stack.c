#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Pensar em alto nivel
 * estruturar o pensamento
 * implementar
 * */

#define STACK_SIZE 0x64

int stack[STACK_SIZE];

int stack_pointer = -1;

char stack_empty()
{
	if (stack_pointer < 0x0)
	{
		return 0x1;
	}

	return 0x0;
}

void push(int * stack, int value)
{

	if (stack_pointer >= STACK_SIZE)
	{
		return;
	}

	stack_pointer += 0x1;
	printf("> stack_pointer value: [%d]\n", stack_pointer);
	stack[stack_pointer] = value;
}

int pop(int * stack)
{
	int return_element;

	if (stack_empty() == 0x1)
	{
		puts("> Stack is empty");
		return 0x0;
	}

	return_element = stack[stack_pointer];
	stack_pointer -= 0x1;

	return return_element;
}

void print_stack()
{
	int i;

	for (i = 0x0; i <= stack_pointer; i++)
	{
		printf("{%d:[%d]}\n", i, stack[i]);
	}
	puts("");
}


int main(int argc, char ** argv)
{
	/* push(stack, 0xa); */
	/* push(stack, 0xb); */
	/* push(stack, 0xc); */
	/* push(stack, 0xd); */

	print_stack();

	pop(stack);
	pop(stack);

	print_stack();

	return 0x0;
}
