#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 105;      // 数字三角形的最大行数
ll a[N][N], dp[N][N];   // a: 存储数字三角形；dp: 存储从当前位置到底部的最大路径和

int main()
{
	int n; cin >> n;   

	// 输入数字三角形
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	// 从底部向上计算最大路径和
	for (int i = n; i >= 1; i--) // 从最后一行开始向上遍历
	{
		// 遍历当前行的每个元素
		for (int j = 1; j <= i; j++) 
		{
			// 当前元素的值加上下一行相邻两个元素的最大值
			dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}

	cout << dp[1][1] << '\n';
	return 0;
}      
