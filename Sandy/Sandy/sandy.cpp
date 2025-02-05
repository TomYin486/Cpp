#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;

    // 定义一个最小堆（优先队列），存储 long long 类型的元素
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        // 将元素 x 插入优先队列
        pq.push(x);
    }

    ll ans = 0;
    while (pq.size() >= 2)
    {
        // 取出堆顶元素 a,b 并弹出
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a + b;

        // 将 a + b 插入优先队列
        pq.push(a + b);
    }

    cout << ans << '\n';
    return 0;
}
