#include <stdio.h>
#define MAXLEN 100
int main()
{
	int c, i, j, state;
	char map1[26] = "abcdefghijklmnopqrstuvwxyz";
	char map2[26];
	char code[MAXLEN], result[MAXLEN];

	for (i = 0; i < MAXLEN && (c = getchar()) != '\n'; i++) {
		map2[i] = c; 
	}
	
	while ((c = getchar()) != '\n')
		state = c - '0';
	
	i = 0;
	for (i = 0; i < MAXLEN && (c = getchar()) != EOF; i++) {
		code[i] = c;
	}
	i++;
	code[i] = '\0';
	
	i = 0;
	while (code[i] != '\0') {
		j = 0;
		if (state == 0) {
			while (map2[j] != code[i])
				j++;
			result[i] = map1[j];
		}
		if (state == 1) {
			while (map1[j] != code[i])
				j++;
			result[i] = map2[j];
		}
		i++;
	}
	i++;
	result[i] = '\0';
	printf("%s\n",result);	
	return 0;
}
