#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 120;       // ��԰�����ߴ�
bool a[N][N], b[N][N];   // ��԰�Ĺ��״̬

int main()
{
    int n, m; cin >> n >> m;    // ��԰������������

    int t; cin >> t;            // �����ˮ�ܵ�����
    for (int i = 1; i <= t; i++)
    {
        // ����ÿ����ˮ�ܵ�����
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;      // ������ a �б�ǳ�ˮ�ܵ�λ��
    }

    int k; cin >> k;       // ��ȵķ�����

    // ѭ�� k �Σ�ģ��ÿ���ӵĹ�ȹ���
    while (k--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 1) // �����ǰλ���Ѿ������
                {
                    // ����ǰλ�õ����������ĸ�������Ϊ�ѹ��
                    b[i][j] = b[i - 1][j] = b[i + 1][j] = b[i][j - 1] = b[i][j + 1] = 1;
                }
            }
        }

        // �� b ����Ĺ��״̬���Ƶ� a ���飬�Ա���һ���ӵ���չ
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                a[i][j] = b[i][j];
            }
        }
    }

    // �������ձ���ȵķ�������
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // �����ǰλ�ñ���ȣ����Ӽ���
            if (a[i][j] == 1)
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
