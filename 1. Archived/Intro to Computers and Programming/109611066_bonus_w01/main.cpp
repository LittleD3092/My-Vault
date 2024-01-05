#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "my_string.h"

int main(){
	char c;
	char _;
	char *ret = NULL;
	char str[128] = {0};
	char str1[128] = {0};
	char str2[128] = {0};

	printf("Testing mystrchr...\n");
	printf("Please input a string: ");
	fgets(str, 128, stdin);
	str[strnlen(str, 128) - 1] = 0;

	// mystrchr
	printf("Please input a character: ");
	c = getchar(); fflush(stdin);
	_ = getchar(); fflush(stdin);
	ret = mystrchr(str, c);

	if(ret != NULL) printf("The string %s after first \"%c\" is %s.\n", str, c, ret);
	else printf("The string %s does not contain \"%c\".\n", str, c);


	// mystrrchr
	printf("Testing mystrrchr...\n");
	printf("Please input a character: ");
	c = getchar(); fflush(stdin);
	_ = getchar(); fflush(stdin);
	ret = mystrrchr(str, c);
	
	if(ret != NULL) printf("The last %c index is %ld.\n", c, ret - str);
	else printf("The string %s does not contain \"%c\".\n", str, c);

	// mystrspn
	printf("Testing mystrspn...\n");
	printf("Please input string1: ");
	fgets(str1, 128, stdin);
	printf("Please input string2: ");
	fgets(str2, 128, stdin);
	str1[strnlen(str1, 128) - 1] = 0;
	str2[strnlen(str2, 128) - 1] = 0;

	printf("The length of the same string from start is %lu.\n", mystrspn(str1, str2));

	// mystrcspn
	printf("Testing mystrcspn...\n");
	printf("Please input string1: ");
	fgets(str1, 128, stdin);
	printf("Please input string2: ");
	fgets(str2, 128, stdin);
	str1[strnlen(str1, 128) - 1] = 0;
	str2[strnlen(str2, 128) - 1] = 0;

	printf("The first index of str1 contain str2's character is %lu.\n", mystrcspn(str1, str2));

	// mystrpbrk
	printf("Testing mystrpbrk...\n");
	ret = mystrpbrk(str1, str2);
	
	if(ret != NULL) printf("The remain string start with character which in str2 is %s.\n", ret);
	else printf("The characters in str1 dose not in str2\n");

	// mystrstr
	printf("Testing mystrstr...\n");
	printf("Please input string1: ");
	fgets(str1, 128, stdin);
	printf("Please input string2: ");
	fgets(str2, 128, stdin);
	str1[strnlen(str1, 128) - 1] = 0;
	str2[strnlen(str2, 128) - 1] = 0;

	ret = mystrstr(str1, str2);

	if(ret != NULL) printf("The substring in str1 is %s.\n", ret);
	else printf("There is no substr in str1.\n");


	// mystrtok
	printf("Testing mystrtok...\n");
	printf("Please input string1: ");
	fgets(str1, 128, stdin);
	printf("Please input string2: ");
	fgets(str2, 128, stdin);
	str1[strnlen(str1, 128) - 1] = 0;
	str2[strnlen(str2, 128) - 1] = 0;

	char *token = mystrtok(str1, str2);

	while(token != NULL){
		printf("%s\n", token);
		token = mystrtok(NULL, str2);
	}

	return 0;
}


