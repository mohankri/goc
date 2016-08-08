#include <stdio.h>

int
main()
{
	int x = 100;
	int y = 101;

	if ((x ^ y) < 0) {
		printf("numbers has opposite sign \n");
		return (1);
	} 
	printf("numbers has same sign \n");
	return (0);
}
