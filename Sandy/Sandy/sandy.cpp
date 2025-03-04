#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		// 1.���� dp ��
		// 2.��ʼ��
		// 3.���
		// 4.����ֵ

		// ����߽����
		if (n == 0) return 0;
		if (n == 1 || n == 2) return 1;

		vector<int> dp(n + 1);
		dp[0] = 0, dp[1] = dp[2] = 1;
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		// ������
		/*int a = 0, b = 1, c = 1, d = 0;
		for (int i = 3; i <= n; i++)
		{
			// T(n) = T(n-3) + T(n-2) + T(n-1)
			d = a + b + c;
			a = b;
			b = c;
			c = d;
		}
		return d;*/
		return dp[n];
	}
};
