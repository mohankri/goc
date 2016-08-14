#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
permute(char *str, int start, int len)
{
	int i;
	char ch;
	if (start == len) {
		printf("%s \n", str);
	} else {
		for (i = start; i < len; i++) {
			ch = str[start];
			str[start] = str[i];
			str[i] = ch;

			permute(str, start+1, len);		

			ch = str[i];
			str[i] = str[start];
			str[start] = ch;	
		}
	}
}

int
main()
{
	char str[] = "ABCD";

	permute(str, 0, strlen(str));
}
