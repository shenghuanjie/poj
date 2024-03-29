/*
D: 排列
http://cxsjsx.openjudge.cn/contest1793/D/


描述
题目描述：   大家知道，给出正整数n，则1到n这n个数可以构成n！种排列，把这些排列按照从小到大的顺序（字典顺序）列出，如n=3时，列出1 2 3，1 3 2，2 1 3，2 3 1，3 1 2，3 2 1六个排列。任务描述：   给出某个排列，求出这个排列的下k个排列，如果遇到最后一个排列，则下1排列为第1个排列，即排列1 2 3…n。   比如：n = 3，k=2 给出排列2 3 1，则它的下1个排列为3 1 2，下2个排列为3 2 1，因此答案为3 2 1。
输入
第一行是一个正整数m，表示测试数据的个数，下面是m组测试数据，每组测试数据第一行是2个正整数n( 1 <= n < 1024 )和k(1<=k<=64)，第二行有n个正整数，是1，2 … n的一个排列。
输出
对于每组输入数据，输出一行，n个数，中间用空格隔开，表示输入排列的下k个排列。
样例输入
3
3 1
2 3 1
3 1
3 2 1
10 2	
1 2 3 4 5 6 7 8 9 10

样例输出
3 1 2
1 2 3
1 2 3 4 5 6 7 9 8 10

来源
qinlu@POJ

*/

#include<iostream>
using namespace std;
int main()
{
short m, n, k, i, j, t, a[1024];
scanf("%d",&m);
while(m--){
scanf("%d %d", &n, &k);
for(i = 0; i < n; i++)
scanf("%d", &a[i]);
while(k--){
i = n - 1; j = n - 1;
while( i && a[i] < a[i - 1]) i--;
if(i){i--;
while(a[j] < a[i]) j--;
t = a[i]; a[i++] = a[j]; a[j] = t;
j = n - 1;
}
while(i < j){
t = a[i]; a[i] = a[j]; a[j] = t;
i++; j--;
}
}
printf("%d", a[0]);
for(i = 1; i < n; i++)
printf(" %d", a[i]);
printf("\n");
}
return 0;
}
