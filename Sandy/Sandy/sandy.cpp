#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

// �ȽϺ���
bool cmp(string a, string b)
{
    // ��� a + b > b + a���� a Ӧ������ b ǰ��
    return a + b > b + a;
}

int main()
{
    int n; 
    cin >> n; 

    string s[n];    // �ַ������� s ���ڴ洢 n ��������
    int i = 0;
    // ��ȡ n ��������
    for (i = 0; i < n; i++)
    {
        cin >> s[i]; 
    }

    // �������������
    sort(s, s + n, cmp);

    // ����������ַ������� s
    for (i = 0; i < n; i++)
    {
        cout << s[i]; 
    }

    return 0; 
}
