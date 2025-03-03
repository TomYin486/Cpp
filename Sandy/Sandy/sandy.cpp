#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		// 1.先找到最后一个数
		int cur = 0;      // cur 用于遍历数组
		int dest = -1;    // dest 用于记录复写后的位置
		int n = arr.size();  
		while (cur < n)
		{
			// 如果当前元素不为 0，dest 前进 1 步，否则，复写 0 前进 2 步
			if (arr[cur]) dest++;  
			else dest += 2;  
			if (dest >= n - 1) break;  // 如果 dest 已经到达或超过数组的最后一个位置，跳出循环
			cur++;  
		}

		// 2.处理边界情况
		if (dest == n)
		{
			// 将数组最后一个元素设置为 0
			arr[n - 1] = 0;  
			cur--;  
			dest -= 2;  
		}

		// 3.从后向前完成复写操作
		while (cur >= 0)
		{
			// 如果当前元素不为 0，直接复制到 dest 位置
			if (arr[cur]) arr[dest--] = arr[cur--];  
			else
			{
				// 如果当前元素为 0，复写两个 0
				arr[dest--] = 0;  
				arr[dest--] = 0;
				cur--;  
			}
		}
	}
};
