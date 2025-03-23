#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int cnt[N], prefix[N];  // cnt[i] �˻�Ϊ i �������θ��� 

// �������п��ܵ������θ����������� V, st ��һ��ѡ��ı߳�, mul Ϊǰ��ĳ˻���, sum Ϊ�߳���  
void dfs(int dep, int st, int mul, int sum)
{
    if (mul > 1e6) return;  // ����˻����� 1e6��ֱ�ӷ���
    if (dep == 4)  // ����Ѿ�ѡ���� 3 ����, ͳ�Ƴ˻�Ϊ mul �������θ���
    {
        cnt[mul]++;  
        return;
    }

    // ���㵱ǰ�����ѡ������߳�
    int up = pow(1e6 / mul, 1.0 / (4 - dep)) + 3;
    for (int i = st + 1; i < (dep == 3 ? sum : up); i++)
    {
        dfs(dep + 1, i, mul * i, sum + i);   // ѡ����һ����
    }
}

int main()
{
    dfs(1, 0, 1, 0);  // �ӵ�һ���߿�ʼ
    for (int i = 1; i <= 1e6; i++) prefix[i] = prefix[i - 1] + cnt[i];  // ����ǰ׺��

    int t = 0; cin >> t;  
    while (t--)
    {
        int l = 0, r = 0; cin >> l >> r;  
        cout << prefix[r] - prefix[l - 1] << '\n';  
    }
    return 0;
}
