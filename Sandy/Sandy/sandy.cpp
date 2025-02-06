#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using ll = long long;

const ll p = 1e9 + 7;      // p Ϊģ��
const int N = 1e5 + 9;     // N Ϊ���������С
ll a[6][N], prefix[6][N];  // a ����洢��ͬ�η���ֵ��prefix ����洢ǰ׺��

// ���� k �Ƚ�С�����Դ���� 5 ������ֱ��ʾ��ͬ�Ĵη����� a3[] �е�Ԫ�ض������� a ��Ԫ�ص� 3 �η�
// �ٶ� 5 ������Ԥ�����ǰ׺�ͣ�����ÿ��ѯ������ǰ׺�͵����ʿ� O(1) ���

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);    // �����������
    int n, m;         // n �� m �ֱ�Ϊ���鳤�ȺͲ�ѯ����
    cin >> n >> m;

    int i = 0;
    int j = 0;

    // ����ԭʼ����
    for (i = 1; i <= n; ++i)
    {
        cin >> a[1][i];
    }

    // ����ÿ��Ԫ�ص� 2 �� 5 �Ĵη�����ȡģ
    for (i = 2; i <= 5; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            a[i][j] = a[i - 1][j] * a[1][j] % p;
        }
    }

    // ����ÿ���η���ǰ׺�ͣ���ȡģ
    for (i = 1; i <= 5; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            prefix[i][j] = (prefix[i][j - 1] + a[i][j]) % p;
        }

    }

    // ����ÿ����ѯ
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;   // �����ѯ�����ұ߽�ʹη�

        // �����ѯ����������˸������
        cout << (prefix[k][r] - prefix[k][l - 1] + p) % p << "\n";
    }
    return 0;
}
