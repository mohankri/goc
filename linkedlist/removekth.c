#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int val;
	struct node *next;
} node_t;

node_t *
alloc_node(int val)
{
	node_t *node = malloc(sizeof(node_t));
	node->val = val;
	node->next = NULL;
	
	return node;
}

node_t *
remove_elem(node_t **root, int k)
{
	node_t *temp = *root;
	node_t *head = temp;
	node_t *prev = head;
	int count = 0;

	if (temp == NULL) {
		return NULL;	
	}

	while (temp) {
		count++;
		if (count == k) {
			if (temp == head) {
				prev = temp;
				temp = temp->next;	
				free(prev);
				head = temp;
			} else {
				prev->next = temp->next;
				free(temp);
			}
		}
		prev = temp;
		temp = temp->next;
	}
	*root = head;
	return (head);
}



int
main()
{
	node_t *temp;
	node_t *root = alloc_node(1);
	root->next = alloc_node(2);
	root->next->next = alloc_node(3);
	root->next->next->next = alloc_node(4);	
	root->next->next->next->next = alloc_node(5);	

	root = remove_elem(&root, 1);

	for (temp = root; temp != NULL; temp = temp->next) {
		printf("%d \n", temp->val);
	}
}
