#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer()
{
    char c = 0;
    while((c = getchar()) != '\n' && c != 0 && c != ' ');
}

int min(int num1, int num2)
{
    if(num1 <= num2)
        return num1;
    else // num2 < num1
        return num2;
}

struct String
{
    char* str;
    int len;
    int capacity;
};

void String__constructor(struct String* strObj, char* str)
{
    if(str == 0)
    {
        strObj->len = 0;
        strObj->str = (char*)malloc(sizeof(char) * (strObj->len + 1));
        strObj->str[strObj->len] = '\0';
        strObj->capacity = strObj->len;
        return;
    }
    strObj->len = 0;
    while(str[strObj->len] != '\0')
        strObj->len++;
    strObj->str = (char*)malloc(sizeof(char) * (strObj->len + 1));
    for(int i = 0; i < strObj->len; i++)
        strObj->str[i] = str[i];
    strObj->str[strObj->len] = '\0';
    strObj->capacity = strObj->len;
}

void String__copy(struct String* strObj1, struct String* strObj2)
{
    free(strObj1->str);
    strObj1->len = strObj2->len;
    strObj1->str = (char*)malloc(sizeof(char) * (strObj1->len + 1));
    for(int i = 0; i < strObj1->len; i++)
        strObj1->str[i] = strObj2->str[i];
    strObj1->str[strObj1->len] = '\0';
    strObj1->capacity = strObj1->len;
}

void String__destructor(struct String* strObj)
{
    free(strObj->str);
}

void String__resize(struct String* strObj, int newCapacity)
{
    char* newStr = (char*)malloc(sizeof(char) * (newCapacity + 1));
    for(int i = 0; i < min(strObj->len, newCapacity); i++)
        newStr[i] = strObj->str[i];
    newStr[strObj->len] = '\0';
    free(strObj->str);
    strObj->str = newStr;
    strObj->capacity = newCapacity;
}

void String__stdInputLine(struct String* strObj)
{
    clearInputBuffer();
    int i = 0;
    while(1)
    {
        char c = getchar();
        if(c == '\n' || c == 0)
            break;
        if(i >= strObj->capacity)
            String__resize(strObj, strObj->capacity * 2);
        strObj->str[i] = c;
        i++;
    }
}

void String__stdInput(struct String* strObj, int len)
{
    clearInputBuffer();
    free(strObj->str);
    strObj->len = len;
    strObj->str = (char*)malloc(sizeof(char) * (strObj->len + 1));
    for(int i = 0; i < strObj->len; i++)
        strObj->str[i] = getchar();
}

int String__length(struct String* strObj)
{
    return strObj->len;
}

struct BookSet
{
    struct String* books;
    int len;
};

void BookSet__constructor(struct BookSet* bookSetObj, int len)
{
    bookSetObj->books = (struct String*)malloc(sizeof(struct String) * len);
    bookSetObj->len = len;
    for(int i = 0; i < len; i++)
        String__constructor(&bookSetObj->books[i], 0);
}

void BookSet__destructor(struct BookSet* bookSetObj)
{
    for(int i = 0; i < bookSetObj->len; i++)
        String__destructor(&bookSetObj->books[i]);
    free(bookSetObj->books);
}

void BookSet__add(struct BookSet* BookSetObj, int index, struct String* book)
{
    if(index >= BookSetObj->len)
        return;
    else if(BookSetObj->books[index].len != 0)
        return;
    String__copy(&BookSetObj->books[index], book);
}

void BookSet__delete(struct BookSet* BookSetObj, int index)
{
    if(index >= BookSetObj->len)
        return;
    else if(BookSetObj->books[index].len == 0)
        return;
    String__destructor(&BookSetObj->books[index]);
    String__constructor(&BookSetObj->books[index], 0);
}

void BookSet__exchange(struct BookSet* BookSetObj1, int index1, struct BookSet* BookSetObj2, int index2)
{
    if(index1 >= BookSetObj1->len || index2 >= BookSetObj2->len)
        return;

    struct String temp = BookSetObj1->books[index1];
    BookSetObj1->books[index1] = BookSetObj2->books[index2];
    BookSetObj2->books[index2] = temp;
}

void BookSet__print(struct BookSet* BookSetObj)
{
    for(int i = 0; i < BookSetObj->len; i++)
    {
        if(BookSetObj->books[i].len == 0)
            printf("(null)\n");
        else
            printf("%s\n", BookSetObj->books[i].str);
    }
}

int main()
{
    struct BookSet A, B;
    int m, n;
    scanf("%d %d", &m, &n);
    BookSet__constructor(&A, m);
    BookSet__constructor(&B, n);

    int p = 0;
    while(1)
    {
        scanf("%d", &p);
        if(p == 0) // add
        {
            int x, y, s;
            scanf("%d %d %d", &x, &y, &s);
            struct String book;
            String__constructor(&book, 0);
            String__stdInput(&book, s);
            if(x == 0)
                BookSet__add(&A, y, &book);
            else if(x == 1)
                BookSet__add(&B, y, &book);
            String__destructor(&book);
        }
        else if(p == 1) // delete
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if(x == 0)
                BookSet__delete(&A, y);
            else if(x == 1)
                BookSet__delete(&B, y);
        }
        else if(p == 2) // exchange
        {
            int x, y;
            scanf("%d %d", &x, &y);
            BookSet__exchange(&A, x, &B, y);
        }
        else if(p == 3) // exit
            break;

        printf("A:\n");
        BookSet__print(&A);
        printf("B:\n");
        BookSet__print(&B);
        printf("\n");
    }

    return 0;
}