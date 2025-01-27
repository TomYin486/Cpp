#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

char convertCh(char ch)
{
	// 如果 ch 是小写字母，则转换为大写字母
	if ('a' <= ch && ch <= 'z')
	{
		ch = ch - 'a' + 'A';
	}
	// 如果 ch 是大写字母，则转换为小写字母
	else if ('A' <= ch && ch <= 'Z')
	{
		ch = ch - 'A' + 'a';
	}

	// 或使用 tolower toupper 函数
	/*if(islower(ch))
	{
		ch = toupper(ch);
	}
	else if(isupper(ch))
	{
		ch = tolower(ch);
	}*/

	return ch;
}

int main()
{
	string s1;
	getline(cin, s1);

	// 遍历字符串
	for (auto& i : s1)
	{
		i = convertCh(i);
	}

	//  方式二 
	//	for(int i = 0 ; i < s1.size(); i++)
	//	{
	//		s1[i] = convertCh(s1[i]);
	//	}

	cout << s1 << '\n';

	return 0;
}
