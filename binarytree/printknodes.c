#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int val;
	struct tree *left;
	struct tree *right;
} tree_t;

tree_t *
alloc_node(int val)
{
	tree_t *node = malloc(sizeof(tree_t));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void
printk(tree_t *root, int k)
{
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		printf("%d \n", root->val);
	}
	printk(root->left, k-1);
	printk(root->right, k-1);
	return;
}


int
main()
{
	int i;
	tree_t *root = alloc_node(1);
	root->left = alloc_node(2);
	root->right = alloc_node(3);
	root->right->left = alloc_node(8);
	root->left->left = alloc_node(4);
	root->left->right = alloc_node(5);

	printk(root, 2);
}
