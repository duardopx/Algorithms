#include <stdio.h>
#include <stdlib.h>
#include "../include/binary_search_tree.h"

struct node * small_node(struct node * root)
{
	if (root->left == NULL)
		return root;

	return small_node(root->left);
}

struct node * create_node(int value)
{
	struct node * new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

struct node * insert(struct node * root, int value)
{
	if (root == NULL)
		return create_node(value);

	else if (root->data > value)
		root->left = insert(root->left, value);

	else
		root->right = insert(root->right, value);

	return root;
}

struct node * search(struct node * root, int target)
{
	if (root == NULL || root->data == target)
		return root;

	else if (root->data > target)
		return search(root->left, target);

	return search(root->right, target);
}


struct node * delete(struct node * root, int target)
{
	struct node * substitute;

	if (root == NULL)
		return NULL;

	if (root->data > target)
		root->left = delete(root->left, target);

	else if (root->data < target)
		root->right = delete(root->right, target);

	else
	{
		if (root->left == NULL)
		{
			substitute = root->right;
			free(root);
			return substitute;
		}
		  
		else if (root->right == NULL)
		{
			substitute = root->left;
			free(root);
			return substitute;
		}

		substitute = small_node(root->right);
		root->data = substitute->data;
		root->right = delete(root->right, substitute->data);
	}
	
	return root;
}

void in_order(struct node * root)
{
	if (root == NULL)
		return;

	printf("[%d]", root->data);
	in_order(root->left);
	in_order(root->right);

}

void pre_order(struct node * root)
{
	if (root == NULL)
		return;

	pre_order(root->left);
	printf("[%d]", root->data);
	pre_order(root->right);
}

void post_order(struct node * root)
{
	if (root == NULL)
		return;

	post_order(root->left);
	post_order(root->right);
	printf("[%d]", root->data);
}

