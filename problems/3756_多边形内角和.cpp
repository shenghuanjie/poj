/*
3756: 多边形内角和
http://bailian.openjudge.cn/practice/3756/


描述
在欧几里德几何中，n边形的内角和是(n-2)*180°。已知其中(n-1)个内角的度数，就能计算出剩下的一个未知内角的度数。请编写一个程序，来解决这个问题。
输入
第1行只有一个整数n(2第2行有(n-1)个正整数，是每个已知内角的度数。相邻两个整数之间用单个空格隔开。数据保证给定多边形合法。
输出
一个正整数，为未知内角的度数。
样例输入
3
45 60


样例输出
75


*/

#include<iostream>
using namespace std;
int main()
{
	int n,x,sum;
	while(cin>>n)
	{
		if(n==0)return 0;
		sum=180*(n-2);
		for(;n>1;n--)
		{
			cin>>x;
			sum-=x;
		}
		cout<<sum<<endl;
	}
	return 0;
}
