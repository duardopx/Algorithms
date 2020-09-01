#ifndef __LINKED_LIST__
#define __LINKED_LIST__


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

struct node * create_node(int value);
struct linked_list * create_linkedlist();
void add(struct linked_list * linked_list, struct node * node);

struct node * search(struct linked_list * linked_list, int target);

void delete(struct linked_list * linked_list, int target);

void print_linked_list(struct linked_list * linked_list);

#endif
