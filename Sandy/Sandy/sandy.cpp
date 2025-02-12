#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    // int 类型，右移操作是算术右移，在左侧补符号位（正数补 0，负数补 1）
    // unsigned int 类型，右移操作是逻辑右移，在左侧补 0
    unsigned int n;
    cin >> n;
    int count = 0;   // 用于统计二进制中 1 的个数

    while (n > 0)
    {
        // 检查 n 的最低位是否为 1
        if ((n & 1) != 0)
        {
            // 如果最低位是 1，计数器加 1
            count++;
        }
        n >>= 1;    // 将 n 右移一位，相当于去掉最低位
    }

    cout << count << '\n';
    return 0;
}
