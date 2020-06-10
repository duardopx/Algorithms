#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node * next;
};


struct linked_list
{
	int size;
	struct node * head;
	struct node * tail;
	struct node * list;
};


struct node * create_node(int value)
{
	struct node * new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = value;
	return new_node;
}

struct linked_list * create_linkedlist()
{
	struct linked_list * new_linked_list =  (struct linked_list *) malloc(sizeof(struct linked_list));

	new_linked_list->size = 0x0;

	new_linked_list->head = create_node(0x0);
	new_linked_list->tail = create_node(0x0);



	return new_linked_list;
}

void add(struct linked_list * linked_list, struct node * node)
{

	linked_list->size++;

	if (!linked_list->list)
	{
		linked_list->list = node;
		linked_list->head->next = linked_list->list;
		linked_list->list->next = linked_list->tail;

		/* printf("list->data: %d\n", linked_list->list->data); */

		return;
	}

	linked_list->list->next = node;
	linked_list->list->next->next = linked_list->tail;
	linked_list->list = linked_list->list->next;
}

void print_linked_list(struct linked_list * linked_list)
{
	int count = 0x0;

	linked_list->list = linked_list->head->next;
	

	while (linked_list->list->next != linked_list->tail)
	{
		printf("{%d : %d}\n", count, linked_list->list->data);
		linked_list->list = linked_list->list->next;
		count++;
	}
}

/* void remove(struct linked_list * linked_list, int value); */


int main(int argc, char ** argv)
{
	struct linked_list * linked_list;
	linked_list = create_linkedlist();
	
	puts("Adding nodes {0xa ... 0xf}");
	puts(".................................");

	add(linked_list, create_node(0xa));
	add(linked_list, create_node(0xb));
	add(linked_list, create_node(0xc));
	add(linked_list, create_node(0xd));
	add(linked_list, create_node(0xe));
	add(linked_list, create_node(0xff));


	print_linked_list(linked_list);


	puts(".................................");

	printf("list->data: %d\n", linked_list->list->data);
	printf("list->data: %d\n", linked_list->list->next->data);
	/* printf("list->data: %d\n", linked_list->list->next->data); */
	/* printf("tail->data: %d\n", linked_list->tail->data); */
	/* printf("head->data: %d\n", linked_list->head->data); */

	/* print_linked_list(linked_list); */

	return 0x0;
}
