/*
2803: 碎纸机
http://bailian.openjudge.cn/practice/2803/


描述
你现在负责设计一种新式的碎纸机。一般的碎纸机会把纸切成小片，变得难以阅读。而你设计的新式的碎纸机有以下的特点：1.每次切割之前，先要给定碎纸机一个目标数，而且在每张被送入碎纸机的纸片上也需要包含一个数。2.碎纸机切出的每个纸片上都包括一个数。3.要求切出的每个纸片上的数的和要不大于目标数而且与目标数最接近。举一个例子，如下图，假设目标数是50，输入纸片上的数是12346。碎纸机会把纸片切成4块，分别包含1，2，34和6。这样这些数的和是43 (= 1 + 2 + 34 + 6)，这是所有的分割方式中，不超过50，而又最接近50的分割方式。又比如，分割成1，23，4和6是不正确的，因为这样的总和是34 (= 1 + 23 + 4 + 6)，比刚才得到的结果43小。分割成12，34和6也是不正确的，因为这时的总和是52 (= 12 + 34 + 6)，超过了50。还有三个特别的规则：1.如果目标数和输入纸片上的数相同，那么纸片不进行切割。2.如果不论怎样切割，分割得到的纸片上数的和都大于目标数，那么打印机显示错误信息。3.如果有多种不同的切割方式可以得到相同的最优结果。那么打印机显示拒绝服务信息。比如，如果目标数是15，输入纸片上的数是111，那么有两种不同的方式可以得到最优解，分别是切割成1和11或者切割成11和1，在这种情况下，打印机会显示拒绝服务信息。为了设计这样的一个碎纸机，你需要先写一个简单的程序模拟这个打印机的工作。给定两个数，第一个是目标数，第二个是输入纸片上的数，你需要给出碎纸机对纸片的分割方式。
输入
输入包括多组数据，每一组包括一行。每行上包括两个正整数，分别表示目标数和输入纸片上的数。已知输入保证：两个数都不会以0开头，而且两个数至多都只包含6个数字。输入的最后一行包括两个0，这行表示输入的结束。
输出
对每一组输入数据，输出相应的输出。有三种不同的输出结果：sum part1 part2 ... rejected error 第一种结果表示：1.每一个partj是切割得到的纸片上的一个数。partj的顺序和输入纸片上原始数中数字出现的次序一致。2.sum是切割得到的纸片上的数的和，也就是说：sum = part1 + part2 +...第一种结果中相邻的两个数之间用一个空格隔开。如果不论怎样切割，分割得到的纸片上数的和都大于目标数，那么打印“error”。如果有多种不同的切割方式可以得到相同的最优结果，那么打印“rejected”。 
样例输入
50 12346
376 144139
927438 927438
18 3312
9 3142
25 1299
111 33333
103 862150
6 1104
0 0

样例输出
43 1 2 34 6
283 144 139
927438 927438
18 3 3 12
error
21 1 2 9 9
rejected
103 86 2 15 0
rejected

来源
翻译自Japan 2002 Kanazawa的试题

*/

#include<iostream>
#include<cmath>
using namespace std;
int x,goal,w=0,sum=0,k;
int num[10],temp[10];
void change(int z)//将整数存为一个数组
{
	w=0;//初始化
		while(z!=0)
	{
		num[w++]=z%10;
		z/=10;
	}
	for(int i=0;i<=(w/2-1);i++)
	{
		num[i]=num[i]^num[w-1-i];
		num[w-i-1]=num[i]^num[w-i-1];
		num[i]=num[i]^num[w-i-1];
	}
}
void output()//输出
{
	cout<<sum<<" ";
	for(int i=0;i<w;i++)
	{
		if(temp[i]!=-1)
			cout<<temp[i]<<" ";
	}
	cout<<endl;
}
void cut(int m,int result)
{
	int i,j;
	if(m==w)
	{
		if((result<=goal)&&(result==sum)&&(result>k))
			k=result;
		if((result<=goal)&&(result>sum))
	    {
		    sum=result;
		    for(int i=0;i<w;i++)
			{
		    temp[i]=num[i];
			}
		}
		return ;
	}
	else
	for(i=m;i<w;i++)
	{
		for(j=m;j<i;j++)
		{
			num[i]+=num[j]*pow(10.0,i-j);
			num[j]=-1;
		}
		//改变原数组
		result+=num[i];
	    cut(i+1,result);
		//递归
		result-=num[i];
		num[m]=num[i];
		for(j=i;j>m;j--)
		{
			num[j]=num[m]%10;
			num[m]/=10;
		}
		//恢复数组
	}
}
int main()
{
input:while(cin>>goal>>x)
	{
	if(goal==0&&x==0)return 0;//停止
	sum=0;//初始化
	k=0;
	memset(num,-1,sizeof(num));
	memset(temp,-1,sizeof(temp));
	change(x);
		for(int i=0;i<w;i++)
	{
		sum+=num[i];
	}
	if(sum>goal)
	{cout<<"error"<<endl;goto input;}//报错
	sum=0;//再次初始化
	cut(0,0);
	if(k==sum)
	cout<<"rejected"<<endl;
	else
	output();
	}
	return 0;
}
