#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct IntDynamicArray
{
    int* ptr;
    int size;
    int capacity;
};

void IntDynamicArray__constructor(IntDynamicArray* array)
{
    array -> ptr = (int*) malloc(1 * sizeof(int));
    array -> size = 0;
    array -> capacity = 1;
}

void IntDynamicArray__deconstructor(IntDynamicArray* array)
{
    free(array -> ptr);
}

void IntDynamicArray__extend(IntDynamicArray* array)
{
    int* newArray = (int*) malloc((array -> capacity) * 2 * sizeof(int));
    for(int i = 0; i < (array -> capacity); i++)
        newArray[i] = (array -> ptr)[i];
    free(array -> ptr);
    array -> ptr = newArray;
    array -> capacity *= 2;
}

void IntDynamicArray__shrink(IntDynamicArray* array)
{
    int* newArray = (int*) malloc((array -> capacity) / 2 * sizeof(int));
    for(int i = 0; i < (array -> capacity) / 2; i++)
        newArray[i] = (array -> ptr)[i];
    free(array -> ptr);
    array -> ptr = newArray;
    array -> capacity /= 2;
}

void IntDynamicArray__push_back(IntDynamicArray* array, int element)
{
    if((array -> size) == (array -> capacity))
        IntDynamicArray__extend(array);
    (array -> ptr)[array -> size] = element;
    array -> size += 1;
}

void IntDynamicArray__pop_back(IntDynamicArray* array)
{
    (array -> ptr)[(array -> size) - 1] = -7777;
    array -> size -= 1;

    if((array -> size) <= (array -> capacity) / 2)
        IntDynamicArray__shrink(array);
}

void IntDynamicArray__print_whole_array(IntDynamicArray* array)
{
    for(int i = 0; i < array -> capacity; i++)
        printf("%d ", (array -> ptr)[i]);
    printf("\n");
}

int main()
{
    IntDynamicArray arr;
    IntDynamicArray__constructor(&arr);
    int command;
    while(true)
    {
        // input action
        printf("action = ");
        scanf("%d", &command);

        // determine which action
        if(command == 0)
        {
            IntDynamicArray__deconstructor(&arr);
            break;
        }
        else if(command == 1)
        {
            int buffer;
            printf("element to add = ");
            scanf("%d", &buffer);
            IntDynamicArray__push_back(&arr, buffer);
        }
        else if(command == 2)
        {
            IntDynamicArray__pop_back(&arr);
        }

        printf("whole array = ");
        IntDynamicArray__print_whole_array(&arr);
    }

    return 0;
}