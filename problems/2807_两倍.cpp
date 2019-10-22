/*
2807: 两倍
http://bailian.openjudge.cn/practice/2807/


描述
给定2到15个不同的正整数，你的任务是计算这些数里面有多少个数对满足：数对中一个数是另一个数的两倍。比如给定1 4 3 2 9 7 18 22，得到的答案是3，因为2是1的两倍，4是2个两倍，18是9的两倍。
输入
一行，给出2到15个两两不同且小于100的正整数。最后用0表示输入结束。
输出
一个整数，即有多少个数对满足其中一个数是另一个数的两倍。
样例输入
1 4 3 2 9 7 18 22 0

样例输出
3

来源
翻译自Mid-Central USA 2003的试题

*/

#include<iostream>
using namespace std;
int main()
{
	int x[20];
	int i,j,l;
	while(1)
		{
		int count=0;
	for(l=0;;l++)
	{
		cin>>x[l];
		if(x[l]==0||x[l]==-1)
			break;
	}
	if(x[0]==-1)return 0;
	for(i=0;i<=l-1;i++)
	{
		for(j=0;j<=l-1;j++)
		{
			if(x[j]==2*x[i])count++;
		}
	}
	cout<<count<<endl;
		}
	return 0;
}

