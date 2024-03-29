/*
2797: 最短前缀
http://bailian.openjudge.cn/practice/2797/


描述
一个字符串的前缀是从该字符串的第一个字符起始的一个子串。例如 "carbon"的字串是: "c", "ca", "car", "carb", "carbo", 和 "carbon"。注意到这里我们不认为空串是字串, 但是每个非空串是它自身的字串. 我们现在希望能用前缀来缩略的表示单词。例如, "carbohydrate" 通常用"carb"来缩略表示. 现在给你一组单词, 要求你找到唯一标识每个单词的最短前缀在下面的例子中，"carbohydrate" 能被缩略成"carboh", 但是不能被缩略成"carbo" (或其余更短的前缀) 因为已经有一个单词用"carbo"开始一个精确匹配会覆盖一个前缀匹配，例如，前缀"car"精确匹配单词"car". 因此 "car" 是 "car"的缩略语是没有二义性的 , “car”不会被当成"carriage"或者任何在列表中以"car"开始的单词.
输入
输入包括至少2行，至多1000行. 每行包括一个以小写字母组成的单词，单词长度至少是1，至多是20.
输出
输出的行数与输入的行数相同。每行输出由相应行输入的单词开始，后面跟着一个空格接下来是相应单词的没有二义性的最短前缀标识符。
样例输入
carbohydrate
cart
carburetor
caramel
caribou
carbonic
cartilage
carbon
carriage
carton
car
carbonate

样例输出
carbohydrate carboh
cart cart
carburetor carbu
caramel cara
caribou cari
carbonic carboni
cartilage carti
carbon carbon
carriage carr
carton carto
car car
carbonate carbona

来源
翻译自Rocky Mountain 2004

*/

#include<iostream>
#include <stdlib.h>
using namespace std;
char word[1500][30];//保存字符串
int num[1500];//保存词的顺序，用于排序
char result[1500][30];//保存结果
char str[30];//临时变量，用于输入
int judge(const void *a,const void *b)//比较函数
{
	return strcmp(word[*(int*)a],word[*(int*)b]);
}
int main()
{
	int n=1;
	int i=0,j=0,x=-1;
	word[0][0]= '\0';
	while (cin>>str)
	{
		strcpy(word[n],str);
		num[n]=n++;
	}
	word[n][0]= '\0';
	qsort(num,n,sizeof(int),judge);//将序号按词的字母先后排序
	result[0][0]= '\0';
	for(i=1;i<n;i++)//看上下两个的相同子序列，知道找到一个不同的为止
	{
		j=0;
		while((word[num[i-1]][j]==word[num[i]][j])&&(word[num[i]][j]==word[num[i+1]][j]))
		{
			result[num[i]][j]=word[num[i]][j];
			j++;
		}
		x=-1;
		if(word[num[i-1]][j]==word[num[i]][j])
		{
			x=num[i-1];
		}
		if(word[num[i+1]][j]==word[num[i]][j])
		{
			x=num[i+1];
		}
		if(x!=-1)
		{
		while (word[x][j]==word[num[i]][j])
		{ 
			result[num[i]][j]=word[num[i]][j];
			j++;
		}
		}
		result[num[i]][j]=word[num[i]][j];
		result[num[i]][j+1]= '\0';
	}
	for(i=1;i<n;i++)//输出
	{
		cout<<word[i]<<" "<<result[i]<<endl;
	}
	return 0;
}
