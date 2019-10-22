/*
3142: 球弹跳高度的计算
http://bailian.openjudge.cn/practice/3142/


描述
一球从某一高度落下（整数，单位米），每次落地后反跳回原来高度的一半，再落下。编程计算气球在第10次落地时，共经过多少米? 第10次反弹多高？
输入
输入一个整数h，表示球的初始高度。
输出
输出包含两行：第1行：到球第10次落地时，一共经过的米数。第2行：第10次弹跳的高度。注意：结果可能是实数，结果用double类型保存。提示：输出时不需要对精度特殊控制，用cout << ANSWER，或者printf("%g", ANSWER)即可。
样例输入
20

样例输出
59.9219
0.0195313

来源
计算概论2007, XieDi

*/

#include<iostream>
using namespace std;
int main()
{
	int h,i;
	double sum,x;
	cin>>h;
	sum=h;
	x=2*h;
		for(i=0;i<=10;i++)
		{
            sum=sum+x/2;
			x=x/2;
		}
		cout<<sum<<endl;
		cout<<x<<endl;
	return 0;
}
