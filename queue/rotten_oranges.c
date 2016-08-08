#include <stdio.h>
#include <stdlib.h>

#define	NUM_OF_ROW	3
#define	NUM_OF_COL	5

typedef struct queue {
	int row;
	int col;
	struct queue *next;
} queue_t;

queue_t *head = NULL;
queue_t *end = NULL;

void
fill_array(int **array)
{
	int i, j;
	int arr[][NUM_OF_COL] = { {2, 1, 0, 2, 1},
				  {1, 0, 1, 2, 1},
				  {1, 0, 0, 2, 1}}; 

/*	int arr[][NUM_OF_COL] = { {2, 1, 0, 2, 1},
				  {0, 0, 1, 2, 1},
				  {1, 0, 0, 2, 1}}; */
	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			array[i][j] = arr[i][j];
		}
	}
	
}

void
print_array(int **array)
{
//#if 0
	int i, j;
	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
//#endif
	queue_t	*q = head;
	while (q) {
		printf("%d %d\n", q->row, q->col); 
		q = q->next;
	}
}

void
enqueue(int row, int col)
{
	queue_t *queue = malloc(sizeof(queue_t));
	if (end == NULL) {
		end = queue;
		head = end;
	} else {
		end->next = queue;
		end = queue;
	}
	queue->row = row;
	queue->col = col;
}

queue_t *
dequeue()
{
	queue_t *q = head;
	head = head->next;
	return q;
}

int
isValid(int row, int col)
{
	return ((row >= 0) && (row < NUM_OF_ROW) && (col >= 0) && (col < NUM_OF_COL));
}

int
rott_all_oranges(int **array)
{
	int i, j;
	int frame = 0;
	queue_t *q;
	int row, col;
	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			if (array[i][j] == 2) {
				enqueue(i, j);
			}
		}
	}

	enqueue(-1, -1);

	while (head != end) {
		q = dequeue();
		if ((q->row != -1) && (q->col != -1)) {
			row = q->row+1;
			col = q->col; 
			if (isValid(row, col) && (array[row][col] == 1)) {
				array[row][col] = 2;
				enqueue(row, col);
			}
			row = q->row;
			col = q->col+1;
			if (isValid(row, col) && (array[row][col] == 1)) {
				array[row][col] = 2;
				enqueue(row, col);
			}

			row = q->row;
			col = q->col-1;
			if (isValid(row, col) && (array[row][col] == 1)) {
				array[row][col] = 2;
				enqueue(row, col);
			}

			row = q->row-1;
			col = q->col;
			if (isValid(row, col) && (array[row][col] == 1)) {
				array[row][col] = 2;
				enqueue(row, col);
			}
		} else {
			frame++;
			if (head != end) {
				enqueue(-1, -1);
			}
		}
		free(q);
	}
	return frame;
}

int
check_array(int **array)
{
	int i, j;
	for (i = 0; i < NUM_OF_ROW; i++) {
		for (j = 0; j < NUM_OF_COL; j++) {
			if (array[i][j] == 1) {
				return 1;	
			}
		}
	}
	return (0);
}

int
main()
{
	int **arr = malloc(sizeof(int *) * NUM_OF_ROW);
	int i;
	int result;
	for (i = 0; i < NUM_OF_COL; i++) {
		arr[i] = malloc(sizeof(int) * NUM_OF_COL);
	}

	fill_array(arr);
	result = rott_all_oranges(arr);
	if (check_array(arr) == 0) {
		printf("Time required rot %d\n", result);
	} else {
		printf("Can't rot\n");
	}
	//print_array(arr);
}
