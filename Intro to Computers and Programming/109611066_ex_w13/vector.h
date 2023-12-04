#ifndef __vector__
#define __vector__

typedef struct _vector {
	int length;
	int* vec;
}vector;

vector* vector_construct(int length);

#endif
