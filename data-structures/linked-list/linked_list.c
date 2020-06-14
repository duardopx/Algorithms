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


struct node * search(struct linked_list * linked_list, int target)
{
	linked_list->list = linked_list->head->next;

	while (linked_list->list != linked_list->tail)
	{
		if (linked_list->list->data == target)
			return linked_list->list;

		linked_list->list = linked_list->list->next;
	}

	return NULL;
}

void delete(struct linked_list * linked_list, int target)
{

	if (search(linked_list, target) == NULL)
	{
		puts("> Element not found to be removed");
		return;
	}

	linked_list->size--;
	linked_list->list = linked_list->head->next;


	if ((linked_list->list == linked_list->head->next) &&
			(linked_list->list->data ==  target))
	{
		struct node * new_next = linked_list->list->next;
		linked_list->list = new_next;
		linked_list->head->next = linked_list->list;

		return;
	}

	while (linked_list->list->next->data != target)
	{
		linked_list->list = linked_list->list->next;
	}
	
	struct node * new_next = linked_list->list->next->next;
	linked_list->list->next->next = NULL;
	linked_list->list->next = new_next;

}


void print_linked_list(struct linked_list * linked_list)
{
	int count = 0x0;

	linked_list->list = linked_list->head->next;

	while (linked_list->list != linked_list->tail)
	{
		printf("{%d:%d}\n", count, linked_list->list->data);
		linked_list->list = linked_list->list->next;
		count++;
	}
}




int main(int argc, char ** argv)
{
	struct linked_list * linked_list;
	linked_list = create_linkedlist();
	
	puts(".................................");
	puts("Adding nodes {0xa ... 0xf}");
	puts(".................................");

	add(linked_list, create_node(0x0));
	add(linked_list, create_node(0x1));
	add(linked_list, create_node(0x2));
	add(linked_list, create_node(0x3));
	add(linked_list, create_node(0x4));
	add(linked_list, create_node(0x5));


	print_linked_list(linked_list);


	puts(".................................");
	puts("Deleting Elements");
	puts(".................................");

	delete(linked_list, 0x0);
	delete(linked_list, 0x5);
	delete(linked_list, 0x3);

	printf("> List data: %d\n", linked_list->list->data);
	print_linked_list(linked_list);


	puts(".................................");
	puts("Size");
	puts(".................................");

	printf("Linked list Size: %d\n", linked_list->size);




	/* print_linked_list(linked_list); */

	return 0x0;
}
