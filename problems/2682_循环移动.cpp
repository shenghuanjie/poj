/*
2682: 循环移动
http://bailian.openjudge.cn/practice/2682/


描述
给定一组整数，要求利用数组把这组数保存起来，再利用指针实现对数组中的数循环移动。假定共有n个整数，则要使前面各数顺序向后移m个位置，并使最后m各数变为最前面的m各数。注意，不要用先输出后m个数，再输出前n-m个数的方法实现，也不要用两个数组的方式实现。要求只用一个数组的方式实现，一定要保证在输出结果时，输出的顺序和数组中数的顺序是一致的。
输入
输入有两行：第一行包含一个正整数n和一个正整数m，第二行包含n个正整数。每两个正整数中间用一个空格分开。
输出
输出有一行：经过循环移动后数组中整数的顺序依次输出，每两个整数之间用空格分隔。
样例输入
11 4
15 3 76 67 84 87 13 67 45 34 45
样例输出
67 45 34 45 15 3 76 67 84 87 13
提示

来源
计算概论05

*/

#include<iostream>
using namespace std;
int main()
{
	int a[100],n,m,*p;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{cin>>a[i];}
	p=&a[n];
	p-=m;
	for(int i=0;i<n;i++)
	{
		if(p>&a[n-1])
			p=a;
		cout<<*p++<<" ";
	}
	cout<<endl;
	return 0;
}

