#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * left;
	struct node * right;
};


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
	if(root == NULL)
		return root;

	if (root->data > target)
		root->left = delete(root->left, target);

	else if (root->data < target)
		root->right = delete(root->right, target);

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

int main(int argc, char ** argv)
{
	struct node * root = NULL;

	root = insert(root, 0x7);

	insert(root, 0x4);
	insert(root, 0x6);

	insert(root, 0xa);
	insert(root, 0xb);


	puts("[TREE]");
	puts(".............................");


	in_order(root);
	puts("");
	puts(".............................");

	puts(".............................");

	return 0x0;
}
