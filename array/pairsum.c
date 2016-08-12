#include <stdio.h>

int
partition(int a[], int start, int end)
{
	int pivot = end-1;
	int i = start;
	int j = start - 1;
	int temp;

	while (i < end) {
		//printf("compare %d %d\n", a[i], a[pivot]);
		if (a[i] < a[pivot]) {
			j++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		i++;
	}
	temp = a[pivot];
	a[pivot] = a[j+1];
	a[j+1] = temp;
	return (j+1);
}

void
qsort(int a[], int start, int end)
{
	int pivot;
	if (start < end) {
		pivot = partition(a, start, end);
		qsort(a, start, pivot);
		qsort(a, pivot+1, end);	
	}
}



int
main()
{
	int n = 16;
	int a[] = {1, 4, 45, 6, 10, -8};
	int i = 0, j = sizeof(a)/sizeof(a[0]);

	qsort(a, 0, sizeof(a)/sizeof(a[0]));

	while (i < j) {
		if (a[i] + a[j] == n) {
			printf("found..\n");
			break;
		} else if (a[i] + a[j] > n) {
			j--;
		} else {
			i++;
		}
	}	
	
}
