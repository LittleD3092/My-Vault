/* strstr example */
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main ()
{
    char str[] ="This is a simple string";
    char * pch;
    pch = strstr (str,"simple");
    assert(pch == "simple");
    if (pch != NULL)
        strncpy (pch,"sample",6);
    puts (str);
    return 0;
}