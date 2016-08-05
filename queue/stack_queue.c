#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int	value;
	struct queue *next;
} queue_t;

queue_t	*qhead = NULL;;

void
enqueue(queue_t *q)
{
	q->next = qhead;
	qhead = q;
}

queue_t *
dequeue()
{
	queue_t *item = qhead;
	qhead = qhead->next;
	return item;
}

void
push(int val)
{
	queue_t *item = malloc(sizeof(queue_t));
	item->value = val;
	item->next = NULL;
	enqueue(item);
}

int
pop()
{
	queue_t *item;
	int val;
	if (qhead == NULL) {
		printf("empty queue\n");
		return -1;
	}
	item = dequeue();
	val = item->value;
	free(item);
	return val;
}

int
main()
{
	push(5);		
	push(15);		
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
	printf("pop %d\n", pop());
}
