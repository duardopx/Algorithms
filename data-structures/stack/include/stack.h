#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

struct stack
{
	int size;
	int top;
	int * array;
	unsigned capacity;
};


bool is_empty(struct stack * stack);
bool is_full (struct stack * stack);
struct stack * create_stack(unsigned capacity);
void push(struct stack * stack, int value);
int pop(struct stack * stack);
void print_struct(struct stack * stack);

#endif

