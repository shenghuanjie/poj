/*
2871: 整数奇偶排序
http://bailian.openjudge.cn/practice/2871/


描述
输入10个整数，彼此以空格分隔重新排序以后输出(也按空格分隔)，要求:1.先输出其中的奇数,并按从大到小排列；2.然后输出其中的偶数,并按从小到大排列。
输入
任意排序的10个整数（0～100），彼此以空格分隔
输出
按照要求排序后输出，由空格分隔
样例输入
4 7 3 13 11 12 0 47 34 98
样例输出
47 13 11 7 3 0 4 12 34 98
提示
1. 测试数据可能有很多组，请使用while(cin>>a[0]>>a[1]>>...>>a[9])类似的做法来实现；2. 输入数据随机，有可能相等。

*/

#include<iostream>
using namespace std;
int main()
{
	int a[10];
	int jishu[10],oushu[10],x=0,y=0;
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9])
	{
		memset(jishu,0,sizeof(jishu));
		memset(oushu,0,sizeof(oushu));
		x=y=0;
		for(int i=0;i<10;i++)
		{
			if(a[i]%2==0)
				oushu[y++]=a[i];
			else
				jishu[x++]=a[i];
		}
		for(int i=0;i<x-1;i++)
		{
			for(int j=0;j<x-i-1;j++)
			{
				if(jishu[j+1]<jishu[j])
				{
					jishu[j]=jishu[j]^jishu[j+1];
					jishu[j+1]=jishu[j+1]^jishu[j];
					jishu[j]=jishu[j]^jishu[j+1];
				}
			}
		}
		for(int i=0;i<y-1;i++)
		{
			for(int j=0;j<y-i-1;j++)
			{
				if(oushu[j+1]<oushu[j])
				{
					oushu[j]=oushu[j]^oushu[j+1];
					oushu[j+1]=oushu[j+1]^oushu[j];
					oushu[j]=oushu[j]^oushu[j+1];
				}
			}
		}
		for(int i=x-1;i>=0;i--)cout<<jishu[i]<<" ";
		for(int i=0;i<y;i++)cout<<oushu[i]<<" ";
		cout<<endl;
	}
	return 0;
}
