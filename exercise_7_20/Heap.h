#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n);



