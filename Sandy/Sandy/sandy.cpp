#include<bits/stdc++.h>
using namespace std;
const int M = 1e4 + 9;
int dp[M][2];    // dp[i][j] ��ʾ������Ϊ i��ʹ���� j ��ħ��������õ�����ֵ 

int main()
{
	// n ��Ʒ������m ����������k ʹ��ħ�����ӵ�����
	int n = 0, m = 0, k = 0; cin >> n >> m >> k;
	// ����ÿ����Ʒ�� 3 ��ѡ�񣺿��Բ�ѡ��ѡ������ħ����ѡ����ħ��
	for (int i = 1; i <= n; i++)
	{
		int w = 0, v = 0; cin >> w >> v;
		for (int j = m; j >= 0; j--)
		{
			// ��ʹ��ħ��
			if (j >= w)
			{
				dp[j][0] = max(dp[j][0], dp[j - w][0] + v);
				dp[j][1] = max(dp[j][1], dp[j - w][1] + v);
			}
			// ʹ��ħ��
			if (j >= w + k) dp[j][1] = max(dp[j][1], dp[j - w - k][0] + v * 2);
		}
	}

	// �����ʹ��ħ����ʹ��ħ�������ֵ�еĽϴ�� 
	cout << max(dp[m][0], dp[m][1]) << '\n';
	return 0;
}
