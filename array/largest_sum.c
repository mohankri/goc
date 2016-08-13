#include <stdio.h>

int
main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int i = 0;
	int sum = a[0];
	int largest = 0;
	for (i = 1; i < sizeof(a)/sizeof(a[0]); i++) {
		sum += a[i];
		if (sum < 0) {
			sum = 0;
		}
		largest = largest < sum ? sum : largest;
	}
	printf("largest sum %d\n", largest);
	return (largest);
}
