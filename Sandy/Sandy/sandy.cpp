#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];     // 邻接表，存储帮派的关系
int siz[N];           // siz[x] 表示以 x 为根节点的子树的大小，相当于 x 的手下数量

struct Node
{
    int siz, id;   // siz 表示手下数量，id 表示帮众的序号

    // 排序
    bool operator<(const Node& u) const
    {
        return siz == u.siz ? id < u.id : siz > u.siz;
    }
};

vector<Node> v;    // 存储所有帮众的信息

// 计算以 x 为根节点的子树大小(手下数量)
void dfs(int x, int p)
{
    siz[x] = 1;        // 初始化当前节点的手下数量为 1（自己）
    for (const auto& y : g[x])  // 遍历 x 的所有子节点
    {
        if (y == p) continue;  // 跳过父节点
        dfs(y, x);             // 计算子节点的手下数量，当前 y 的父节点为 x 
        siz[x] += siz[y];
    }
}

int main()
{
    int n, m; cin >> n >> m;  // 输入帮派总人数 n 和小明的序号 m

    // 输入帮派的关系网
    for (int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        g[y].push_back(x);  // 将 x 添加到 y 的子节点中
    }

    // 从根节点 1 开始，计算每个节点的手下数量
    dfs(1, 0);

    // 将所有帮众的信息存储到数组 v 中
    for (int i = 1; i <= n; ++i)
        v.push_back({ siz[i] - 1, i });  // siz[i] - 1 表示除去自己后的手下数量

    // 按照手下数量从大到小排序，如果手下数量相同则按序号从小到大排序
    sort(v.begin(), v.end());

    // 遍历排序后的结果，找到小明的排名
    for (int i = 0; i < v.size(); ++i)
        if (v[i].id == m)
            cout << i + 1 << '\n';  // 输出排名

    return 0;
}
