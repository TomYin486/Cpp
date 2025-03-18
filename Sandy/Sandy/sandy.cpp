#include<bits/stdc++.h>
using namespace std;
const int M = 1e4 + 9;
int dp[M][2];    // dp[i][j] 表示在重量为 i，使用了 j 次魔法，所获得的最大价值 

int main()
{
	// n 物品数量，m 背包容量，k 使用魔法增加的重量
	int n = 0, m = 0, k = 0; cin >> n >> m >> k;
	// 对于每个物品有 3 种选择：可以不选，选但不用魔法，选且用魔法
	for (int i = 1; i <= n; i++)
	{
		int w = 0, v = 0; cin >> w >> v;
		for (int j = m; j >= 0; j--)
		{
			// 不使用魔法
			if (j >= w)
			{
				dp[j][0] = max(dp[j][0], dp[j - w][0] + v);
				dp[j][1] = max(dp[j][1], dp[j - w][1] + v);
			}
			// 使用魔法
			if (j >= w + k) dp[j][1] = max(dp[j][1], dp[j - w - k][0] + v * 2);
		}
	}

	// 输出不使用魔法和使用魔法的最大值中的较大的 
	cout << max(dp[m][0], dp[m][1]) << '\n';
	return 0;
}
