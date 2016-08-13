#include <stdio.h>

int
main()
{
	int i=0;
	int sum = 0;
	int a[] = {1, 2, 3, 4, 6, 7, 8};
	int n = sizeof(a)/sizeof(a[0]);
	for (i = 0; i < n; i++) {
		sum += a[i];
	}
	printf("missing number %d\n", ((n+1) * (n+2)/2) - sum);
}
