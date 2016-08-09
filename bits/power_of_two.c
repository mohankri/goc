#include <stdio.h>

int
power(int n)
{
	if ((n & (n-1)) == 0) {
		return 1;
	} 
	return (0);
}

int
main()
{
	printf("%s \n", power(2) ? "power of 2" : "not power of 2");
	printf("%s \n", power(3) ? "power of 2" : "not power of 2");
}
