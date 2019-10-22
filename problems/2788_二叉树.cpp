/*
2788: 二叉树
http://bailian.openjudge.cn/practice/2788/


描述
如上图所示，由正整数1，2，3……组成了一颗二叉树。我们已知这个二叉树的最后一个结点是n。现在的问题是，结点m所在的子树中一共包括多少个结点。比如，n = 12，m = 3那么上图中的结点13，14，15以及后面的结点都是不存在的，结点m所在子树中包括的结点有3，6，7，12，因此结点m的所在子树中共有4个结点。
输入
输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。最后一组测试数据中包括两个0，表示输入的结束，这组数据不用处理。
输出
对于每一组测试数据，输出一行，该行包含一个整数，给出结点m所在子树中包括的结点的数目。
样例输入
3 12
0 0

样例输出
4

*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int m,n;
while(cin>>m>>n)
{

if(m==0&&n==0)
break;
int i=1;
int start=m,end=m;
int ans;
while(1)
{
start=2*start;
end=2*end+1;
i=i*2;
if(end>=n)
{
if(start<=n)
ans=i+n-start;
else
ans=i-1;
break;
}
}
cout<<ans<<endl;
}//end of while
return 0;
}
