#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int n, a[N], dfn[N], idx, mindfn;
// n: 小朋友的数量
// a[N]: 每个小朋友崇拜的对象
// dfn[N]: 记录每个小朋友的访问顺序(时间戳)
// idx: 当前的时间戳
// mindfn: 当前 DFS 的最小时间戳

// 查找环
int dfs(int x)
{
    dfn[x] = ++idx;   // 给当前节点 x 打上时间戳
    if (dfn[a[x]]) 
    {
        // 如果 a[x] 的时间戳在当前 DFS 的最小时间戳之后, 返回环的长度
        if (dfn[a[x]] >= mindfn) return dfn[x] - dfn[a[x]] + 1;  
        return 0;      // 没有形成有效的环
    }
    return dfs(a[x]);  
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    cin >> n;    
    for (int i = 1; i <= n; i++) cin >> a[i];   
        
    int ans = 0;  // 最大环的长度
    for (int i = 1; i <= n; i++) 
    {
        // 如果当前小朋友没有被访问过, 设置当前 DFS 的最小时间戳
        if (!dfn[i]) 
        {
            mindfn = idx + 1;    
            ans = max(ans, dfs(i));  
        }
    }
    cout << ans << '\n';
    return 0;
}
