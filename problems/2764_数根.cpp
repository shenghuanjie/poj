/*
2764: 数根
http://bailian.openjudge.cn/practice/2764/


描述
数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根。如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。比如，对于24来说，把2和4相加得到6，由于6是一位数，因此6是24的数根。再比如39，把3和9加起来得到12，由于12不是一位数，因此还得把1和2加起来，最后得到3，这是一个一位数，因此3是39的数根。
输入
一个正整数(小于101000)。
输出
一个数字，即输入数字的数根。
样例输入
24
样例输出
6
来源
翻译自 Greater New York 2000 的试题

*/

#include<iostream>
#include<string>
using namespace std;
string f(unsigned a,string s)
{
	string temp="";
	while(a!=0)
	{
		temp=a%10+'0';
		s+=temp;
		a/=10;
	}
	return s;
}
int main()
{
	string str;
	while(cin>>str)
	{
		if(str=="0")return 0;
	unsigned l=str.length(),result=0;
	for(unsigned i=0;i<l;i++)
	{
		result+=str[i]-'0';
	}
	while(result>=10)
	{
		str="";
		str=f(result,str);
		l=str.length();
		result=0;
		for(unsigned i=0;i<l;i++)
	     {
		      result+=str[i]-'0';
	     }
	}
	cout<<result<<endl;
	}
	return 0;
}
