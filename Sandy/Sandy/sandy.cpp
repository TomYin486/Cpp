#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 105;      // ���������ε��������
ll a[N][N], dp[N][N];   // a: �洢���������Σ�dp: �洢�ӵ�ǰλ�õ��ײ������·����

int main()
{
	int n; cin >> n;   

	// ��������������
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	// �ӵײ����ϼ������·����
	for (int i = n; i >= 1; i--) // �����һ�п�ʼ���ϱ���
	{
		// ������ǰ�е�ÿ��Ԫ��
		for (int j = 1; j <= i; j++) 
		{
			// ��ǰԪ�ص�ֵ������һ����������Ԫ�ص����ֵ
			dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	cout << dp[1][1] << '\n';
	return 0;
}      
