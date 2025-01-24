#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 9;
int nums[N];

// 比较函数 cmp 用于 sort 函数中的降序排序
bool cmp(const int& p1, const int& p2)
{
	// int &p1 表示 p1 是一个 int 类型的引用，可理解为 p1 是另一个 int 类型变量的别名
	// 如果 p1 大于 p2，则返回 true，表示 p1 应该排在 p2 前面
	return p1 > p2;
}

int main()
{
	int n;
	cin >> n;

	int i = 0;
	for (i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// 进行升序排序，范围是[nums, num + n)
	sort(nums, nums + n);

	for (i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << '\n';

	// 降序排序
	sort(nums, nums + n, cmp);

	for (i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}

	// 方法二：逆序输出
	/*for (i = n - 1; i >= 0; i--)
	{
		cout << nums[i] << ' ';
	}*/
	return 0;
}
