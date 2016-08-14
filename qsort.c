#include <stdio.h>

void
swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int
partition(int arr[], int start, int end)
{
	int pivot = arr[end];
	int j;
	int i = start - 1;
	for (j = start; j < end; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}	
	}
	swap(&arr[i+1], &arr[j]);
	return (i+1);
}

void
qsort(int arr[], int start, int end)
{
	if (start < end) {
		int pivot = partition(arr, start, end);
		qsort(arr, start, pivot-1);
		qsort(arr, pivot+1, end);
	}
}

int
main()
{
	int j;
	//int arr[] = {5, 4, 100, 7, 6, 20, 8};
	int arr[] = {1, 5, 9, 10, 7};
	int n = sizeof(arr)/sizeof(arr[0]);

	qsort(arr, 0, n-1);
	for (j = 0; j < n; j++) {
		printf("%d ", arr[j]);
	}	
}
