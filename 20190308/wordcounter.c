#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
	int c;
	int n = 0;
	int state = OUT;
	while ((c=getchar()) != EOF) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '\'')
			state = IN;
		else {
			if (state == IN) {
				state = OUT;
				n++;
			}
		}
	}
	printf("%d\n", n);

	return 0;
}
	
