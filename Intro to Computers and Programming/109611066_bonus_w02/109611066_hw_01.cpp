#include <stdio.h>
#include <stdlib.h>
// #define VERBOSE

/***********
** String **
***********/
struct String
{
    char *str;
    int len;
    int cap;
};

void String__constructor(struct String *s)
{
    s->len = 0;
    s->cap = 10;
    s->str = (char *)malloc(sizeof(char) * s->cap);
    s->str[0] = '\0';
}

void String__deconstructor(struct String *s)
{
    free(s->str);
    s->len = 0;
    s->cap = 0;
}

void String__delete(struct String *s)
{
    String__deconstructor(s);
    String__constructor(s);
}

void String__resize(struct String *s, int newCap)
{
    char *newStr = (char *)malloc(sizeof(char) * newCap);
    for(int i = 0; i < s->len; i++)
        newStr[i] = s->str[i];
    free(s->str);
    s->str = newStr;
    s->cap = newCap;
}

void String__append(struct String *s, char c)
{
    if(s->len == s->cap)
        String__resize(s, s->cap * 2);
    s->str[s->len] = c;
    s->len++;
}

struct String* String__duplicate(struct String *s)
{
    struct String* newStr = (struct String *)malloc(sizeof(struct String));
    newStr->len = s->len;
    newStr->cap = s->cap;
    newStr->str = (char *)malloc(sizeof(char) * newStr->cap);
    for(int i = 0; i < s->len; i++)
        newStr->str[i] = s->str[i];
    return newStr;
}

void String__stdin(struct String *s)
{
    char c;
    while(true)
    {
        c = getchar();
        if(c == '\n')
            break;
        String__append(s, c);
    }
}

char String__at(struct String *s, int index)
{
    if(index < 0 || index >= s->len)
        return '\0';
    return s->str[index];
}

int String__getLen(struct String *s)
{
    return s->len;
}

int String__diff(struct String *s1, struct String *s2)
{
    if(s1->len != s2->len)
        return -1;
    int diff = 0;
    for(int i = 0; i < s1->len; i++)
        if(s1->str[i] != s2->str[i])
            diff++;
    return diff;
}

void String__print(struct String *s)
{
    for(int i = 0; i < s->len; i++)
        printf("%c", s->str[i]);
}

/*************
** WordList **
*************/
struct WordList
{
    struct String *words;
    int len;
    int cap;
};

void WordList__constructor(struct WordList *wl)
{
    wl->len = 0;
    wl->cap = 10;
    wl->words = (struct String *)malloc(sizeof(struct String) * wl->cap);
}

void WordList__deconstructor(struct WordList *wl)
{
    for(int i = 0; i < wl->len; i++)
        String__deconstructor(&wl->words[i]);
    free(wl->words);
    wl->len = 0;
    wl->cap = 0;
}

void WordList__resize(struct WordList *wl, int newCap)
{
    struct String *newWords = (struct String *)malloc(sizeof(struct String) * newCap);
    for(int i = 0; i < wl->len; i++)
        newWords[i] = wl->words[i];
    free(wl->words);
    wl->words = newWords;
    wl->cap = newCap;
}

void WordList__append(struct WordList *wl, struct String *word)
{
    if(wl->len == wl->cap)
        WordList__resize(wl, wl->cap * 2);
    wl->words[wl->len] = *String__duplicate(word);
    wl->len++;
}

void WordList__setWithFile(struct WordList *wl, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    struct String word;
    String__constructor(&word);
    char c;
    while(true)
    {
        c = fgetc(fp);
        if(c == EOF)
            break;
        if(c == '\n')
        {
            WordList__append(wl, &word);
            String__delete(&word);
        }
        else
            String__append(&word, c);
    }
    fclose(fp);
    String__deconstructor(&word);
}

void WordList__print(struct WordList *wl)
{
    for(int i = 0; i < wl->len; i++)
    {
        for(int j = 0; j < wl->words[i].len; j++)
            printf("%c", wl->words[i].str[j]);
        printf("\n");
    }
}

int WordList__getLen(struct WordList *wl)
{
    return wl->len;
}

void WordList__at(struct WordList *wl, int index, struct String *word)
{
    if(index < 0 || index >= wl->len)
        return;
    word = String__duplicate(&wl->words[index]);
}

/**********
** Queue **
**********/
struct Queue
{
    int* arr;
    int start;
    int end;
    int cap;
};

void Queue__constructor(struct Queue *q)
{
    q->start = 0;
    q->end = 0;
    q->cap = 10;
    q->arr = (int *)malloc(sizeof(int) * q->cap);
}

void Queue__deconstructor(struct Queue *q)
{
    free(q->arr);
    q->start = 0;
    q->end = 0;
    q->cap = 0;
}

void Queue__print(struct Queue *q)
{
    printf("start: %d, end: %d, cap: %d\n", q->start, q->end, q->cap);
    for(int i = q->start; i != q->end; i = (i + 1) % q->cap)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void Queue__resize(struct Queue *q, int newCap)
{
#ifdef VERBOSE
    printf("resizing to %d\n", newCap);
    Queue__print(q);
#endif
    if(newCap < q->end - q->start)
        return;
    int *newArr = (int *)malloc(sizeof(int) * newCap);
    if(newArr == NULL)
        return;
    for(int i = 0; (q->start + i) % q->cap != q->end; i++)
        newArr[i] = q->arr[(i + q->start) % q->cap];
    free(q->arr);
    q->arr = newArr;
    int newEnd = (q->end - q->start + q->cap) % q->cap;
    q->cap = newCap;
    q->start = 0;
    q->end = newEnd;
#ifdef VERBOSE
    printf("resized to %d\n", newCap);
    Queue__print(q);
#endif
}

void Queue__push(struct Queue *q, int val)
{
    if((q->end + 1) % q->cap == q->start)
        Queue__resize(q, q->cap * 2);
    q->arr[q->end] = val;
    q->end = (q->end + 1) % q->cap;
}

int Queue__pop(struct Queue *q)
{
    if(q->start == q->end)
        return -1;
    int val = q->arr[q->start];
    q->start = (q->start + 1) % q->cap;
    return val;
}

/**********
** Stack **
**********/
struct Stack
{
    int* arr;
    int top;
    int cap;
};

void Stack__constructor(struct Stack *s)
{
    s->top = 0;
    s->cap = 10;
    s->arr = (int *)malloc(sizeof(int) * s->cap);
}

void Stack__deconstructor(struct Stack *s)
{
    free(s->arr);
    s->top = 0;
    s->cap = 0;
}

void Stack__resize(struct Stack *s, int newCap)
{
    int *newArr = (int *)malloc(sizeof(int) * newCap);
    for(int i = 0; i < s->top; i++)
        newArr[i] = s->arr[i];
    free(s->arr);
    s->arr = newArr;
    s->cap = newCap;
}

void Stack__push(struct Stack *s, int val)
{
    if(s->top == s->cap)
        Stack__resize(s, s->cap * 2);
    s->arr[s->top] = val;
    s->top++;
}

int Stack__pop(struct Stack *s)
{
    if(s->top == 0)
        return -1;
    s->top--;
    return s->arr[s->top];
}

/*********
** Main **
*********/
int main()
{
    // read words from file
    struct WordList wl;
    WordList__constructor(&wl);
    WordList__setWithFile(&wl, "DAMwords.txt");

    // user input
    struct String strt, dest;
    String__constructor(&strt);
    String__constructor(&dest);
    String__stdin(&strt);
    String__stdin(&dest);
    int strtIndex = -1, destIndex = -1;
    for(int i = 0; i < wl.len; i++)
    {
        if(String__diff(&wl.words[i], &strt) == 0)
            strtIndex = i;
        if(String__diff(&wl.words[i], &dest) == 0)
            destIndex = i;
    }

    // use BFS to find the shortest path
    struct Queue q;
    Queue__constructor(&q);
    Queue__push(&q, strtIndex);
    int *prev = (int *)malloc(sizeof(int) * WordList__getLen(&wl));
    for(int i = 0; i < WordList__getLen(&wl); i++)
        prev[i] = -1;
    int *visited = (int *)malloc(sizeof(int) * WordList__getLen(&wl));
    for(int i = 0; i < WordList__getLen(&wl); i++)
        visited[i] = 0;
    visited[strtIndex] = 1;
    while(q.start != q.end)
    {
#ifdef VERBOSE
        printf("queue: ");
        for(int i = q.start; i != q.end; i = (i + 1) % q.cap)
        {
            String__print(&wl.words[q.arr[i]]);
            printf(" ");
        }
        printf("\n");
#endif
        int cur = Queue__pop(&q);
#ifdef VERBOSE
        printf("cur: ");
        String__print(&wl.words[cur]);
        printf("\n");
#endif
        if(cur == destIndex)
            break;
        for(int i = 0; i < WordList__getLen(&wl); i++)
        {
            if(visited[i] == 0 && String__diff(&wl.words[cur], &wl.words[i]) == 1)
            {
#ifdef VERBOSE
                printf("found: ");
                String__print(&wl.words[i]);
                printf("\n");
#endif
                Queue__push(&q, i);
                visited[i] = 1;
                prev[i] = cur;
            }
        }
    }

    // print the path
    struct Stack s;
    Stack__constructor(&s);
    int cur = destIndex;
    while(cur != -1)
    {
        Stack__push(&s, cur);
        cur = prev[cur];
    }
    if(s.top == 1)
        printf("Does not exist.\n");
    else
    {
        while(s.top != 0)
        {
            int cur = Stack__pop(&s);
            String__print(&wl.words[cur]);
            if(s.top != 0)
                printf(" >> ");
        }
        printf("\n");
    }
    return 0;
}