#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec = { 1,5,3,9,8,7,10,2,5,6,10,2,2,6,6,6,6 };

    // �� vec �е�Ԫ�ؽ�����������
    sort(vec.begin(), vec.end());

    // �� vec �е������ظ�Ԫ���ƶ�������ĩβ��������һ��ָ��ȥ�غ���ĩβ�ĵ�ַ last
    // unique ����������ɾ��Ԫ�أ�ֻ�ǽ��ظ�Ԫ���ƶ���ĩβ
    auto last = unique(vec.begin(), vec.end());

    // ɾ�� unique �������ƶ���ĩβ���ظ�Ԫ��(�� last �� vec.end() ֮���Ԫ��)
    vec.erase(last, vec.end());

    for (auto& num : vec)
    {
        cout << num << ' ';
    }

    return 0;
}
