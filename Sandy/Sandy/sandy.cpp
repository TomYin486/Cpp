#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 9;
int dp[N];    // dp[j] 表示背包容量为 j 时的最大价值

int main()
{
    int n = 0, m = 0; cin >> n >> m;  //  宝物种类数 n 和背包容量 m

    for (int i = 1; i <= n; i++)
    {
        // 宝物的体积 v、价值 w 和数量 s
        int v = 0, w = 0, s = 0; cin >> v >> w >> s;

        // 将 s 件物品拆分成 1, 2, 4,..., 2^k 件物品的组合
        for (int k = 1; s >= k; s -= k, k *= 2)
        {
            // 对拆分后的k件物品进行选择, 选择是否拿这 k 件物品：比较不拿和拿的价值
            for (int j = m; j >= k * v; j--) dp[j] = max(dp[j], dp[j - k * v] + k * w);
        }
        // 处理拆分后剩余的物品数量 s
        for (int j = m; j >= s * v; j--) dp[j] = max(dp[j], dp[j - s * v] + s * w);
    }
    cout << dp[m] << '\n';
    return 0;
}
