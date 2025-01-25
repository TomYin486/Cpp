#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int data[200] = { 0 };
	for (int i = 0; i < 200; i++)
	{
		// 为每个元素进行赋值，可以看出数组 data 里的元素是升序的
		data[i] = i * 4 + 6;
	}

	int target = 0;
	// 假设 target 一定在数组 data 中
	cin >> target;

	// 使用 lower_bound() 在数组 data 中利用二分查找第一个大于或等于 target 的元素的位置
	// lower_bound 返回一个指向该元素的地址
	cout << (lower_bound(data, data + 200, target) - data) << '\n';

	return 0;
}
