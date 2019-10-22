/*
2774: 木材加工
http://bailian.openjudge.cn/practice/2774/


描述
木材厂有一些原木，现在想把这些木头切割成一些长度相同的小段木头，需要得到的小段的数目是给定了。当然，我们希望得到的小段越长越好，你的任务是计算能够得到的小段木头的最大长度。木头长度的单位是厘米。原木的长度都是正整数，我们要求切割得到的小段木头的长度也要求是正整数。
输入
第一行是两个正整数N和K(1 ≤ N ≤ 10000, 1 ≤ K ≤ 10000)，N是原木的数目，K是需要得到的小段的数目。接下来的N行，每行有一个1到10000之间的正整数，表示一根原木的长度。　
输出
输出能够切割得到的小段的最大长度。如果连1厘米长的小段都切不出来，输出"0"。
样例输入
3 7
232
124
456

样例输出
114
来源
NOIP 2004

*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	int sum=0;
	int min=10001,max=0;
	cin>>n>>k;
	int *num=new int[n+1];
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>num[i];
		if(num[i]<min)
			min=num[i];
		if(num[i]>max)
			max=num[i];
	}
	for(j=(min+max)/2;j>0;j--)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=num[i]/j;
		}
		if(sum>=k)
			break;
	}
	if(j==(min+max)/2)
	{
		for(;;j++)
		{
			sum=0;
			for(i=0;i<n;i++)
			{
				sum+=num[i]/j;
			}
			if(sum<k)
			{
				j--;
				break;
			}
		}
	}
	cout<<j<<endl;
    return 0;
}
