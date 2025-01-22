#define _CRT_SECURE_NO_WARNINGS
#include<iostream>   // 包含标准输入输出库，用于使用 cin 和 cout
#include<string>     // 包含字符串库，用于使用 string 类型和 getline 函数
using namespace std;

int main()
{
    string s;
    getline(cin, s);    // 处理包含空格的字符串输入的情况

    // 反向遍历字符串 s
    for (int i = (int)s.length() - 1; i >= 0; i--)   // (int)s.length() - 1 为获取字符串的长度并减去 1，得到最后一个字符的下标
    {
        cout << s[i];
    }

    return 0;
}
