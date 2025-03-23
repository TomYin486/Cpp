#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int cnt[N], prefix[N];  // cnt[i] 乘积为 i 的三角形个数 

// 生成所有可能的三角形个数，并计算 V, st 上一个选择的边长, mul 为前面的乘积数, sum 为边长和  
void dfs(int dep, int st, int mul, int sum)
{
    if (mul > 1e6) return;  // 如果乘积超过 1e6，直接返回
    if (dep == 4)  // 如果已经选择了 3 条边, 统计乘积为 mul 的三角形个数
    {
        cnt[mul]++;  
        return;
    }

    // 计算当前层可以选择的最大边长
    int up = pow(1e6 / mul, 1.0 / (4 - dep)) + 3;
    for (int i = st + 1; i < (dep == 3 ? sum : up); i++)
    {
        dfs(dep + 1, i, mul * i, sum + i);   // 选择下一条边
    }
}

int main()
{
    dfs(1, 0, 1, 0);  // 从第一条边开始
    for (int i = 1; i <= 1e6; i++) prefix[i] = prefix[i - 1] + cnt[i];  // 计算前缀和

    int t = 0; cin >> t;  
    while (t--)
    {
        int l = 0, r = 0; cin >> l >> r;  
        cout << prefix[r] - prefix[l - 1] << '\n';  
    }
    return 0;
}
