/*
2675: 计算书费
http://bailian.openjudge.cn/practice/2675/


描述
下面是一个图书的单价表：  计算概论          28.9 元/本  数据结构与算法    32.7 元/本  数字逻辑          45.6元/本  C++程序设计教程   78  元/本  人工智能          35  元/本  计算机体系结构    86.2 元/本  编译原理          27.8元/本  操作系统          43  元/本  计算机网络        56  元/本  JAVA程序设计      65  元/本给定每种图书购买的数量，编程计算应付的总费用。
输入
输入第一行包含一个正整数k（0<k<100），表示有k组测试数据；接下来k行，每行包含一组测试数据。每组测试数据包含10个整数(大于等于0，小于等于100)，分别表示购买的《计算概论》、《数据结构与算法》、《数字逻辑》、《C++程序设计教程》、《人工智能》、《计算机体系结构》、《编译原理》、《操作系统》、《计算机网络》、《JAVA程序设计》的数量（以本为单位）。每两个整数用一个空格分开。
输出
对于每组测试数据，输出一行。该行包含一个浮点数f，表示应付的总费用。精确到小数点后两位。可用printf("%.2f\n", sum)来输出sum的值，并精确到小数点后两位。
样例输入
2
1 5 8 10 5 1 1 2 3 4 
3 5 6 3 100 1 1 0 1 0

样例输出
2140.20
4427.80

来源
计算概论05－模拟考试1

*/

#include<iostream>
using namespace std;
int main()
{
	float number[10],sum;
	int k,i;
	cin>>k;
		for(i=0;i<k;i++)
		{
			cin>>number[0]>>number[1]>>number[2]>>number[3]>>number[4]>>number[5]>>number[6]>>number[7]>>number[8]>>number[9];
			sum=28.9*number[0]+32.7*number[1]+45.6*number[2]+78*number[3]+35*number[4]+86.2*number[5]+27.8*number[6]+43*number[7]+56*number[8]+65*number[9];
			printf("%.2f\n",sum);
		}
	return 0;
}
