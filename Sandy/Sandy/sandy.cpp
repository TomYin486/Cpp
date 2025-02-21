#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, ans;         // n: 皇后数量, ans: 记录合法的放置方法数量
const int N = 15;
int vis[N][N];      // vis[i][j] 表示位置 (i,j) 被多少个皇后占据或受到攻击

// dfs 函数，用于递归尝试放置皇后
// dep: 当前正在放置第 dep 个皇后
void dfs(int dep)
{
    // 如果 dep == n + 1，说明已经成功放置了 n 个皇后
    if (dep == n + 1)
    {
        ans++;    
        return;   // 返回上一层递归
    }

    // 遍历当前行的每一列，尝试放置皇后
    for (int i = 1; i <= n; i++)
    {
        // 如果当前位置已经被占据或受到攻击，跳过
        if (vis[dep][i]) continue;

        // 修改状态：放置皇后，并标记其攻击范围
        // 1. 标记当前列
        for (int _i = 1; _i <= n; _i++) vis[_i][i]++;
        // 2. 标记左上对角线
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j]++;
        // 3. 标记左下对角线
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j]++;
        // 4. 标记右上对角线
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j]++;
        // 5. 标记右下对角线
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j]++;

        // 递归放置下一个皇后
        dfs(dep + 1);

        // 恢复现场：回溯时撤销当前皇后的放置和攻击范围标记
        // 1. 撤销当前列的标记
        for (int _i = 1; _i <= n; _i++) vis[_i][i]--;
        // 2. 撤销左上对角线标记
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j]--;
        // 3. 撤销左下对角线标记
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j]--;
        // 4. 撤销右上对角线标记
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j]--;
        // 5. 撤销右下对角线标记
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j]--;
    }
}

int main()
{
    cin >> n;

    // 调用 dfs 函数，从第 1 个皇后开始放置
    dfs(1);

    cout << ans << '\n';

    return 0;
}
