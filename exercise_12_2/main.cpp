#include <iostream>  
#include "SqQueue.h"  

#define ITEM 9                                                                //ITEM宏表示待处理集合中元素的项数  

using namespace std;

int R[ITEM][ITEM] = {                                                      //该矩阵用来存储待划分集合中元素之间的冲突关系，0代表不冲突，1代表冲突  
{0, 1, 0, 0, 0, 1, 0, 0, 0},
{1, 0, 0, 0, 1, 1, 0, 1, 1},
{0, 0, 0, 0, 0, 1, 1, 0, 0},
{0, 0, 0, 0, 1, 0, 0, 0, 1},
{0, 1, 0, 1, 0, 0, 1, 0, 1},
{1, 1, 1, 0, 0, 0, 1, 0, 0},
{0, 0, 1, 0, 1, 1, 0, 0, 0},
{0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 1, 0, 1, 1, 0, 0, 0, 0} };

int result[ITEM];                                                               //该数组用来存放分组后的结果  

/***********************************************************
 *功能：划分给定集合的无冲突子集
 *输入：集合中元素关系集，集合中基本元素的个数，存储结果的数组
 *时间：2016年10月17日
 ***********************************************************/
void DivideSubset(int R[][ITEM], int n, int result[])
{
	int PreIndex = n, GroupIndex = 0;                       //PreIndex表示前一次出队列的元素序号，GroupIndex表示当前分配的组的编号  
	SqQueue SQ;
	InitQueue(SQ);                                                       //初始化一个队列，长度与被划分集合的基本元素个数相同，本例中取9  
	for (int i = 0; i < n; ++i)                                        //该循环用来给分配的队列附上初值，该例中为（0-8）  
	{
		EnQueue(SQ, i);
	}
	int currVal;                                                            //该变量用来表示当前待考察的队列中的一个元素  
	int clash[ITEM];                                                     //该数组用来表示当前分配组的已经添加的元素与其它元素的关系，即是否产生冲突  
	while (!QueueEmpty(SQ))                                       //该循环用来处理队列中的每一个元素，知道所有元素都分配完成时结束  
	{
		DeQueue(SQ, currVal);                                   //取出一个元素进行处理  
		if (currVal <= PreIndex)                                  //如果当前元素小于前一个，则表示队列已经循环遍历所有的元素，应该新建另一个组  
		{
			++GroupIndex;
			for (int i = 0; i < n; ++i)
				clash[i] = 0;
		}
		if (clash[currVal] == 0)                                   //查询当前分配组的clash数组的值，当值为0时表示该元素没有与当前组中已经添加的元素产生冲突  
		{
			result[currVal] = GroupIndex;              //将当前元素编入该组  
			for (int i = 0; i < n; ++i)                       //添加与被添加元素冲突的信息  
				clash[i] += R[currVal][i];
		}
		else
		{
			EnQueue(SQ, currVal);                          //如果该元素与当前组中的所有元素都冲突，将该元素继续入栈  
		}
		PreIndex = currVal;
	}
}

int main()
{
	DivideSubset(R, ITEM, result);

	for (const auto& e : result)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}