#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   // ������׼��������⣬����ʹ�� cin �� cout
#include<string>     // �����ַ����⣬����ʹ�� string ���ͺ� getline ����
using namespace std;

int main()
{
    string s;
    getline(cin, s);    // ��������ո���ַ�����������

    reverse(s.begin(), s.end());   // ������ת�ַ��� s
    cout << s;

    return 0;
}
