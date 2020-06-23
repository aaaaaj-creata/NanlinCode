//硬币找零问题动态规划算法
#include<stdio.h>
#include<stdlib.h>
int coin[3] = { 1, 3, 5 };			/* 硬币种类	*/
int coin_kind_num = 3;				/* 硬币种类数量 */
int sum = 7;						/* 找零钱数 */
int min_coin_num;					/* 硬币最少数 */
int coin_kind[1000];				/* 存放最少数的方案 */
bool is_find = false;				/* 是否找到硬币 */

/*  函数：打印方案
	打印存放找零方案的 数组coin_kind[]
*/
bool output() {
	for (int i = 0; i < 1000; i++)
	{
		if (coin_kind[i] == -1) break;
		printf("   %d ", coin_kind[i]);

	}
	printf("\n");

	return coin_kind;
}

/* 	函数：初始化方案数组
	初始化存放找零方案的数字 ，使元素全部为 0，以便判断输出
*/
void initCoinKind() {
	for (int i = 0; i < 100; i++) coin_kind[i] = -1;
}

/* 函数：查找基本函数
   该函数用于给定 指定硬币数 和 指定应找零的钱数，看是否能找开，用的回溯法查找.
   思想是 若存在对于给定应找零的钱数 sum，存在最少硬币数 num，则对于 sum - coin[i] ( i = 0, ..., coin_kind_num - 1)
   仍然存在最少硬币数 num - 1, 类似于 最短路径那个 dijkstra算法 。

   @param   num    指定硬币数
   @param   sum    指定应找零的钱数
 */
bool findCoin(int num, int sum) {

	/* 函数逻辑

		若 给定指定硬币数为 0 , 即此时已到期待边界，若此时硬币数
			等于 0 ，说明已经找开，找到方案，赋值 is_find = true ( 作为 连续查找终止条件 )。
			大于 0 ，说明未找开， 此时剩余应找开金额大于0。
			小于 0 , 说明此时剩余金额小于 0，不满足。
		若 给定指定金额硬币数 不为 0（及 大于 0），说明此时未搜寻完，执行
			遍历存放硬币种类的数组 coin[]， 将当前遍历对象 存放到 *指定下标* 的
			找零方案数组 coin_kind[] 中。递归执行 该函数，硬币数 - 1，应找零数 - 遍历对象硬币值

	*/

	if (num == 0)
	{
		if (sum == 0) {
			is_find = true;
			printf("找到最少硬币数 %d: ", min_coin_num);
			output();
			return true;
		}
		else if (sum > 0) {

			return false;
		}
		else {

			return false;
		}
	}
	else
	{
		for (int i = 0; i < coin_kind_num; i++)
		{
			coin_kind[num - 1] = coin[i];
			findCoin(num - 1, sum - coin[i]);
		}
	}
}

/* 	函数：硬币数逐渐 + 1 查找
	由于查找方案基本函数只能给定指定硬币数 num 和指定找零数 sum，
	所以 应该使得指定硬币数从小到大， 从 1 开始，每次查找完毕判断 is_find 的值，
	若为 false 则 num + 1，继续查找
	否则 退出循环查找完毕。

 */
bool startFind() {
	int num = 1;
	while (!is_find) {
		min_coin_num = num;
		findCoin(num, sum);
		num++;
	}

	return is_find;
}
int main() {
	initCoinKind();		/* 初始化存放方案的数组 */
	startFind();
}
