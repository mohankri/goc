#include <stdio.h>

int
main()
{
	unsigned long val = 4 * 1000000;		
	unsigned long count = 2;
	unsigned long prev = 1;
	unsigned long next = 1;
	unsigned long sum = 0;
	unsigned long oldprev = 0;
	
	while (prev <= val) {
		if (prev % 2 == 0) 
			sum += prev;
		count++;
		oldprev = prev;
		prev = next;
		next = prev + oldprev;
	}
	printf("%ld \n", sum);

}
