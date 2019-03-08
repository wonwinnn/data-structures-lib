#include <stdio.h>
#define MAXLEN 100

char *strcpyn(char *dst, char *src, size_t n);

int main()
{
	char s[6] = "abcde";
	char d[MAXLEN];
	printf("%s\n", strcpyn(d, s, 5));
	return 0;
}

char *strcpyn(char *dst, char *src, size_t n)
{
	if ((dst == NULL) || (src == NULL))
		return NULL;
	char *strdst;
	strdst = dst;
	for(int i = 0; i < n; i++)
		*dst++ = *src++; //"dst++ = src++" copies the pointer! wrong!
 	return strdst;
}
