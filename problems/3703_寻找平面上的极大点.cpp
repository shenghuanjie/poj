/*
3703: 寻找平面上的极大点
http://bailian.openjudge.cn/practice/3703/


描述
在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。本题规定：n不超过100，并且不考虑点的坐标为负数的情况。
输入
输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。
输出
按x轴坐标最小到大的顺序输出所有极大点。输出格式为:(x1,y1),(x2,y2),...(xk,yk)注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错
样例输入
5 
1 2 2 2 3 1 2 3 1 4
样例输出
(1,4),(2,3),(3,1)
提示


*/

#include <iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int w=1,x,y;
	int face[110][110];
	int t=0,hang[110],lie[110];
	memset(face,0,sizeof(face));
	memset(hang,0,sizeof(hang));
	memset(lie,0,sizeof(lie));
	for(;w<=n;w++)
	{
		cin>>x>>y;
		if(face[x][y]!=-1)
		face[x][y]=1;
		for(int i=0;i<=x;i++)
		{
			for(int j=0;j<=y;j++)
			{
				if(i==x&&j==y)continue;
				face[i][j]=-1;
			}
		}
	}
	for(int i=0;i<110;i++)
		{
			for(int j=0;j<110;j++)
			{
				if(face[i][j]==1)
				{
					hang[t]=i;
					lie[t]=j;
					t++;
				}
			}
		}
	int temp=-1;
	for(int i=0;i<t;i++)
	{
		for(int j=i;j<t;j++)
		{
			if(hang[i]>hang[j])
			{
				temp=hang[i];
				hang[i]=hang[j];
				hang[j]=temp;
				temp=lie[i];
				lie[i]=lie[j];
				lie[j]=temp;
			}
		}
	}
	for(int i=0;i<t-1;i++)
	cout<<"("<<hang[i]<<","<<lie[i]<<"),";
	cout<<"("<<hang[t-1]<<","<<lie[t-1]<<")"<<endl;
	return 0;
}
