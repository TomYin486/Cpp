#define _CRT_SECURE_NO_WARNINGS
#include<iostream>     // ������׼��������⣬����ʹ�� cin �� cout
#include <algorithm>   // ���� max_element �� min_element �����ͷ�ļ�
#include<iomanip>      // �������ڸ�ʽ������Ŀ⣬�� setprecision
using namespace std;   // ʹ�ñ�׼�����ռ䣬���� std:: ǰ׺

const int N = 1e4 + 9;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);  // �Ż�����������ӿ�ִ���ٶ�
    int n = 0;
    cin >> n;
    int i = 0;
    long long sum = 0;

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // max_element �� min_element ���ڲ��Ҹ�����Χ�ڵ����Ԫ�غ���СԪ�صĵ�ַ
    // a��ָ��������ʼλ�õĵ�ַ 
    // a + n��ָ���������λ�õĵ�ַ�����ҷ�Χ�� [a, a + n)
    cout << *max_element(a, a + n) << '\n';
    cout << *min_element(a, a + n) << '\n';

    // ��������
    //int mx = a[0];
    //int mi = a[0];

    // ѭ���������飬�ҳ����ֵ�����ֵ 
    //for (i = 1; i < n; i++)
    //{
    //    mx = max(mx, a[i]);    // �������ֵ
    //    mi = min(mi, a[i]);    // �������ֵ
    //}
    //cout << mx << '\n';
    //cout << mi << '\n';

    //for (i = 0; i < n; i++)
    //{
    //    sum += a[i];
    //}

    // ���ƽ���֣�������λС����ע��Ҫ�˸� 1.0
    cout << fixed << setprecision(2) << 1.0 * sum / n;

    return 0;
}
