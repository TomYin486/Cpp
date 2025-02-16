#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 1e5 + 9;   // 数组的最大长度
int a[N];            

// 利用快慢指针，保持区间 [i, j] 尽可能小且和 >= S
// 当 [i, j] 中的 sum >= S 后，再增加 j 没有意义，所以 i, j 都不动
// 当 i 增大后 sum 可能 < S，此时 j 不可能左移，所以只能右移，于是 i, j 都只能右移，从而出现左移

int main()
{
    // 加速输入输出流
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, S;         // n 是序列长度，S 是目标区间和
    cin >> n >> S;    

    int i = 0;
    // 读取序列中的元素
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = n + 1;   // ans 为 n + 1，表示一个不可能的长度，用于后面判断
    int j = 0;
    int sum = 0;

    // 双指针
    for (i = 1; i <= n; i++)
    {
        // 指针 j 向右移动，直到区间和 sum >= S 或者 j 超出范围
        while (i > j || (j + 1 <= n && sum < S))
        {
            j++;           // 右指针右移
            sum += a[j];   // 累加区间和
        }

        // 如果当前区间和 sum >= S，更新 ans 为当前区间的长度和 ans 中的较小值
        if (sum >= S)
        {
            ans = min(ans, j - i + 1);
        }

        // 移动左指针 i，并从 sum 中减去 a[i]，以便继续寻找更短的区间
        sum -= a[i];
    }

    // 如果 ans 仍然大于 n，表示没有找到满足条件的区间，输出 0；否则输出 ans
    cout << (ans > n ? 0 : ans) << '\n';

    return 0; 
}
