#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 9;
int nums[N];

// �ȽϺ��� cmp ���� sort �����еĽ�������
bool cmp(const int& p1, const int& p2)
{
	// int &p1 ��ʾ p1 ��һ�� int ���͵����ã������Ϊ p1 ����һ�� int ���ͱ����ı���
	// ��� p1 ���� p2���򷵻� true����ʾ p1 Ӧ������ p2 ǰ��
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

	// �����������򣬷�Χ��[nums, num + n)
	sort(nums, nums + n);

	for (i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}
	cout << '\n';

	// ��������
	sort(nums, nums + n, cmp);

	for (i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}

	// ���������������
	/*for (i = n - 1; i >= 0; i--)
	{
		cout << nums[i] << ' ';
	}*/
	return 0;
}
