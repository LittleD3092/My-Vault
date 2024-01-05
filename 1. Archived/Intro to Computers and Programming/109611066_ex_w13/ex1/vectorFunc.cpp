#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

// construct the vector by given length
vector* vector_construct(int length) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->length = length;
    v->vec = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++) {
        v->vec[i] = 0;
    }
    return v;
}