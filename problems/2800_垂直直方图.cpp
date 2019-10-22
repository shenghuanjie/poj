/*
2800: 垂直直方图
http://bailian.openjudge.cn/practice/2800/


描述
输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。
输入
输入包括4行由大写字母组成的文本，每行上字符的数目不超过80个。
输出
输出包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用一个空格隔开。前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。注意：输出的第一行不能是空行。
样例输入
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST FOR YOUR
HISTOGRAM PROGRAM.
HELLO!

样例输出
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

来源
翻译自USACO 2003 February Orange的试题。

*/

#include<iostream>
using namespace std;
int main()
{
	int result[27];
	char str[100];
	int len;
	int i;
	int k;
	memset(result,0,sizeof(result));
	for(k=1;k<=4;k++)
	{
		cin.getline(str,100);
	len=strlen(str);
//	cout<<len<<endl;
	for(i=0;i<len;i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			result[str[i]-'A']++;
		}
	}
	memset(str,0,sizeof(str));
    }
	int m=0;
	for(i=0;i<26;i++)
	{
		//cout<<result[i]<<endl;
		if(result[i]>m)m=result[i];
	}
	//cout<<m<<endl;
          if(m){
			  for(k=m;k>=1;k--)
			  {
				  for(i=0;i<26;i++)
				  {
					  if(result[i]>=k)
						  cout<<"* ";
					  else
						  cout<<"  ";
				  }
				  cout<<endl;
			  }
		  }
	for(i='A';i<='Z';i++)
		cout<<(char)i<<" ";
	return 0;
}
