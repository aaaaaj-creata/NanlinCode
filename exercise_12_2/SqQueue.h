#ifndef SQQUEUE_H  
#define SQQUEUE_H  

#define MAXQSIZE 10                                                     //队列的最大长度  

typedef int QElemType;

typedef struct
{
	QElemType* base;                                                //初始化的动态分配存储空间  
	int front;                                                              //头指针，若队列不空，指向队列头元素  
	int rear;                                                               //尾指针，若队列不空，指向队列尾元素的下一个位置  
}SqQueue;

bool InitQueue(SqQueue& Q);                                  //按指定大小构造一个顺序空队列Q  
int QueueLength(SqQueue& Q);                               //返回Q的元素的个数，即队列长度  
bool EnQueue(SqQueue& Q, QElemType e);            //插入元素e为Q的新的队尾元素  
bool DeQueue(SqQueue& Q, QElemType& e);         //对头元素出队列  
void PrintSqQueue(SqQueue& Q);                           //打印顺序队列  
bool QueueEmpty(SqQueue& Q);                            //判断给定的队列是否为空队列  

#endif  /* SqQueue.h */  
