/*
2755: 神奇的口袋
http://bailian.openjudge.cn/practice/2755/


描述
有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
输入
输入的第一行是正整数n (1 <= n <= 20)，表示不同的物品的数目。接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
输出
输出不同的选择物品的方式的数目。
样例输入
3
20
20
20

样例输出
3

*/

#include<iostream>
using namespace std;
int n,thing[22],result=0;
int cmp(const void *a,const void *b)
{
	if(*(int *)a>*(int *)b)
		return -1;
	else 
		return 1;
}
bool use[22];
void get(int goal,int start)
{
	int i;
	for(i=start;i<n;i++)
	{
		if(use[i])continue;
		if(thing[i]==goal)	
		{result++;continue;}
		else if(thing[i]<goal)
		{use[i]=true;get(goal-thing[i],i+1);use[i]=false;}
		use[i]=true;
	}
	for(i=start;i<n;i++)
		use[i]=false;
}
int main()
{
	cin>>n;
	int i;
	memset(thing,0,sizeof(thing));
	memset(use,0,sizeof(use));
	for(i=0;i<n;i++)
		cin>>thing[i];
	qsort(thing,n,sizeof(int),cmp);
	get(40,0);
	cout<<result<<endl;
}
