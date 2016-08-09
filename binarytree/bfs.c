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

int
height(tree_t *root)
{
	if (root == NULL) {
		return (0);
	}

	int lh = height(root->left);
	int rh = height(root->left);
	if (lh > rh) {
		return lh+1;
	} else {
		return rh+1;
	}
}

void
bfs(tree_t *root, int h)
{
	if (root == NULL) {
		return;
	}
	if (h == 0) {
		printf("%d\n", root->val);
	}
	bfs(root->left, h-1);
	bfs(root->right, h-1);
	return;
}



int
main()
{
	int i;
	tree_t *root = alloc_node(5);
	root->left = alloc_node(1);
	root->right = alloc_node(2);
	root->right->left = alloc_node(3);
	root->right->right = alloc_node(4);

	printf("height %d\n", height(root));
	for (i = 0; i <= height(root); i++) {
		bfs(root, i);
	}
}
