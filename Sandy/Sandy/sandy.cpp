#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 2e5 + 9;
int a[N];

// ���ÿ���ָ�룬�������� [i,j] �� >= m �ĸ��������� k ���������価����С
// �õ����� [i,j] �󣬶��������˵㣬�� n - j + 1 ���Ҷε��ȡ
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // �Ż��������
    int n, m, k;
    cin >> n >> m >> k;

    // �õ����� a
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;    // ��ʾ�����������Ӵ�����

    // ʹ��˫ָ�� i �� j ����������
    // cnt ���ڼ�¼��ǰ�Ӵ��д��ڵ��� m ��Ԫ������
    for (int i = 1, j = 0, cnt = 0; i <= n; i++)
    {
        // �ƶ� j ָ�룬ֱ����ǰ�Ӵ��������� k ��Ԫ�ش��ڵ��� m
        while (i > j || (j + 1 <= n && cnt < k))
        {
            j++;
            cnt += (a[j] >= m);   // ��� a[j] >= m���� cnt ����
        }

        // ������������������ӵ�ǰ�Ӵ���ʼ������ĩβ�����п��ܵ��Ӵ�����
        if (cnt >= k)
        {
            ans += n - j + 1;
        }

        // �ƶ� i ָ�룬���� cnt ����Ӧ�ļ���
        cnt -= (a[i] >= m);
    }

    cout << ans << '\n';
    return 0;
}
