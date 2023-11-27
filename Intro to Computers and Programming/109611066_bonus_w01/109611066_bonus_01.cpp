#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
char *mystrchr(const char *s, int c)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == c)
			return (char *)(s + i);
		i++;
	}
	return 0;
}

char *mystrrchr(const char *s, int c)
{
	char* result = NULL;
	while(*s != '\0')
	{
		if(*s == c)
			result = (char *)s;
		s++;
	}
	return result;
}

size_t mystrspn(const char *s, const char *accept)
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
	{
		int flag = 0;
		for(int j = 0; accept[j] != '\0'; j++)
		{
			if(s[i] == accept[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			return i;
	}
	return i;
}

size_t mystrcspn(const char *s, const char *reject)
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
	{
		for(int j = 0; reject[j] != '\0'; j++)
		{
			if(s[i] == reject[j])
				return i;
		}
	}
	return i;
}

char *mystrpbrk(const char *s, const char *accept)
{
	for(int i = 0; s[i] != '\0'; i++)
	{
		for(int j = 0; accept[j] != '\0'; j++)
			if(s[i] == accept[j])
				return (char*)(s + i);
	}
	return NULL;
}

char *mystrstr(const char *haystack, const char *needle)
{
	int i, j;
	for(i = 0; haystack[i] != '\0'; i++)
	{
		for(j = 0; needle[j] != '\0'; j++)
		{
			if(haystack[i + j] != needle[j])
				break;
		}
		if(needle[j] == '\0')
			return (char*)(haystack + i);
	}
	return NULL;
}

char *mystrtok(char *str, const char *delim)
{
	static char *last = NULL;
	if(str != NULL)
		last = str;
	if(last == NULL)
		return NULL;
	
	// skip the delim
	while(*last != '\0')
	{
		int flag = 0;
		for(int i = 0; delim[i] != '\0'; i++)
		{
			if(*last == delim[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			break;
		last++;
	}

	char *result = last;
	int i;
	for(i = 0; last[i] != '\0'; i++)
	{
		int flag = 0;
		for(int j = 0; delim[j] != '\0'; j++)
		{
			if(last[i] == delim[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	if(last[i] == '\0')
		last = NULL;
	else
	{
		last[i] = '\0';
		last = last + i + 1;
	}
	return result;
}

char *mysubstring(char *str, int start, int end)
{
	char *result = (char *)malloc(sizeof(char) * (end - start + 1));
	for(int i = 0; i < end - start; i++)
		result[i] = str[start + i];
	result[end - start] = '\0';
	return result;
}

int mystrlen(char *str)
{
	int i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}

int mystrcmp(const char *s1, const char *s2)
{
	int i;
	for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if(s1[i] != s2[i])
			return s1[i] - s2[i];
	}
	return s1[i] - s2[i];
}