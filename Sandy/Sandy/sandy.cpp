#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int n, a[N], dfn[N], idx, mindfn;
// n: С���ѵ�����
// a[N]: ÿ��С���ѳ�ݵĶ���
// dfn[N]: ��¼ÿ��С���ѵķ���˳��(ʱ���)
// idx: ��ǰ��ʱ���
// mindfn: ��ǰ DFS ����Сʱ���

// ���һ�
int dfs(int x)
{
    dfn[x] = ++idx;   // ����ǰ�ڵ� x ����ʱ���
    if (dfn[a[x]]) 
    {
        // ��� a[x] ��ʱ����ڵ�ǰ DFS ����Сʱ���֮��, ���ػ��ĳ���
        if (dfn[a[x]] >= mindfn) return dfn[x] - dfn[a[x]] + 1;  
        return 0;      // û���γ���Ч�Ļ�
    }
    return dfs(a[x]);  
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
    cin >> n;    
    for (int i = 1; i <= n; i++) cin >> a[i];   
        
    int ans = 0;  // ��󻷵ĳ���
    for (int i = 1; i <= n; i++) 
    {
        // �����ǰС����û�б����ʹ�, ���õ�ǰ DFS ����Сʱ���
        if (!dfn[i]) 
        {
            mindfn = idx + 1;    
            ans = max(ans, dfs(i));  
        }
    }
    cout << ans << '\n';
    return 0;
}
