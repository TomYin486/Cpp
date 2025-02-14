#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

// 比较函数
bool cmp(string a, string b)
{
    // 如果 a + b > b + a，则 a 应该排在 b 前面
    return a + b > b + a;
}

int main()
{
    int n; 
    cin >> n; 

    string s[n];    // 字符串数组 s 用于存储 n 个正整数
    int i = 0;
    // 读取 n 个正整数
    for (i = 0; i < n; i++)
    {
        cin >> s[i]; 
    }

    // 对数组进行排序
    sort(s, s + n, cmp);

    // 输出排序后的字符串数组 s
    for (i = 0; i < n; i++)
    {
        cout << s[i]; 
    }

    return 0; 
}
