#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   // ������׼��������⣬����ʹ�� cin �� cout
#include<string>     // �����ַ����⣬����ʹ�� string ���ͺ� getline ����
using namespace std;

int main()
{
    string s;
    getline(cin, s);    // ��������ո���ַ�����������

    // ��������ַ��� s
    for (int i = (int)s.length() - 1; i >= 0; i--)   // (int)s.length() - 1 Ϊ��ȡ�ַ����ĳ��Ȳ���ȥ 1���õ����һ���ַ����±�
    {
        cout << s[i];
    }

    return 0;
}
