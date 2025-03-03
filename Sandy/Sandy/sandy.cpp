#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		// 1.���ҵ����һ����
		int cur = 0;      // cur ���ڱ�������
		int dest = -1;    // dest ���ڼ�¼��д���λ��
		int n = arr.size();  
		while (cur < n)
		{
			// �����ǰԪ�ز�Ϊ 0��dest ǰ�� 1 �������򣬸�д 0 ǰ�� 2 ��
			if (arr[cur]) dest++;  
			else dest += 2;  
			if (dest >= n - 1) break;  // ��� dest �Ѿ�����򳬹���������һ��λ�ã�����ѭ��
			cur++;  
		}

		// 2.����߽����
		if (dest == n)
		{
			// ���������һ��Ԫ������Ϊ 0
			arr[n - 1] = 0;  
			cur--;  
			dest -= 2;  
		}

		// 3.�Ӻ���ǰ��ɸ�д����
		while (cur >= 0)
		{
			// �����ǰԪ�ز�Ϊ 0��ֱ�Ӹ��Ƶ� dest λ��
			if (arr[cur]) arr[dest--] = arr[cur--];  
			else
			{
				// �����ǰԪ��Ϊ 0����д���� 0
				arr[dest--] = 0;  
				arr[dest--] = 0;
				cur--;  
			}
		}
	}
};
