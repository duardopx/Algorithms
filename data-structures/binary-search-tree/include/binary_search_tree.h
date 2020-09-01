#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__


struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * small_node(struct node * root);
struct node * create_node(int value);
struct node * insert(struct node * root, int value);
struct node * search(struct node * root, int target);
struct node * delete(struct node * root, int target);
void in_order(struct node * root);
void pre_order(struct node * root);
void post_order(struct node * root);

#endif
