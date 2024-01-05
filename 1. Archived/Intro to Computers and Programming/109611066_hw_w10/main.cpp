#include <stdio.h>
#include <assert.h>

char *mystrchr(const char *s, int c);
char *mystrrchr(const char *s, int c);
size_t mystrspn(const char *s, const char *accept);
size_t mystrcspn(const char *s, const char *reject);
char *mystrpbrk(const char *s, const char *accept);
char *mystrstr(const char *haystack , const char *needle);
char *mystrtok(char *str, const char *delim);

int main(){
	char c;
	char *ret = NULL;
	char str[128] = {0};
	char str1[128] = {0};
	char str2[128] = {0};

	fgets(str, 128, stdin);

	// mystrchr
	scanf("%c", &c);
	ret = mystrchr(str, c);
	printf("The string %s after \"%c\" is %s.\n", str, c, ret);

	// mystrrchr
	scanf("%c", &c);
	printf("The last %c index is %ld.\n", c, mystrrchr(str, c) - str);

	// mystrspn
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	printf("The length of the same string from start is %lu.\n", mystrspn(str1, str2));

	// mystrcspn
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	printf("The first index of str1 contain str2's character is %lu.\n", mystrspn(str1, str2));

	// mystrpbrk
	ret = mystrpbrk(str1, str2);
	printf("The remain string start with character which in str2 is %s.", ret);

	// mystrstr
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	ret = mystrstr(str1, str2);
	assert(ret == str2);
	
	printf("The substring in str1 is %s.\n", ret);

	// mystrtok
	fgets(str1, 128, stdin);
	fgets(str2, 128, stdin);

	char *token = mystrtok(str1, str2);

	while(token != NULL){
		printf("%s\n", token);
		token = mystrtok(NULL, str2);
	}

	return 0;
}


