#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using ll = long long;

const ll p = 1e9 + 7;      // p 为模数
const int N = 1e5 + 9;     // N 为数组的最大大小
ll a[6][N], prefix[6][N];  // a 数组存储不同次方的值，prefix 数组存储前缀和

// 由于 k 比较小，可以处理出 5 个数组分别表示不同的次方，如 a3[] 中的元素都是数组 a 中元素的 3 次方
// 再对 5 个数组预处理出前缀和，对于每次询问利用前缀和的性质可 O(1) 解决

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);    // 加速输入输出
    int n, m;         // n 和 m 分别为数组长度和查询次数
    cin >> n >> m;

    int i = 0;
    int j = 0;

    // 输入原始数组
    for (i = 1; i <= n; ++i)
    {
        cin >> a[1][i];
    }

    // 计算每个元素的 2 到 5 的次方，并取模
    for (i = 2; i <= 5; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            a[i][j] = a[i - 1][j] * a[1][j] % p;
        }
    }

    // 计算每个次方的前缀和，并取模
    for (i = 1; i <= 5; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            prefix[i][j] = (prefix[i][j - 1] + a[i][j]) % p;
        }

    }

    // 处理每个查询
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;   // 输入查询的左右边界和次方

        // 输出查询结果，处理了负数情况
        cout << (prefix[k][r] - prefix[k][l - 1] + p) % p << "\n";
    }
    return 0;
}
