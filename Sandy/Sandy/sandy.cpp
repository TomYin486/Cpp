#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
	int data[200] = { 0 };
	for (int i = 0; i < 200; i++)
	{
		// Ϊÿ��Ԫ�ؽ��и�ֵ�����Կ������� data ���Ԫ���������
		data[i] = i * 4 + 6;
	}

	int target = 0;
	// ���� target һ�������� data ��
	cin >> target;

	// ʹ�� lower_bound() ������ data �����ö��ֲ��ҵ�һ�����ڻ���� target ��Ԫ�ص�λ��
	// lower_bound ����һ��ָ���Ԫ�صĵ�ַ
	cout << (lower_bound(data, data + 200, target) - data) << '\n';

	return 0;
}
