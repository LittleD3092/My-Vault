#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person
{
    int id;
    int money;
    struct Person *next;
};

struct PersonLine
{
    struct Person *head;
};

void PersonLine__leave(struct PersonLine *personLine, int position)
{
    if(personLine->head == NULL)
    {
        return;
    }
    struct Person *current = personLine->head;
    struct Person *previous = NULL;
    int count = 0;
    while(current != NULL)
    {
        if(count == position)
        {
            if(previous == NULL)
                personLine->head = current->next;
            else
                previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
        count++;
    }
}

void PersonLine__join(struct PersonLine *personLine, int id, int money)
{
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
    newPerson->id = id;
    newPerson->money = money;
    newPerson->next = NULL;

    if(personLine->head == NULL)
    {
        personLine->head = newPerson;
        newPerson->next = NULL;
        return;
    }
    
    struct Person *current = personLine->head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newPerson;
}

void PersonLine__insert(struct PersonLine *personLine, int id, int money, int position)
{
    struct Person *newPerson = (struct Person *)malloc(sizeof(struct Person));
    newPerson->id = id;
    newPerson->money = money;
    newPerson->next = NULL;

    if(personLine->head == NULL)
    {
        if(position == 0)
        {
            personLine->head = newPerson;
            newPerson->next = NULL;
            return;
        }
        else
        {
            return;
        }
    }

    struct Person *current = personLine->head;
    struct Person *previous = NULL;
    int count = 0;
    while(current != NULL)
    {
        if(count == position)
        {
            if(previous == NULL)
            {
                personLine->head = newPerson;
                newPerson->next = current;
            }
            else
            {
                previous->next = newPerson;
                newPerson->next = current;
            }
            break;
        }
        previous = current;
        current = current->next;
        count++;
    }
}

void PersonLine__print(struct PersonLine *PersonLine)
{
    struct Person *current = PersonLine->head;
    while(current != NULL)
    {
        printf("ID money: ");
        printf("%d %d\n", current->id, current->money);
        current = current->next;
    }
}

int main()
{
    struct PersonLine personLine;
    personLine.head = NULL;
    int numInput;
    scanf("%d", &numInput);
    for(int i = 0; i < numInput; i++)
    {
        int size;
        scanf("%d", &size);
        if(size == 1)
        {
            int position;
            scanf("%d", &position);
            PersonLine__leave(&personLine, position);
        }
        else if(size == 2)
        {
            int id, money;
            scanf("%d %d", &id, &money);
            PersonLine__join(&personLine, id, money);
        }
        else if(size == 3)
        {
            int id, money, position;
            scanf("%d %d %d", &id, &money, &position);
            PersonLine__insert(&personLine, id, money, position);
        }
    }
    PersonLine__print(&personLine);
    return 0;
}