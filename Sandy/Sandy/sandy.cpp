#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;

char convertCh(char ch)
{
	// ��� ch ��Сд��ĸ����ת��Ϊ��д��ĸ
	if ('a' <= ch && ch <= 'z')
	{
		ch = ch - 'a' + 'A';
	}
	// ��� ch �Ǵ�д��ĸ����ת��ΪСд��ĸ
	else if ('A' <= ch && ch <= 'Z')
	{
		ch = ch - 'A' + 'a';
	}

	// ��ʹ�� tolower toupper ����
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

	// �����ַ���
	for (auto& i : s1)
	{
		i = convertCh(i);
	}

	//  ��ʽ�� 
	//	for(int i = 0 ; i < s1.size(); i++)
	//	{
	//		s1[i] = convertCh(s1[i]);
	//	}

	cout << s1 << '\n';

	return 0;
}
