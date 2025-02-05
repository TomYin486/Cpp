#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;

    // ����һ����С�ѣ����ȶ��У����洢 long long ���͵�Ԫ��
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        // ��Ԫ�� x �������ȶ���
        pq.push(x);
    }

    ll ans = 0;
    while (pq.size() >= 2)
    {
        // ȡ���Ѷ�Ԫ�� a,b ������
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ans += a + b;

        // �� a + b �������ȶ���
        pq.push(a + b);
    }

    cout << ans << '\n';
    return 0;
}
