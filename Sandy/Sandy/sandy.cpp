#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    // int ���ͣ����Ʋ������������ƣ�����ಹ����λ�������� 0�������� 1��
    // unsigned int ���ͣ����Ʋ������߼����ƣ�����ಹ 0
    unsigned int n;
    cin >> n;
    int count = 0;   // ����ͳ�ƶ������� 1 �ĸ���

    while (n > 0)
    {
        // ��� n �����λ�Ƿ�Ϊ 1
        if ((n & 1) != 0)
        {
            // ������λ�� 1���������� 1
            count++;
        }
        n >>= 1;    // �� n ����һλ���൱��ȥ�����λ
    }

    cout << count << '\n';
    return 0;
}
