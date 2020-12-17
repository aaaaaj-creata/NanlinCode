#include "SqQueue.h"  
#include <stdlib.h>  
#include <iostream>  

using namespace std;

bool InitQueue(SqQueue& Q)
{
	Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
	if (Q.base == nullptr)
		return false;
	Q.front = Q.rear = 0;
	return true;
}

int QueueLength(SqQueue & Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool EnQueue(SqQueue & Q, QElemType e)
{
	if (((Q.rear + 1) % MAXQSIZE) == Q.front)
		return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(SqQueue & Q, QElemType & e)
{
	if (Q.rear == Q.front)
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

void PrintSqQueue(SqQueue & Q)
{
	int i = Q.front;
	while (i != Q.rear)
	{
		cout << Q.base[i] << " ";
		i = (i + 1) % MAXQSIZE;
	}
	cout << endl;
}

bool QueueEmpty(SqQueue & Q)
{
	return (Q.front == Q.rear) ? true : false;
}