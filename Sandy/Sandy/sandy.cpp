#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 9;
int dp[N];    // dp[j] ��ʾ��������Ϊ j ʱ������ֵ

int main()
{
    int n = 0, m = 0; cin >> n >> m;  //  ���������� n �ͱ������� m

    for (int i = 1; i <= n; i++)
    {
        // �������� v����ֵ w ������ s
        int v = 0, w = 0, s = 0; cin >> v >> w >> s;

        // �� s ����Ʒ��ֳ� 1, 2, 4,..., 2^k ����Ʒ�����
        for (int k = 1; s >= k; s -= k, k *= 2)
        {
            // �Բ�ֺ��k����Ʒ����ѡ��, ѡ���Ƿ����� k ����Ʒ���Ƚϲ��ú��õļ�ֵ
            for (int j = m; j >= k * v; j--) dp[j] = max(dp[j], dp[j - k * v] + k * w);
        }
        // �����ֺ�ʣ�����Ʒ���� s
        for (int j = m; j >= s * v; j--) dp[j] = max(dp[j], dp[j - s * v] + s * w);
    }
    cout << dp[m] << '\n';
    return 0;
}
