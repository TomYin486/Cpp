#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using ll = long long;  
const ll N = 1e6 + 9, p = 1e9 + 7;  // N 是数组大小，p 是模数
ll dp[N], prefix[N];  

int main()
{
    int n, k;
    cin >> n >> k;  // n 是空位数，k 是油桶之间需要的最小空位数

    // dp[0] 和 prefix[0] 初始化为 1，表示没有空位时的方案数为 1
    // dp[i] 表示以位置 i 结尾的方案总数
    dp[0] = prefix[0] = 1;  

    // 用 dp 计算每个位置的方案数
    for (int i = 1; i <= n; i++)
    {
        // 如果当前位置 i 减去 k - 1 小于 0，说明无法放置油桶，方案数为 1
        if (i - k - 1 < 0)
        {
            dp[i] = 1;
        }
        else
        {
            // prefix[i - k - 1] 表示在 i - k - 1 位置之前的方案数
            dp[i] = prefix[i - k - 1];
        }
           
        // 更新 prefix 数组
        prefix[i] = (prefix[i - 1] + dp[i]) % p;  
    }

    cout << prefix[n] << '\n';
    return 0;
}
