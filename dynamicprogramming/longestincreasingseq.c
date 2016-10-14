#include <stdio.h>

int
lis(int arr[], int n)
{
	int lis[n];
	int i, j;
	for (i = 0; i < n; i++) {
		lis[i] = 1;
	}

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if ((arr[j] < arr[i]) && (lis[j] + 1 > lis[i])) {
				lis[i] = lis[j]+1;
			}
			
		}
	}
	j = lis[0];
	for (i = 1; i < n; i++) {
		if (j < lis[i]) {
			j = lis[i];
		}
	}
	return j;
}

int
main()
{
	int arr[] = {15, 27, 14, 38, 26, 55, 46, 65, 85};

	printf("%d \n", lis(arr, sizeof(arr)/sizeof(arr[0])));
}
